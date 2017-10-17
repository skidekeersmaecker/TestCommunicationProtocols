#include"main.h" //interface om robot aan/uit/pauze te zetten
#include"comm.h" //kijken of er instructie zijn ontvangen.
#include"parser.h" //nodig om ontvangen instructies te ontleden
#include"debug.h"//nodig om debug informatie door te laten sturen
#include<stdint.h>

bool running;

void setup() {
  Serial.begin(9600);
  startComm();
}

void loop() {
  callHome(); //send debugging information.
  listenHome(); //see if we got instructions.
}

void listenHome() {
  uint8_t buffer[PAYLOAD_SIZE];

  if(read(buffer, PAYLOAD_SIZE)){
    Serial.print("Received: ");
    Serial.println((char*)buffer);
    parse(buffer);
  }
}

void callHome() {
  debug();
}

void pause(){
  running = false;
}

void run(){
  running = true;
}

void stop(){
  running = false;
}
