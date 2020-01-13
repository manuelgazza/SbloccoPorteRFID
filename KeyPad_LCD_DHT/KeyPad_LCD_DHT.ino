#include <DHT.h>

#include <Wire.h>
#include <Keypad.h>
#include <LiquidCrystal.h>

using namespace std;

DHT dht;
Serial.begin(9600);
dht.begin();

//REGISTER SELECT = 12
//ENABLE = 11
//D2 = 25
//D3 = 24
//D2 = 23
//D1 = 22

/*
 * 22 = pin4
 * 23 = pin6
 * 38 = DHT
 */

const byte righe = 4, colonne = 4;
byte PULSrighe [righe] = {9, 8, 7, 6};
byte PULScolonne [colonne] = {5, 4, 3, 2};

const byte pulsanti [righe] [colonne] = { {'1', '2', '3', 'A'},
                                          {'4', '5', '6', 'B'},
                                          {'7', '8', '9', 'C'},
                                          {'*', '0', '#', 'D'} };

Keypad tastiera = Keypad(makeKeymap(pulsanti), PULSrighe, PULScolonne, righe, colonne);

const int RS = 22, EN = 23, d4 = 30, d5 = 31, d6 = 32, d7 = 33;
LiquidCrystal lcd(RS, EN, d4, d5, d6, d7);

    
void setup() {
  

  // 1, 2, 3, 4: Colonne
  // 5, 6, 7, 8: Righe

  //PIN Righe: 2, 3, 4, 5.
  //PIN Colonne: 6, 7, 8, 9.

  lcd.begin(5, 2);
  lcd.setCursor(0, 0);
  lcd.print("INSERISCI UN NUMERO DI 4 CIFRE");
    
}

void loop() {

  float h;
  float t;

  t = dht.readTemperature();
  h = dht.readHumidity();
  
  //lcd.clear();
  //byte key = tastiera.getKey();
  //lcd.print("TEST");
  
  int cont_pos_lcd = 0;

  for(; cont_pos_lcd < 16; cont_pos_lcd++) {
    lcd.scrollDisplayLeft();
    delay(500);
  }
  

  if(key != 0) {
    lcd.clear();
    //lcd.print(char(key));
    Serial.println(char(key));
    lcd.print("Temperatura: ");
    lcd.print(t);

    lcd.setCursor(0, 1);
    lcd.print("Umidita': ");
    lcd.print(h);
 }

 //delay(2500);

  
  
}
