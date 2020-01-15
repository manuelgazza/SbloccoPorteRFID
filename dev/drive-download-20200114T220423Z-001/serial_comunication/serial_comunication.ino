#define clock_pin 4
#define data_pin 3
#define send_ 5

void setup() {
  pinMode(data_pin,OUTPUT);
  pinMode(clock_pin,OUTPUT);
  pinMode(send_,INPUT);

}
bool dato[6]={1,1,1,0,1,1};
int I;
bool start = 0;


void loop() {
  start = digitalRead(send_);
  if(start == 1)
  {
   
    digitalWrite(clock_pin,LOW);
    
    for(I=0;I<6;I++){
      digitalWrite(clock_pin,HIGH);
      digitalWrite(data_pin,dato[I]);
      delay(100);
      
      digitalWrite(data_pin,LOW);
      digitalWrite(clock_pin,LOW);
      delay(100);
      
    }
    start=0;
  }

}
