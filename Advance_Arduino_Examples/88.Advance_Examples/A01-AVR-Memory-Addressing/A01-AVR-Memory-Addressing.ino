// Advance arduino Examples for Atmega8/168/328 (Mainly 8)
// AVR memory addressing
// When you are doing digitalWrite (2, HIGH), you are turning on bit 2 in PORTD. or PORTD= 0b00000100;
// Unlike a typical computer, where there are 5 elements: CPU, ALU, Input, Output, and Memory
// An avr only has 3 element: CPU, ALU and Memory
// And There are 3 types of memory in an Avr: Flash, RAM (SRAM) and ROM (EEPROM)
// So when you do Input/output, you are reading/writing to memory, mainly 8 bits binary number.
// and it is done so via Registers in the RAM memory. 
// Data fetch to the RAM, Process by the CPU, Get the Result back to Memory.
// There are 32 General purpose working registers and 64 I/O Registers in Atmega8
// PORTD is one of those I/O registers addresses @ (0x32, hex) in RAM memory slot; (50, dec)

/* OUTPUT file from Serial for this example
RAM Address of PORTD is:50   // of course. First 95 Addresses in RAM are for 32 General purpose working registers and 64 I/O Registers
RAM Address of love is:99    //love is an int array, it is a pointer in the memory, 
RAM Address of love 0 is:99    //so love and Love[0] are in the same memory address
RAM Address of love 1 is:101   //an int is 2 bytes, so 99+2=101
RAM Address of love 2 is:103   // 101+2=103
RAM Address of hate is:96  
RAM Address of hate 0 is:96    // same as above
RAM Address of hate 1 is:97    //but hate is a byte, so 96+1=97
RAM Address of hate 2 is:98    //97+1=98;
*/


int love[3]={1,2,3};
byte hate[3]={5,6,7};

void setup() {

  Serial.begin(9600);
 
  Serial.print("RAM Address of PORTD is:");
  Serial.println( ((int16_t)&PORTD));   

  Serial.print("RAM Address of love is:");
  Serial.println( ((int16_t)&love));

  Serial.print("RAM Address of love 0 is:");
  Serial.println( ((int16_t)&love[0]));

  Serial.print("RAM Address of love 1 is:");
  Serial.println( ((int16_t)&love[1]));  

  Serial.print("RAM Address of love 2 is:");
  Serial.println( ((int16_t)&love[2]));    

  Serial.print("RAM Address of hate is:");
  Serial.println( ((int16_t)&hate));  

  Serial.print("RAM Address of hate 0 is:");
  Serial.println( ((int16_t)&hate[0]));    

  Serial.print("RAM Address of hate 1 is:");
  Serial.println( ((int16_t)&hate[1]));   

  Serial.print("RAM Address of hate 2 is:");
  Serial.println( ((int16_t)&hate[2]));     
}

void loop() {
   
}


