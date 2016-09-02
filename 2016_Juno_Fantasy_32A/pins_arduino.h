#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>
/*
ATmega32
   
PCINT15-8: D7-0  : bit 1
PCINT31-24: D15-8  : bit 3
PCINT23-16: D23-16 : bit 2
PCINT7-0: D31-24   : bit 0
*/

#define STANDARD_PINOUT
#define NUM_DIGITAL_PINS            32
#define NUM_ANALOG_INPUTS           8
#define analogInputToDigitalPin(p)  ((p < NUM_ANALOG_INPUTS) ? (p) + 24 : -1)
#define digitalPinToInterrupt(p)  ((p) == 2 ? 2 : ((p) == 10 ? 0 : ((p) == 11 ? 1 : NOT_AN_INTERRUPT)))

#if defined(__AVR_ATmega8535__) || defined(__AVR_ATmega16__) || defined(__AVR_ATmega32__)
#define digitalPinHasPWM(p)         ((p) == 3 || (p) == 12 || (p) == 13 || (p) == 15)

#elif defined(__AVR_ATmega164A__) || defined(__AVR_ATmega164P__) || defined(__AVR_ATmega324A__) || \
defined(__AVR_ATmega324P__) || defined(__AVR_ATmega324PA__) || defined(__AVR_ATmega644__) || \
defined(__AVR_ATmega644P__)
#define digitalPinHasPWM(p)         ((p) == 3 || (p) == 4 || (p) == 12 || (p) == 13 || (p) == 14 || (p) == 15)

#elif defined(__AVR_ATmega1284__) || defined(__AVR_ATmega1284P__)
 #define digitalPinHasPWM(p)         ((p) == 3 || (p) == 4 || (p) == 6 || (p) == 7 || (p) == 12 || (p) == 13 || (p) == 14 || (p) == 15)
#endif


static const uint8_t LED = 15;
#define LED_BUILTIN 0

static const uint8_t SS   = 12;
static const uint8_t MOSI = 13;
static const uint8_t MISO = 14;
static const uint8_t SCK  = 15;

static const uint8_t SDA = 17;
static const uint8_t SCL = 16;

static const uint8_t A0 = 0;
static const uint8_t A1 = 1;
static const uint8_t A2 = 2;
static const uint8_t A3 = 3;
static const uint8_t A4 = 4;
static const uint8_t A5 = 5;
static const uint8_t A6 = 6;
static const uint8_t A7 = 7;


#if defined(__AVR_ATmega164A__) || defined(__AVR_ATmega164P__) || defined(__AVR_ATmega324A__) || \
defined(__AVR_ATmega324P__) || defined(__AVR_ATmega324PA__) || defined(__AVR_ATmega644__) || \
defined(__AVR_ATmega644P__) || defined(__AVR_ATmega1284__) || defined(__AVR_ATmega1284P__)
#define digitalPinToPCICR(p)    (((p) >= 0 && (p) < NUM_DIGITAL_PINS) ? (&PCICR) : ((uint8_t *)0))
#define digitalPinToPCICRbit(p) (((p) <= 7) ? 1 : (((p) <= 15) ? 3 : (((p) <= 23) ? 2 : 0)))
#define digitalPinToPCMSK(p)    (((p) <= 7) ? (&PCMSK2) : (((p) <= 13) ? (&PCMSK0) : (((p) <= 21) ? (&PCMSK1) : ((uint8_t *)0))))
#define digitalPinToPCMSKbit(p) ((p) % 8)
#endif

#if defined(__AVR_ATmega164A__) || defined(__AVR_ATmega164P__) || defined(__AVR_ATmega324A__) || \
defined(__AVR_ATmega324P__) || defined(__AVR_ATmega324PA__)
/**** Needed to get the SD library to work. 
Missing definitions in the iom164.h/iom324.h file ****/
#define SPR0 0
#define SPR1 1
#define CPHA 2
#define CPOL 3
#define MSTR 4
#define DORD 5
#define SPE 6
#define SPIE 7
#define SPSR _SFR_IO8(0x2D)
#define SPI2X 0
#define WCOL 6
#define SPIF 7
#define SPCR _SFR_IO8(0x2C)
#define SPDR _SFR_IO8(0x2E)
#endif


#ifdef ARDUINO_MAIN

#define PA 1
#define PB 2
#define PC 3
#define PD 4

// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] =
{
	NOT_A_PORT,
	(uint16_t) &DDRA,
	(uint16_t) &DDRB,
	(uint16_t) &DDRC,
	(uint16_t) &DDRD,
};

const uint16_t PROGMEM port_to_output_PGM[] =
{
	NOT_A_PORT,
	(uint16_t) &PORTA,
	(uint16_t) &PORTB,
	(uint16_t) &PORTC,
	(uint16_t) &PORTD,
};

const uint16_t PROGMEM port_to_input_PGM[] =
{
	NOT_A_PORT,
	(uint16_t) &PINA,
	(uint16_t) &PINB,
	(uint16_t) &PINC,
	(uint16_t) &PIND,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] =
{
	PA,
	PA,
	PA,
	PA,
	PA,
	PA,
	PA,
	PA, 
	PB, 
	PB,
	PB,
	PB,
	PB,
	PB,
	PB,
	PB,
	PC,
	PC,
	PC,
	PC,
	PC,
	PC,
   	PC,
	PC,	
	PD,
	PD,
	PD,
	PD,
	PD,
	PD,
	PD,
	PD
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] =
{
	_BV(0), /* D0, port A */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7),
	_BV(0), /* D8, port B */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7),
	_BV(0), /* D16, port C */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7),
	_BV(0), /* D24, port D */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7)
};


#if defined(__AVR_ATmega8535__) || defined(__AVR_ATmega16__) || defined(__AVR_ATmega32__)
const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
{
	NOT_ON_TIMER, 	/* D0  - PA0 */
	NOT_ON_TIMER, 	/* D1  - PA1 */
	NOT_ON_TIMER, 	/* D2  - PA2 */
	NOT_ON_TIMER,   /* D3  - PA3 */
	NOT_ON_TIMER, 	/* D4  - PA4 */
	NOT_ON_TIMER, 	/* D5  - PA5 */
	NOT_ON_TIMER, 	/* D6  - PA6 */
	NOT_ON_TIMER,	/* D7  - PA7 */
	NOT_ON_TIMER, 	/* D8  - PB0 */
	NOT_ON_TIMER, 	/* D9  - PB1 */
	NOT_ON_TIMER, 	/* D10 - PB2 */
	TIMER0A, 	    /* D11 - PB3 */
	NOT_ON_TIMER,   /* D12 - PB4 */
	NOT_ON_TIMER,   /* D13 - PB5 */
	NOT_ON_TIMER,   /* D14 - PB6 */
	NOT_ON_TIMER,   /* D15 - PB7 */
	NOT_ON_TIMER, 	/* D16 - PC0 */
	NOT_ON_TIMER,   /* D17 - PC1 */
	NOT_ON_TIMER,   /* D18 - PC2 */
	NOT_ON_TIMER,   /* D19 - PC3 */
	NOT_ON_TIMER,   /* D20 - PC4 */
	NOT_ON_TIMER,   /* D21 - PC5 */
	NOT_ON_TIMER,   /* D22 - PC6 */
	NOT_ON_TIMER,   /* D23 - PC7 */
	NOT_ON_TIMER,   /* D24 - PD0 */
	NOT_ON_TIMER,   /* D25 - PD1 */
	NOT_ON_TIMER,   /* D26 - PD2 */
	NOT_ON_TIMER,   /* D27 - PD3 */
	TIMER1B,    	/* D28 - PD4 */
	TIMER1A,   		/* D29 - PD5 */
	NOT_ON_TIMER,   /* D30 - PD6 */
	TIMER2    		/* D31 - PD7 */
};


#endif // Timer defs

#endif // ARDUINO_MAIN

#endif // Pins_Arduino_h

// vim:ai:cin:sts=2 sw=2 ft=cpp
