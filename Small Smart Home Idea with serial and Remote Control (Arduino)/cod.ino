#include <avr/sleep.h>
#define interruptPin 2

char incoming_byte=0;
volatile unsigned int count=0;

void wakeUp()
{
  sleep_disable();
  detachInterrupt(0);
  delay(1000);  
}
void Going_To_Sleep()
  {
    sleep_enable();
    attachInterrupt(0 , wakeUp , LOW);
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    delay(1000);
    sleep_cpu();
  }
void setup() {
  // put your setup code here, to run once:

pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(13, OUTPUT);

pinMode(12, OUTPUT); // IR PIN

digitalWrite(3 ,LOW);
digitalWrite(4 ,LOW);
digitalWrite(5 ,LOW);
digitalWrite(6 ,LOW);
digitalWrite(7 ,LOW);
digitalWrite(8 ,LOW);
digitalWrite(9 ,LOW);
digitalWrite(10 ,LOW);
digitalWrite(11 ,LOW);
digitalWrite(13,LOW);



Serial.begin(9600);


pinMode(interruptPin , INPUT_PULLUP);
/* Timer2 Initiat */
TIMSK2 = (TIMSK2 & B11111110) | 0x01;
TCCR2B = (TCCR2B & B11111000) | 0x07;
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available() > 0)
  {
    incoming_byte = Serial.read();
    delay(10);
  }
 
  switch(incoming_byte){
  case 'a' :     // your hand is close to the sensor
      count = 0;
      digitalWrite(3 , !digitalRead(3));
      delay(10);
      break;
  case 'b' :
     // your hand is a few inches from the sensor
      count = 0;
      digitalWrite(4 , !digitalRead(4));
      delay(10);
      break;
   case 'c' :   // your hand is nowhere near the sensor
      count = 0;
      digitalWrite(5 , !digitalRead(5));
      delay(10);
      break;
   case 'd' :  // your hand is on the sensor
      count = 0;
      digitalWrite(6 , !digitalRead(6));
      delay(10);
      break;
   case 'e':    
      count = 0;
      digitalWrite(7 , !digitalRead(7));
      delay(10);
      break;
   case 'f': 
      count = 0;
      digitalWrite(8 , !digitalRead(8));
      delay(10);
      break;
   case 'g' : 
      count = 0;
      digitalWrite(9 , !digitalRead(9));
      delay(10);
      break;
   case 'h' : 
      count = 0; 
      digitalWrite(10 , !digitalRead(10));
      delay(10);
      break;
   case 'i' :
      count = 0;
      digitalWrite(11 , !digitalRead(11));
      delay(10);
      break;
   case 'j' :     // your hand is close to the sensor
      count = 0;
      digitalWrite(13 , !digitalRead(13));
      delay(10);
      break;
   case 'z' :  
      delay(1000);  
      digitalWrite(3 ,LOW);
      digitalWrite(4 ,LOW);
      digitalWrite(5 ,LOW);
      digitalWrite(6 ,LOW);
      digitalWrite(7 ,LOW);
      digitalWrite(8 ,LOW);
      digitalWrite(9 ,LOW);
      digitalWrite(10 ,LOW);
      digitalWrite(11 ,LOW);
      Going_To_Sleep();
      break;
  }
  if(count > 1000){Going_To_Sleep;}
  incoming_byte=0;
  delay(10); 
}
ISR(TIMER2_OVF_vect)
{
  count++;  
}
