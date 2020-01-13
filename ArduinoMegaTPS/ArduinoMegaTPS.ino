bool receivedBinData[6];

// ClockPin = 30 (receiver)

#define pinPorta_1 22

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
  // put your main code here, to run repeatedly:

}

void getBinData() {
  
}

int getRoomNum() {
  // if clock == 1 && 22 == Low
  
}
