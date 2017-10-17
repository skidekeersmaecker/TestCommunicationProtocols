#include"debug.h" 
#include"main.h" //state van robot
#include"comm.h" //opsturen debug bericht
#include"Arduino.h"

static int debugMask = 0;
void sendTestInfo();
void sendStartMessage();
void sendStopMessage();

void setDebugMask(int mask){
  debugMask = mask;
}

void debug(){
  static long startTime = millis();
  static int pause = 500;
  static long currentTime = 0;

  currentTime = millis();

  if(currentTime - startTime <= pause){
    return;
  }

  startTime = currentTime;

  if(debugMask){
    sendStartMessage();
  }

  if(debugMask & DEBUG_TEST){
    sendTestInfo();
  }

  if(debugMask){
    sendStopMessage();
  }
}

void sendDebugMessage(Debug_Message message){
  send(&message, sizeof message);
}

void sendStartMessage(){
  Debug_Message startMessage = {
    DEBUG_START
  };

  sendDebugMessage(startMessage);
}

void sendStopMessage(){
  Debug_Message stopMessage = {
    DEBUG_STOP
  };

  sendDebugMessage(stopMessage);
}

void sendTestInfo(){
  Debug_Message testMessage = { DEBUG_TEST };
  Debug_Body body;

  body.testInfo = { 999 };
  testMessage.body = body;

  sendDebugMessage(testMessage);
}
