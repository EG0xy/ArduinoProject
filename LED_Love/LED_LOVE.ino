// A0-A5 >> LED 1-6 (14-19)
// 0-13 >> LED 7-20
//0-9 right half heart
//0, 20-11 right half heart
//Flyandance 2015

byte ledLove[20]={14, 15, 16, 17, 18, 19, 0, 1, 2,3,4,5,6,7,8,9,10,11,12,13};
byte ledlovefromBehind[20]={4,5,6,7,8,9,10,11,12,13,14, 15, 16, 17, 18, 19, 0, 1, 2,3};

byte lll[11]={14,15,16,17,18,19,0,1,2,3,4};
byte llr[11]={14,13,12,11,10,9, 8,7,6,5,4};

int randomness[5]={20, 50, 100, 200, 400};
int ran=2;

byte counter=0;
int mode=10; //m7=full; m10=fun
byte timer=100; //(0-255 ms)
byte second=0;

unsigned long t1=0;
unsigned long t2=0;

unsigned long t3=0;
unsigned long t4=0;

void setup() {
  
  for(int x=0; x<20; x++){
  pinMode (ledLove[x], OUTPUT);
  }


}

//=======================================================================================================

void loop() {
  
t1=millis();
if(t1-t2>=1000){
  second++;
  t2=t1;
}

t3=millis();
if(t3-t4>=timer){
  counter++;
  t4=t3;
}

//===========
if(mode==0){
  
timer=randomness[ran];  

digitalWrite (lll[counter], HIGH); 
digitalWrite (llr[counter], HIGH);

if(counter==11){
for(int x=0; x<20; x++){
digitalWrite (ledLove[x], LOW);
}
counter=0;
ran=random(5);
mode=random(20);
}

}

//===========
if(mode==1){

timer=randomness[ran]; 

digitalWrite (ledLove[counter], HIGH);

if(counter==20){
for(int x=0; x<20; x++){
digitalWrite (ledLove[x], LOW);
}

counter=0;
ran=random(5);
mode=random(20);
}

}

//===========
if(mode==2){
  
timer=randomness[ran];   
  
digitalWrite (ledLove[19-counter], HIGH);

if(counter==20){
for(int x=0; x<20; x++){
digitalWrite (ledLove[x], LOW);
}

counter=0;
ran=random(5);
mode=random(20);
}

}

//===========
if(mode==3){
  
timer=randomness[ran];   
  
digitalWrite (lll[11-counter], HIGH); 
digitalWrite (llr[11-counter], HIGH);

if(counter==11){
for(int x=0; x<20; x++){
digitalWrite (ledLove[x], LOW);
}
counter=0;
ran=random(5);
mode=random(20);
}

}

//===========

if(mode==4){
  
timer=100;  
  
if(counter%2==0){
for(int x=0; x<20; x++){
digitalWrite (ledLove[x], HIGH);
}}

if(counter%2!=0){
for(int x=0; x<20; x++){
digitalWrite (ledLove[x], LOW);
}}


if(counter==20){
for(int x=0; x<20; x++){
digitalWrite (ledLove[x], LOW);
}
counter=0;
ran=random(5);
mode=random(20);
}

}


//===========

if(mode==5){
  
timer=100;  

if(counter%3==0){
for(int x=0; x<20; x++){
digitalWrite (ledLove[x], LOW);
}}

if(counter%3!=0){
for(int x=0; x<20; x++){
digitalWrite (ledLove[x], HIGH);
}}


if(counter==20){
for(int x=0; x<20; x++){
digitalWrite (ledLove[x], LOW);
}
counter=0;
ran=random(5);
mode=random(20);
}

}


//===========
if(mode==6){

timer=100;  

if(counter%5==0){
for(int x=0; x<20; x++){
digitalWrite (ledLove[x], HIGH);
}}

if(counter%5!=0){
for(int x=0; x<20; x++){
digitalWrite (ledLove[x], LOW);
}}


if(counter==30){
for(int x=0; x<20; x++){
digitalWrite (ledLove[x], LOW);
}
counter=0;
ran=random(5);
mode=random(20);
}

}
//===========

if(mode==7){
  
timer=100;  

for(int x=0; x<20; x++){
digitalWrite (ledLove[x], HIGH);
}


if(counter==30){
for(int x=0; x<20; x++){
digitalWrite (ledLove[x], LOW);
}
counter=0;
ran=random(5);
mode=random(20);
}

}
//===========
  
if(mode==8){
  
timer=100;  

for(int x=0; x<20; x++){
digitalWrite (ledLove[x], LOW);
}


if(counter==10){
for(int x=0; x<20; x++){
digitalWrite (ledLove[x], LOW);
}
counter=0;
ran=random(5);
mode=random(20);
}

}
//===========


if(mode==9){
  
timer=100;  

for(int x=0; x<20; x+=2){
digitalWrite (ledLove[x], HIGH);
}


if(counter==10){
for(int x=0; x<20; x++){
digitalWrite (ledLove[x], LOW);
}
counter=0;
ran=random(5);
mode=random(20);
}

}
//===========

if(mode==10){
  
timer=100;  

if(counter%2==0){
for(int x=0; x<20; x+=2){
digitalWrite (ledLove[x], HIGH);
}

for(int x=1; x<20; x+=2){
digitalWrite (ledLove[x], LOW);
}
}


if(counter%2!=0){
for(int x=0; x<20; x+=2){
digitalWrite (ledLove[x], LOW);
}

for(int x=1; x<20; x+=2){
digitalWrite (ledLove[x], HIGH);
}
}


if(counter==30){
for(int x=0; x<20; x++){
digitalWrite (ledLove[x], LOW);
}
counter=0;
ran=random(5);
mode=random(20);
}

}
//===========


if(mode==11){
  
timer=100;  

for(int x=1; x<20; x+=2){
digitalWrite (ledLove[x], HIGH);
}


if(counter==10){
for(int x=0; x<20; x++){
digitalWrite (ledLove[x], LOW);
}
counter=0;
ran=random(5);
mode=random(20);
}

}
//===========

if(mode==12){

timer=randomness[ran]; 
if(counter%2==0){
digitalWrite (ledLove[counter], HIGH);}

if(counter==20){
for(int x=0; x<20; x++){
digitalWrite (ledLove[x], LOW);
}

counter=0;
ran=random(5);
mode=random(20);
}

}

//===========


if(mode==13){

timer=randomness[ran]; 
if(counter%2!=0){
digitalWrite (ledLove[19-counter], HIGH);}

if(counter==20){
for(int x=0; x<20; x++){
digitalWrite (ledLove[x], LOW);
}

counter=0;
ran=random(5);
mode=random(20);
}

}

//===========


if(mode==14){

timer=randomness[ran]; 
if(counter%2==0){
digitalWrite (lll[counter], HIGH); 
digitalWrite (llr[counter], HIGH);}

if(counter==11){
for(int x=0; x<20; x++){
digitalWrite (ledLove[x], LOW);
}

counter=0;
ran=random(5);
mode=random(20);
}

}

//===========


if(mode==15){

timer=randomness[ran]; 
if(counter%2!=0){
digitalWrite (lll[11-counter], HIGH); 
digitalWrite (llr[11-counter], HIGH);}

if(counter==11){
for(int x=0; x<20; x++){
digitalWrite (ledLove[x], LOW);
}

counter=0;
ran=random(5);
mode=random(20);
}

}

//===========


if(mode==16){

timer=randomness[ran]; 
digitalWrite (ledlovefromBehind[counter], HIGH);

if(counter==20){
for(int x=0; x<20; x++){
digitalWrite (ledLove[x], LOW);
}

counter=0;
ran=random(5);
mode=random(20);
}

}

//===========



if(mode==17){

timer=randomness[ran]; 
digitalWrite (ledlovefromBehind[19-counter], HIGH);

if(counter==20){
for(int x=0; x<20; x++){
digitalWrite (ledLove[x], LOW);
}

counter=0;
ran=random(5);
mode=random(20);
}

}

//===========



if(mode==18){

timer=randomness[ran]; 
if(counter%2!=0){
digitalWrite (ledlovefromBehind[19-counter], HIGH);
}

if(counter==20){
for(int x=0; x<20; x++){
digitalWrite (ledLove[x], LOW);
}

counter=0;
ran=random(5);
mode=random(20);
}

}

//===========


if(mode==19){

timer=randomness[ran]; 
if(counter%2==0){
digitalWrite (ledlovefromBehind[counter], HIGH);
}

if(counter==20){
for(int x=0; x<20; x++){
digitalWrite (ledLove[x], LOW);
}

counter=0;
ran=random(5);
mode=random(20);
}

}

//===========




}
