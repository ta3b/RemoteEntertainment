/*
 * Main.cpp
 *
 *  Created on: Sep 23, 2012
 *      Author: cmihail
 */

#include "../unix/Process.h"
#include "Server.h"

#include <cassert>

#include <iostream>
#include <string>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>

using namespace std;

Process * createMediaPlayer(string port) {
  // TODO(cmihail): only for dev
  string program = "java";
  string * programArgs = new string[6];
  programArgs[0] = "-cp";
  programArgs[1] = ".:../MediaPlayer/lib/vlcj-2.1.0.jar:" +
      string(":../proto/protobuf-java-2.4.1.jar:../proto/common-client.jar");
  programArgs[2] = "-Djna.library.path=/Applications/VLC.app/Contents/MacOS/lib";
  programArgs[3] = "player/Main";
  programArgs[4] = "/Users/cmihail/Downloads/Lockout.UNRATED.720p.BluRay.x264-BLOW [PublicHD]" +
      string("/Lockout.UNRATED.720p.BluRay.x264-BLOW.PublicHD.mkv");
  programArgs[5] = port;

  return new Process(program, 6, programArgs);
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    cerr << "Usage: ./Main <port>\n";
    return 1;
  }

  Server * server = new Server(atoi(argv[1]));
  createMediaPlayer(argv[1]);
  server->run();
}