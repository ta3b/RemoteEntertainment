/*
 * ServerUnixCommon.cpp
 *
 *  Created on: Sep 24, 2012
 *      Author: cmihail (Mihail Costea)
 */

#include "Logger.h"
#include "platform/EventListener.h"

#include <cstdlib>

#include <sys/event.h>

int kqueueDescriptor;
struct kevent * changeList;
struct kevent * eventList;

int currentNumOfEvents = 0;
int numOfTriggeredEvents = -1;

// TODO(cmihail): maybe a method for closing

EventListener::EventListener(int maxNumOfEvents) : maxNumOfEvents(maxNumOfEvents) {
  // Create event notifier.
  kqueueDescriptor = kqueue();
  if (kqueueDescriptor == -1) {
    Logger::print(__FILE__, __LINE__, Logger::ERROR, "kqueue error");
  }
  changeList = new struct kevent[maxNumOfEvents]; // TODO(cmihail): maybe realloc when needed
  eventList = new struct kevent[maxNumOfEvents];
}

EventListener::~EventListener() {
  delete changeList;
  delete eventList;
}

bool EventListener::addEvent(socket_descriptor_t descriptor) {
  if (descriptor < 0) {
    Logger::print(__FILE__, __LINE__, Logger::ERROR, "Invalid descriptor");
    return false;
  }

  // Check if maximum number of events was reached.
  if (currentNumOfEvents == maxNumOfEvents) {
    return false;
  }

  EV_SET(&changeList[currentNumOfEvents], descriptor,
      EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, 0);
  currentNumOfEvents++;
  return true;
}

bool EventListener::deleteEvent(socket_descriptor_t descriptor) {
  if (descriptor < 0) {
    Logger::print(__FILE__, __LINE__, Logger::ERROR, "Invalid descriptor");
    return false;
  }

  // Search for the correspondent event for the given descriptor.
  int i = 0;
  for (; i < currentNumOfEvents; i++) {
    if (changeList[i].ident == (unsigned int) descriptor) {
      // Delete event from kqueue.
      EV_SET(&changeList[i], descriptor, EVFILT_READ, EV_DELETE, 0, 0, 0);
      struct kevent tempEventList;
      kevent(kqueueDescriptor, &changeList[i], 1, &tempEventList, 1, NULL);
      break;
    }
  }

  // Check if the event was found.
  if (i == currentNumOfEvents) {
    return false;
  }

  // Move all remaining events to the left.
  for (; i < currentNumOfEvents - 1; i++) {
    changeList[i] = changeList[i + 1];
  }
  currentNumOfEvents--;

  return true;
}

int EventListener::checkEvents() {
  numOfTriggeredEvents = kevent(kqueueDescriptor, changeList, currentNumOfEvents,
      eventList, currentNumOfEvents, NULL);
  return numOfTriggeredEvents;
}

socket_descriptor_t EventListener::getDescriptor(int eventId) {
  if (numOfTriggeredEvents <= 0  || eventId >= numOfTriggeredEvents ||
      eventList[eventId].filter != EVFILT_READ) {
    return -1;
  }
  return eventList[eventId].ident;
}
