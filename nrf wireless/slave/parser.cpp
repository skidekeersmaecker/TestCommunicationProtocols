#include"parser.h"
#include"main.h"
#include"stdlib.h"
#include"debug.h"
#include"Arduino.h"

void parseDebugCommand(uint8_t*);

void parse(uint8_t *buffer){
  switch(*buffer){

  case 'P':
    pause();
    break;
    
  case 'S':
    stop();
    break;

  case 'R':
    run();
    break;

  case 'D':
    parseDebugCommand(buffer);
    break;
  }
}

void parseDebugCommand(uint8_t *buffer){
  int debugMask = 0;

  while(*++buffer){
    switch(*buffer){
    case 'S':
      debugMask |= DEBUG_TEST;
      break;
    }
  }

  setDebugMask(debugMask);
}

