#include <SPI.h>
#include <MFRC522.h>

// Card UID: 80 50 DF 87

#define testNumRoom 1

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

String content = "";

/*   Assegnamento UID TESSERE   */
String badges[40] = {
  "8050df87", "b574b2ab",
};

bool stanza_1 [40] = {
  true, false, true, false/*, true,
  false, true, false, true, false,
  true, false, true, false, true,
  false, true, false, true, false,
  true, false, true, false, true,
  false, true, false, true, false,
  true, false, true, false, true,
  false, true, false, true, false*/
};

bool stanza_2 [40] = {
  false, true, false, true/*, false,
  true, false, true, false, true,
  false, true, false, true, false,
  true, false, true, false, true,
  false, true, false, true, false,
  true, false, true, false, true,
  false, true, false, true, false,
  true, false, true, false, true*/
};

bool stanza_3 [40] = {
  true, false, true, false/*, true,
  false, true, false, true, false,
  true, false, true, false, true,
  false, true, false, true, false,
  true, false, true, false, true,
  false, true, false, true, false,
  true, false, true, false, true,
  false, true, false, true, false*/
};

bool stanza_4 [40] = {
  false, true, false, true/*, false,
  true, false, true, false, true,
  false, true, false, true, false,
  true, false, true, false, true,
  false, true, false, true, false,
  true, false, true, false, true,
  false, true, false, true, false,
  true, false, true, false, true*/
};

bool stanza_5 [40] = {
  true, false, true, false/*, true,
  false, true, false, true, false,
  true, false, true, false, true,
  false, true, false, true, false,
  true, false, true, false, true,
  false, true, false, true, false,
  true, false, true, false, true,
  false, true, false, true, false*/
};

bool stanza_6 [40] = {
  false, true, false, true/*, false,
  true, false, true, false, true,
  false, true, false, true, false,
  true, false, true, false, true,
  false, true, false, true, false,
  true, false, true, false, true,
  false, true, false, true, false,
  true, false, true, false, true*/
};

void setup() {
  Serial.begin(9600);   // Initialize serial communications with the PC
  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  delay(4);       // Optional delay. Some board do need more time after init to be ready, see Readme
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details

  pinMode(6, OUTPUT);
  digitalWrite(6, HIGH);
}
 
void loop()
{
  /* Temporary loop counter */
  byte i;
  int sector = 0;
  unsigned long uid;
  byte UID [10];
  int j = 0;
   
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  int decOfHex [4];
  
  Serial.print("UID Tag: ");

  for(int j = 0; j < mfrc522.uid.size; j++) {
    byte b = mfrc522.uid.uidByte[j];

    if(b < 0x10) {
      content += " 0";
    } else {
      content += " ";
    }
    content += (b);

    decOfHex[j] = b;
    
    //Serial.print(b < 0x10 ? " 0" : " ");
    //Serial.print(b, HEX);
  }

  //Serial.println();
  //Serial.println(content);

  content = "";

  for(int k = 0; k < 4; k++) {
    content += String(decOfHex[k], HEX);
  }

  Serial.println();
  Serial.println(content);

  int badgeNum = checkBadges();

  if(stanza_1[badgeNum] == true) {
    Serial.println("Accesso alla STANZA RIUSCITO");
    digitalWrite(6, LOW);
    delay(1000);
    digitalWrite(6, HIGH);
  } else {
    Serial.println("Accesso alla STANZA NEGATO");
  }
  
  delay(1000);  
}

int checkBadges() {
  int i = 0, badgenum;
  
  for(i = 0; i < 41; i++) {
    if(badges[i] == content) {
      badgenum = i;
      break;
    }
  }

  //Serial.println(badgenum);
  return badgenum;
}
