#include"comm.h"
#include <RF24_config.h>
#include <RF24.h>
#include <nRF24L01.h>
#include"pin.h"

RF24 rf(CE_PIN, CSN_PIN);

void startComm(){
  uint8_t addresses[][6] = { "RNode", "CNode" };
  
  rf.begin();
  rf.openReadingPipe(1, addresses[0]);
  rf.openWritingPipe(addresses[1]);
  rf.startListening();
}

bool send(const void *msg, uint8_t size){
  rf.stopListening();
  bool success = rf.write(msg, size);
  rf.startListening();

  return success;
}

bool read(void *buffer, uint8_t size) {
	if (rf.available()) {
	  rf.read(buffer, size);
	  return true;
	}

	return false;
}

