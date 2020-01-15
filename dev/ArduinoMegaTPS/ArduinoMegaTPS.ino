bool receivedBinData[6];

// ClockPin = 30 (receiver)

#define pinPorta_1 22
#define pinPorta_2 23
#define pinPorta_3 24
#define pinPorta_4 25
#define pinPorta_5 26
#define pinPorta_6 27

/*
 * PORTE:
 * Porta_1 = 22
 * Porta_2 = 23
 * Porta_3 = 24
 * Porta_4 = 25
 * Porta_5 = 26
 * Porta_6 = 27
 */

void setup() {
  pinMode(22, INPUT);
  pinMode(23, INPUT);
  pinMode(24, INPUT);
  pinMode(25, INPUT);
  pinMode(26, INPUT);
  pinMode(27, INPUT);

}

void loop() {
  int room = getRoomNum();

  
}

void getBinData() {
  
}

int getRoomNum() {
  bool signalOn;
  int roomNum;
  
  while(signalOn == false) {
    if(pinPorta_1 == HIGH) {
      roomNum = 1;
      signalOn = true;
    }

    if(pinPorta_2 == HIGH) {
      roomNum = 2;
      signalOn = true;
    }

    if(pinPorta_3 == HIGH) {
      roomNum = 3;
      signalOn = true;
    }

    if(pinPorta_4 == HIGH) {
      roomNum = 4;
      signalOn = true;
    }

    if(pinPorta_5 == HIGH) {
      roomNum = 5;
      signalOn = true;
    }

    if(pinPorta_6 == HIGH) {
      roomNum = 6;
      signalOn = true;
    }
  }

  return roomNum;
}
