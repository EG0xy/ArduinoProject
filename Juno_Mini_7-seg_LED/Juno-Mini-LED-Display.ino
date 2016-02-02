/*
Juno-Mini-7-seg LED-2016
D10-mosfet
D11-buttonA
D12-buttonB
D13-buttonC

D2-D9 anodes of 7-seg led
A0-A3 cathodes of 7-seg 4 digit

Pins out:
5v;D0 Rx; D1 Tx; A4-A7;  GND

The following code with print out a 8888 number to the LED display.
*/


#include "ClickButton.h"
ClickButton ba(11, LOW, CLICKBTN_PULLUP);
ClickButton bb(12, LOW, CLICKBTN_PULLUP);
ClickButton bc(13, LOW, CLICKBTN_PULLUP);

byte counter=0;
unsigned long cta=0;
unsigned long ctb=0;

unsigned long t3=0; // internal timing
unsigned long t4=0;

byte dg1=B00110000;
byte dg2=B01011011;
byte dg3=B01111001;
byte dg4=B01110100;

int left; //4 digits display
int right;

int secX=0;
int minX=0;
int hrX=0;

   const byte digit[] =
    {
    B00111111, // 0
    B00110000, // 1
    B01011011, // 2
    B01111001, // 3
    B01110100, // 4
    B01101101, // 5
    B01101111, // 6
    B00111000, // 7
    B01111111, // 8
    B01111101, // 9
    B00000000, // BLANK
    B10000000  }; //dot


//------------------------------------------

void setup() {
 
for (byte x=2; x<9; x++){
pinMode (x, OUTPUT);
}  

pinMode (A0, OUTPUT);
pinMode (A1, OUTPUT);
pinMode (A2, OUTPUT);
pinMode (A3, OUTPUT);

  ba.multiclickTime = 50;
  bb.multiclickTime = 50; 
  bc.multiclickTime = 50; 

  ba.debounceTime = 50;
  bb.debounceTime = 50; 
  bc.debounceTime = 50;
  
}

void loop() {
ba.Update();
bb.Update(); 
bc.Update();  


dg1=digit[left/10];
dg2=digit[left%10];
dg3=digit[right/10];
dg4=digit[right%10];

  if(secX==60){minX++; secX=0;}
  if(minX==60){hrX++; minX=0;}
  
  
  left=43;
  right=21;
 //=================second timer==

 t3=millis(); 
  if (t3-t4>=1000){
    secX++;
    
  t4=t3;  
  }


// LED display driver - Multiplexing + V Ma ------------------------------------
  
cta=millis();
if(cta-ctb>=1){
  
  
counter++;
if(counter==5)counter=0;

if(counter==0){
  digitalWrite(A3, HIGH);  
  for(byte x=2; x<9; x++){
  digitalWrite(x, LOW);
  } 
  
  for(byte dr=0; dr<8; dr++){
  digitalWrite(dr+2, bitRead(dg4,dr));  
  }
  digitalWrite(A0, LOW);  
}

if(counter==1){
 
  digitalWrite(A0, HIGH);   
  for(byte x=2; x<9; x++){
  digitalWrite(x, LOW);
  } 
  
  for(byte dr=0; dr<8; dr++){
  digitalWrite(dr+2, bitRead(dg3,dr));
  }  
  digitalWrite(A1, LOW);   
}

if(counter==2){

  digitalWrite(A1, HIGH); 
  for(byte x=2; x<9; x++){
  digitalWrite(x, LOW);
  } 

  for(byte dr=0; dr<8; dr++){
  digitalWrite(dr+2, bitRead(dg2,dr));
  }  
  digitalWrite(A2, LOW);  
}

if(counter==3){
  
  digitalWrite(A2, HIGH); 
  for(byte x=2; x<9; x++){
  digitalWrite(x, LOW);
  } 

  for(byte dr=0; dr<8; dr++){
  digitalWrite(dr+2, bitRead(dg1,dr));
  }  
  digitalWrite(A3, LOW);   
}

ctb=cta;
}

}
