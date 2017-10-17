#ifndef DEBUG_H
#define DEBUG

#include<stdint.h>

#define DEBUG_TEST 0x01
#define DEBUG_START 0x02
#define DEBUG_STOP 0x04

void setDebugMask(int);
void debug();

typedef struct {
  int testInfo;
} Test_Info;

typedef union {
  Test_Info testInfo;
} Debug_Body;

typedef struct {
  uint8_t type;
  Debug_Body body;
} Debug_Message;

#endif
