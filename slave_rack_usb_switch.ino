#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  // put your setup code here, to run once:
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);

pinMode(A1,OUTPUT);
digitalWrite(A1,HIGH);
pinMode(13,OUTPUT);
digitalWrite(13,HIGH);
Serial.begin(9600);
mySerial.begin(9600);
  Serial.println("Hello, world?");
}
int k=1;
void loop() {
  // put your main code here, to run repeatedly:
if(mySerial.available())
{   char x=mySerial.read();
  Serial.println(x);
   digitalWrite(13,k);
   k=1-k;
    if(x=='i')
   {
    delay(100);
    digitalWrite(A1,LOW);
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    Serial.println("9");
   }
    else if(x=='j')
   {
    delay(100);
    digitalWrite(A1,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    Serial.println("10");
   }
    else if(x=='k')
   {
    delay(100);
    digitalWrite(A1,LOW);
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
    Serial.println("11");
   }
    else if(x=='l')
   {
    delay(100);
    digitalWrite(A1,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
    Serial.println("12");
   }
    else if(x=='m')
   {
    delay(100);
    digitalWrite(A1,LOW);
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
    digitalWrite(4,HIGH);
    
    Serial.println("13");
   }
    else if(x=='n')
   {
    delay(100);
    digitalWrite(A1,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(4,HIGH);
 
    Serial.println("14");
   }
    else if(x=='o')
   {
    delay(100);
    digitalWrite(A1,LOW);
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(4,HIGH);
   
    Serial.println("15");
   }
    else if(x=='p')
   {
    delay(100);
    digitalWrite(A1,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(4,HIGH);
    
    Serial.println("16");
    
   }
    else if(x<'i' || x>'p')
   {
    digitalWrite(A1,HIGH);

    
    Serial.println("first MOUSe Switch");
    
   }
   
}
}
