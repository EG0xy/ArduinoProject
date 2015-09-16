// 595 active HIGH;  D4-D7 active LOW
//Final vision

#include "ClickButton.h"
#include <DS1302.h>
DS1302 rtc(1, 2, 3);
Time t;

int latchPin = 8; 
int clockPin = 9; 
int dataPin = 10; 

ClickButton ba(A1, LOW, CLICKBTN_PULLUP);
ClickButton bb(A2, LOW, CLICKBTN_PULLUP);
ClickButton bc(A3, LOW, CLICKBTN_PULLUP);

int secX=0;
int minX=0;
int hrX=0;
int hrY=0;
int halfday=0; //am/pm
int dayX=0;
int setime=0;

byte counter=1; // counter for multiplexing switch

unsigned long t1=0; // timer for multiplexing switch
unsigned long t2=0;

unsigned long t3=0; // internal timing
unsigned long t4=0;

unsigned long t5=0; // blinking timing
unsigned long t6=0;

unsigned long t7=0; // Second mapping blinking timing
unsigned long t8=0;

byte LED =0; //8 led control byte
byte d1=0;   // bytes for multiplexing or switching 4 digits LED display
byte d2=0;
byte d3=0;
byte d4=0;

byte LEDx =0; //For final shift-out
byte dx1=0;  
byte dx2=0;
byte dx3=0;
byte dx4=0;

int left; //4 digits display
int right;

int mode=0; //different display mode


int interval=1100; //(1000ms-66ms: second mapping to 4 dot led with different blinking speed: 1-15;16-30;31-45;46-60)
boolean secBlink=0;
//----------------------------------------------------------------------

   const byte ledMap[] =  //8 led mapping
    {
    B00000000,      
    B00000001, // 1
    B00000011, // 2
    B00000111, // 3
    B00001111, // 4
    B00011111, // 5
    B00111111, // 6
    B01111111, // 7
    B11111111  }; //8 
    
    
   const byte digit[] = //digit mapping
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
//==================================================================================

void setup() {
 
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  for(int x=4;x<=7;x++){
   pinMode(x, OUTPUT);  //4 digits output - Active Low
  }  
   
  ba.multiclickTime = 50;
  bb.multiclickTime = 50; 
  bc.multiclickTime = 50;  
  
  ba.debounceTime = 50;
  bb.debounceTime = 50; 
  bc.debounceTime = 50;  
 
rtc.halt(false);
t = rtc.getTime();
 dayX=t.dow;
 hrY=t.hour;
 minX=t.min;
 secX=t.sec; 

// ds1302 chip hr range: 0-23; min range:0-59; sec range 0-59;
// convert 24 hr to 12 with am. pm.
  if(hrY<12 && hrY>0){hrX=hrY; halfday=1;}  
  if(hrY==0 ){hrX=12; halfday=1;} 
  
  if(hrY>=13){hrX=hrY-12; halfday=2;}   
  if(hrY==12){hrX=12; halfday=2;}   
 
 
}

void loop() {
  
ba.Update();
bb.Update(); 
bc.Update();  

//=====================byte mapping==================================


d1=digit[left/10];
d2=digit[left%10];
d3=digit[right/10];
d4=digit[right%10];

//timing increasment for 4 dots second display.
for(int x=0; x<15;x++){
if(x==(secX%15)){interval=700-(47*x);}
}

//am pm led switch. 
if(halfday==1){
LED=ledMap[dayX]|B10000000;
}
if(halfday==2){
LED=ledMap[dayX]&B01111111;;
}


//================= update clock every 5 minutes
  if(minX%5==0 && secX==10 && mode==0){
    
    rtc.halt(false);
    t = rtc.getTime();
     dayX=t.dow;
     hrY=t.hour;
     minX=t.min;
     secX=t.sec;
     
     
    if(hrY<12 && hrY>0){hrX=hrY; halfday=1;}  
    if(hrY==0 ){hrX=12; halfday=1;} 
    
    if(hrY>=13){hrX=hrY-12; halfday=2;}   
    if(hrY==12){hrX=12; halfday=2;}  
}    



  if(secX==60){minX++; secX=0;}
  if(minX==60){hrX++; minX=0;}
  if(minX==-1){minX=59;}  

  if(hrX==0){hrX=12;halfday--;}  
  if(hrX==13){hrX=1;halfday++;}
  
  if(halfday==3){halfday=1;dayX++;}
  if(halfday==0){halfday=2;dayX--;}
  
  if(dayX==8){dayX=1;}
  if(dayX==0){dayX=7;}

//====================Modes==================================

if(mode==0){
  left=hrX;
  right=minX;
  
  LEDx=LED;
  
  if(secX<16 && secX>0){
  if(secBlink==1){
  dx1=d1|B10000000;
  dx2=d2; 
  dx3=d3;     
  dx4=d4; }
  else{
  dx1=d1; 
  dx2=d2; 
  dx3=d3;     
  dx4=d4;   
  }
  }
  
  if(secX<31 && secX>15){
  if(secBlink==1){
  dx1=d1;   
  dx2=d2|B10000000; 
  dx3=d3;     
  dx4=d4; }
  else{
  dx1=d1;    
  dx2=d2;
  dx3=d3;     
  dx4=d4;   
  }
  }  
  
  if(secX<46 && secX>30){
  if(secBlink==1){
  dx1=d1; 
  dx2=d2;   
  dx3=d3|B10000000;     
  dx4=d4; }
  else{
  dx1=d1;    
  dx2=d2;    
  dx3=d3;
  dx4=d4;
  }
  }  
  
  if(secX<60 && secX>45){
  if(secBlink==1){
  dx1=d1; 
  dx2=d2; 
  dx3=d3;   
  dx4=d4|B10000000;}
  else{
  dx1=d1; 
  dx2=d2; 
  dx3=d3;     
  dx4=d4;  
  }
  }    
  
  
}
//==================================================================================
if(mode==1){
  left=hrX;

  
  LEDx=LED;
  
  dx1=d1;
  dx2=d2; 
  dx3=B01000000;     
  dx4=B01000000;

  if(bb.clicks==1) {
    hrX--; 
    setime=1;    
  }
  if(bc.clicks==1) {
    hrX++; 
    setime=1;    
  }  
  

}
//==================================================================================
if(mode==2){
  right=minX;
  
  LEDx=LED;
  
  dx1=B01000000;
  dx2=B01000000; 
  dx3=d3;     
  dx4=d4;  

  if(bb.clicks==1) {
    minX--;  
    setime=1;    
  }
  if(bc.clicks==1) {
    minX++;   
    setime=1;    
  }  
}

//==================================================================================
if(mode==3){
  left=dayX;
  
  LEDx=LED;
  
  dx1=B01000000;
  dx2=B01001001; 
  dx3=digit[dayX];     
  dx4=B01000000;  

  if(bb.clicks==1) {
    dayX--; 
    setime=1;    
  }
  if(bc.clicks==1) {
    dayX++; 
    setime=1;    
  }  
}

//==================================================================================
if(mode==4){mode=0;
}



    
  if(setime==1){
    
    if(halfday==1){ 
    rtc.halt(false);
    rtc.writeProtect(false);  
    if(hrX<12){ rtc.setTime((hrX), (minX), (secX));}
    if(hrX==12){ rtc.setTime(0, (minX), (secX));}
    rtc.setDOW(dayX); } 
    
    if(halfday==2){ 
    rtc.halt(false);
    rtc.writeProtect(false);      
    if(hrX<12){ rtc.setTime((hrX+12), (minX), (secX)); }
    if(hrX==12){ rtc.setTime(12, (minX), (secX)); }
    rtc.setDOW((dayX)); } 
    
    setime=0;     
  }
  
 //===================Multiplex===================================
 t1=millis(); // multiplexed throught A1-A4 pins
  if (t1-t2>=1){
   
    counter++;
    if(counter==5) counter=1;
     
    if (counter==1){
      
      
    for(int x=4;x<8; x++){
    digitalWrite(x, HIGH);     
    }     
    digitalWrite(latchPin, LOW); 
    shiftOut(dataPin, clockPin, MSBFIRST ,LEDx); //(1-8 red LED   
    shiftOut(dataPin, clockPin, MSBFIRST ,dx4); //(A-G, Dot, 7-seg LED)   
    digitalWrite(latchPin, HIGH);      
    digitalWrite(4, LOW);            
    }
    
    if (counter==2){
    for(int x=4;x<8; x++){
    digitalWrite(x, HIGH);     
    }     
    
    digitalWrite(latchPin, LOW); 
    shiftOut(dataPin, clockPin, MSBFIRST ,LEDx); //(1-8 red LEDs)
    shiftOut(dataPin, clockPin, MSBFIRST ,dx3); //(A-G, Dot, 7-seg LED)   
    digitalWrite(latchPin, HIGH);   
    digitalWrite(5, LOW);         
    }    
    
    if (counter==3){
    for(int x=4;x<8; x++){
    digitalWrite(x, HIGH);     
    }     
    
    digitalWrite(latchPin, LOW); 
    shiftOut(dataPin, clockPin, MSBFIRST ,LEDx); //(1-8 red LEDs)
    shiftOut(dataPin, clockPin, MSBFIRST ,dx2); //(A-G, Dot, 7-seg LED)   
    digitalWrite(latchPin, HIGH);     
    digitalWrite(6, LOW);    
    }        

    if (counter==4){
    for(int x=4;x<8; x++){
    digitalWrite(x, HIGH);     
    }     
    
    digitalWrite(latchPin, LOW); 
    shiftOut(dataPin, clockPin, MSBFIRST ,LEDx); //(1-8 red LEDs)
    shiftOut(dataPin, clockPin, MSBFIRST ,dx1); //(A-G, Dot, 7-seg LED)   
    digitalWrite(latchPin, HIGH);      
    digitalWrite(7, LOW);          
    }        
        
  t2=t1;
  }
  
 //=================second timer=================================================   
 t3=millis(); 
  if (t3-t4>=1000){
    secX++;
    
  t4=t3;  
  }

  

  
 //============= blinker timer==========================================   
 t5=millis(); 
  if (t5-t6>=100){
    
  t6=t5;  
  }    
  
 //============= Second blinker timer==========================================   
 t7=millis(); 
  if (t7-t8>=interval){
    secBlink=!secBlink;
  t8=t7;  
  }    
  
 //=======================================================   

  if(ba.clicks==1) mode++; 
  if(ba.clicks==-1) mode=0;   
  
  if(bb.clicks==-1) ;   
  if(bc.clicks==-1) {secX=0; setime=1;}     
  

}
