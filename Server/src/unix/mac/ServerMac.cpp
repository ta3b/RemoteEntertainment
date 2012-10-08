/*
 * ServerMac.cpp
 *
 *  Created on: Sep 24, 2012
 *      Author: cmihail
 */

#include "../../common/Server.h" // TODO(cmihail): maybe to this using -I at compilation
#include "../../common/Client.h"
#include "../../common/proto/player.pb.h"
#include "../../common/proto/PlayerCommand.h"
#include "../ServerUnixCommon.h"

#include <google/protobuf/io/zero_copy_stream_impl.h>

#include <cassert>
#include <cstdlib>
#include <iostream>  // TODO(cmihail): use logger instead
#include <map>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/event.h>
#include <sys/socket.h>

#define MAX_NUM_OF_CLIENTS 5

using namespace std;

unsigned int maxNumOfConnections;
unsigned int currectNumOfChangeEvents = 0;
int kqueueFileDescriptor;
struct kevent * changeList;
struct kevent * eventList;

socket_descriptor_t listenSocket;
map<socket_descriptor_t, Client> clientsMap;

Server::Server(int serverPort) {
  GOOGLE_PROTOBUF_VERIFY_VERSION; // TODO(cmihail): make this common

  // Number of clients for read events on sockets + a server socket listener.
  maxNumOfConnections = MAX_NUM_OF_CLIENTS + 1;

  // Init server.
  listenSocket = serverUnixCommon_init(serverPort, MAX_NUM_OF_CLIENTS);

  // Create event notifier.
  kqueueFileDescriptor = kqueue();
  assert(kqueueFileDescriptor != -1);
  changeList = new struct kevent[maxNumOfConnections]; // TODO(cmihail): maybe realloc when needed
  eventList = new struct kevent[maxNumOfConnections];

  // Create event for the server socket used for listening incoming connections.
  EV_SET(&changeList[currectNumOfChangeEvents], listenSocket,
      EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, 0);
  currectNumOfChangeEvents = 1;
}

static void registerNewClient(int listenSocket) {
  if (currectNumOfChangeEvents == maxNumOfConnections) {
    cout << "Maxmum number of clients received" << endl;
    return;
  }

  // Add read event for the newly created socket.
  int clientSocket = serverUnixCommon_newConnection(listenSocket);
  EV_SET(&changeList[currectNumOfChangeEvents], clientSocket,
      EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, 0);
  currectNumOfChangeEvents++;

  clientsMap.insert(pair<socket_descriptor_t, Client>(clientSocket, Client(clientSocket)));
}

// TODO(cmihail): only for dev, it should be send to all other clients
static void printCommand(PlayerCommand * playerCommand) {
  if (playerCommand->getType() == proto::Command::PAUSE) {
    cout << "[SERVER] Pause\n";
  } else if (playerCommand->getType() == proto::Command::PLAY) {
    cout << "[SERVER] Play\n";
  } else  if (playerCommand->getType() == proto::Command::REWIND) {
    cout << "[SERVER] Rewind\n";
  } else  if (playerCommand->getType() == proto::Command::FAST_FORWARD) {
    cout << "[SERVER] Fast Forward\n";
  } else {
    cout << "[SERVER] Other command\n";
  }
}

static void endConnection(socket_descriptor_t clientSocket) {
  unsigned int i = 0;
  for (; i < currectNumOfChangeEvents; i++) {
    if (changeList[i].ident == clientSocket) { // TODO(cmihail): maybe memorize this into map
      EV_SET(&changeList[i], clientSocket, EVFILT_READ, EV_DELETE, 0, 0, 0);
      clientsMap.erase(clientSocket);
      break;
    }
  }
  for (; i < currectNumOfChangeEvents - 1; i++) {
    changeList[i] = changeList[i + 1]; // TODO(cmihail): not sure if it works, but it should
  }
  currectNumOfChangeEvents--;

  serverUnixCommon_endConnection(clientSocket);
}

static void receiveCommand(socket_descriptor_t clientSocket) {
  // Receive command from server.
  int BUFFER_SIZE = 2000; // TODO(cmihail): change 2000
  char * dataBuffer = new char[BUFFER_SIZE];
  memset(dataBuffer, 0, BUFFER_SIZE);
  int n = recv(clientSocket, dataBuffer, BUFFER_SIZE, 0);
  assert(n >= 0);

  // Check if connection with client has ended.
  if (n == 0) {
    cout << "[Server] Connection ended\n";
    endConnection(fileDescriptor);
    return;
  }

  PlayerCommand * playerCommand = new PlayerCommand(string(dataBuffer));
  printCommand(playerCommand);

  // Send command to all other clients.
  map<socket_descriptor_t, Client>::iterator it = clientsMap.begin();
  map<socket_descriptor_t, Client>::iterator itEnd = clientsMap.end();
  string codedBuffer = playerCommand->toCodedBuffer();
  for (; it != itEnd; it++) {
    if (it->first != clientSocket) {
      // TODO(cmihail): check value returned by <send>
      assert(send(it->first, codedBuffer.c_str(), codedBuffer.length(), 0) >= 0);
    }
  }

  delete playerCommand;
}

void Server::run() {
  while(true) {
    // Retrieve event list.
    int n = kevent(kqueueFileDescriptor, changeList, currectNumOfChangeEvents,
        eventList, currectNumOfChangeEvents, NULL);
    assert(n != -1);
    if (n == 0) {
      cout << "No events\n"; // TODO(cmihail): log and another behavior
      _exit(EXIT_FAILURE);
    }

    // Check the event type and execute correspondent action.
    for (unsigned int i = 0; i < currectNumOfChangeEvents; i++) {
      // Receive new connection.
      if (eventList[i].ident == listenSocket && eventList[i].filter == EVFILT_READ) {
        cout << "[SERVER] New Client\n";
        registerNewClient(listenSocket);
        continue;
      }

      // Receive commands from clients.
      map<socket_descriptor_t, Client>::iterator it = clientsMap.find(eventList[i].ident);
      if (it != clientsMap.end() && eventList[i].filter == EVFILT_READ) {
        cout << "[SERVER] Command received\n";
        receiveCommand(it->first);
        continue;
      }
    }
  }
}

Server::~Server() {
  delete changeList;
  delete eventList;
}
