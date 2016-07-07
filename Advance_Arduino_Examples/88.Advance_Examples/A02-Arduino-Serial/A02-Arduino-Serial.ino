/*
sprintf --> Gather variables into a string for Serial Print
 sprintf(string,"format",variables); 

sscanf  --> Read a string from Serial Input and set various variables.
  sscanf (string,"format",&variables);  
  
http://www.cplusplus.com/reference/cstdio/

Serial Communication  ( By Flyandance )
This is a simple clock program for learning how to use Serial
[0]Time:00:00:00:00() <<--This is the Output text from Serial Print
[0] <<-- This is the numbers of bytes in Serial Read buffer (Or number of characters that you have typed in)
Time:00:00:00:00 <<-- This is the time
() <<-- This is your entered string

To set the time, type: #HR[space]#MIN[space]#SEC[space]; for instance 12:34:55 --> (12 34 55 )
You can type in letters too. To clear your inputs, enter few [space]

You can only enter 15 characters/bytes because of the limited size of our array :incoming[15];
But the Serial read buffer supports up to 64 bytes.
 */


int tmsec,tsec,tmin,thr;
unsigned long ta,tb;
char print_string[40];
char incoming[15];
byte c;

void setup (){
  Serial.begin(9600);
   }
  
void loop  (){

  Serial.println (print_string);  

  if (!Serial.available()) {   
  c=0;
  }
  
  if (Serial.available()) {
  incoming[c]=Serial.read();
  c++;
  sscanf (incoming,"%d %d %d ",&thr,&tmin,&tsec);  
  }

  
 sprintf(print_string,"[%01d]Time:%02d:%02d:%02d:%02d(%s)",Serial.available(),thr,tmin,tsec,tmsec,incoming); 


  ta=millis();
  if(ta-tb>=100){
    tmsec++;    
    tb=ta;
  }

  if(tmsec==10){tmsec=0;tsec++;}
  if(tsec==60){tsec=0;tmin++;}
  if(tmin==60){tmin=0;thr++;}
  if(thr==24){thr=0;}
      
     
  
  }  
  
  
  
  /*
  Handy ASCII Table ~ Character Map
!, dec: 33, hex: 21
", dec: 34, hex: 22
#, dec: 35, hex: 23
$, dec: 36, hex: 24
%, dec: 37, hex: 25
&, dec: 38, hex: 26
', dec: 39, hex: 27
(, dec: 40, hex: 28
), dec: 41, hex: 29
*, dec: 42, hex: 2A
+, dec: 43, hex: 2B
,, dec: 44, hex: 2C
-, dec: 45, hex: 2D
., dec: 46, hex: 2E
/, dec: 47, hex: 2F
0, dec: 48, hex: 30
1, dec: 49, hex: 31
2, dec: 50, hex: 32
3, dec: 51, hex: 33
4, dec: 52, hex: 34
5, dec: 53, hex: 35
6, dec: 54, hex: 36
7, dec: 55, hex: 37
8, dec: 56, hex: 38
9, dec: 57, hex: 39
:, dec: 58, hex: 3A
;, dec: 59, hex: 3B
<, dec: 60, hex: 3C
=, dec: 61, hex: 3D
>, dec: 62, hex: 3E
?, dec: 63, hex: 3F
@, dec: 64, hex: 40
A, dec: 65, hex: 41
B, dec: 66, hex: 42
C, dec: 67, hex: 43
D, dec: 68, hex: 44
E, dec: 69, hex: 45
F, dec: 70, hex: 46
G, dec: 71, hex: 47
H, dec: 72, hex: 48
I, dec: 73, hex: 49
J, dec: 74, hex: 4A
K, dec: 75, hex: 4B
L, dec: 76, hex: 4C
M, dec: 77, hex: 4D
N, dec: 78, hex: 4E
O, dec: 79, hex: 4F
P, dec: 80, hex: 50
Q, dec: 81, hex: 51
R, dec: 82, hex: 52
S, dec: 83, hex: 53
T, dec: 84, hex: 54
U, dec: 85, hex: 55
V, dec: 86, hex: 56
W, dec: 87, hex: 57
X, dec: 88, hex: 58
Y, dec: 89, hex: 59
Z, dec: 90, hex: 5A
[, dec: 91, hex: 5B
\, dec: 92, hex: 5C
], dec: 93, hex: 5D
^, dec: 94, hex: 5E
_, dec: 95, hex: 5F
`, dec: 96, hex: 60
a, dec: 97, hex: 61
b, dec: 98, hex: 62
c, dec: 99, hex: 63
d, dec: 100, hex: 64
e, dec: 101, hex: 65
f, dec: 102, hex: 66
g, dec: 103, hex: 67
h, dec: 104, hex: 68
i, dec: 105, hex: 69
j, dec: 106, hex: 6A
k, dec: 107, hex: 6B
l, dec: 108, hex: 6C
m, dec: 109, hex: 6D
n, dec: 110, hex: 6E
o, dec: 111, hex: 6F
p, dec: 112, hex: 70
q, dec: 113, hex: 71
r, dec: 114, hex: 72
s, dec: 115, hex: 73
t, dec: 116, hex: 74
u, dec: 117, hex: 75
v, dec: 118, hex: 76
w, dec: 119, hex: 77
x, dec: 120, hex: 78
y, dec: 121, hex: 79
z, dec: 122, hex: 7A
{, dec: 123, hex: 7B
|, dec: 124, hex: 7C
}, dec: 125, hex: 7D
~, dec: 126, hex: 7E
  */