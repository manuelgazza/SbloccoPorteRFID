#define clock_pin 8
#define data_pin 7
#define data_out 6


void setup() {
  pinMode(clock_pin,INPUT);
  pinMode(data_pin,INPUT);
  pinMode(data_out,OUTPUT);
  Serial.begin(9600);

}
bool dato[6];
bool start[2];
int clock_up;
int bit_;
int I=0,J;

void loop() {

 clock_up = digitalRead(clock_pin);
  /*
  if(clock_up == 1){
    start[1]=digitalRead(clock_pin);
    delay(100);
    start[2]=digitalRead(clock_pin);
  }
  
  if(start[1]==1 && start[2]==1){*/
    
    if(clock_up == 1){
      delay (10);
      
      for( ;I<6; ){
        bit_=digitalRead(data_pin);
        // digitalWrite(data_out,bit_);
        dato[I] = bit_;
  
        clock_up = digitalRead(clock_pin);
        while(clock_up == 1){
          clock_up = digitalRead(clock_pin);
        }
        
        I++;
       break;
      } 
     }
    // start[1]=0;
    // start[2]=0;
    
   //}
  if(I>=6){
    for( J=0;J<6;J++){
      Serial.print(dato[J]);
    }
     Serial.println();
  }

}
