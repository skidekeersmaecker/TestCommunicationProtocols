#include"comm.h"
#include"debug.h"
#include<string.h>
#include<stdlib.h>

void setup() {
  Serial.begin(9600);
  startComm();
}

void loop() {
  //checkSerial(); //see if we received data on the serial connection
  checkRF(); //see if we received data on the wireless connection
}

/*void checkSerial() {
  if (Serial.available()) {
    handleInput();
  }
}*/

void checkRF() {
  //Debug_Message message;
  String message;
  if (read(&message, sizeof message)) {
    Serial.println(message);
    /*switch (message.type) {
      case DEBUG_START:
        Serial.print("");
        break;
      
      case DEBUG_STOP:
        Serial.println("");
        break;

      case DEBUG_SENSORS:
        printSensorsInfo(message.body.sensorsInfo);
        break;
    }*/
  }
}

/*void printSensorsInfo(Sensors_Info info) {
  Serial.print("Sensormask: ");
  Serial.print(info.sensorMask);
  Serial.print(" (");

  if (info.sensorMask & POMP1) {
    Serial.print(" PO");
  }

  if (info.sensorMask & POMP2) {
    Serial.print(" PB");
  }

  Serial.println(" )");
}
*/

bool containsChar(char *string, char character) {
  if (!(*string)) { //if string is empty
    return false;
  }

  else {
    return (*string == character || containsChar(string + 1, character));
  }
}

/*void handleInput() {
  static char buffer[PAYLOAD_SIZE];
  static int index;

  while (Serial.available()) {
    char symbol = Serial.read();
    if (symbol == '\n') {
      buffer[index] = '\0';

      if (isValidInstruction(buffer)) {
        if (!send(buffer, sizeof buffer)) {
          Serial.println("COMMUNICATION ERROR: could not send instruction.");
        }
        else {
          Serial.println("Instruction send.");
        }
      }

      else {
        Serial.println("SYNTAX ERROR: not a valid instruction.");
      }

      index = 0;
    }

    else if (index < PAYLOAD_SIZE - 1) { //- 1 want laatste plaats in buffer is voor newline
      if (symbol != ' ' && symbol != '\t') {
        buffer[index++] = symbol;
      }
    }

    else {
      Serial.println("SYNTAX ERROR: instruction too long.");
      index = 0;
    }
  }
}

bool isValidInstruction(char *instruction) {
  if (containsChar("RPS", *instruction) ||
      isValidDebugInstruction(instruction) ||
      isValidMotorInstruction(instruction)) {
    return true;
  }
  else {
    return false;
  }
}

bool isValidDebugInstruction(char *instruction) {
  if (*instruction == 'D') {
    while (*++instruction) {
      if (!containsChar("STAM", *instruction)) {
        return false;
      }
    }

    return true;
  }

  else {
    return false;
  }
}

bool isValidMotorInstruction(char *instruction) {
  if (*instruction == 'M' && *(instruction + 1) - '0' >= 0 && *(instruction + 1) - '0' <= 2) {
    instruction += 2;

    if (containsChar("SP", *instruction)) {
      int value = atoi(instruction + 1);

      if (*instruction == 'S') {
        return value <= 255 && value >= -255;
      }

      else if (*instruction == 'P') {
        return value <= 100 && value >= 0;
      }
    }

    else {
      return false;
    }
  }

  else {
    return false;
  }
}*/
