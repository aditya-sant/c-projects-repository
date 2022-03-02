#include <stdint.h>
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void uart_setup(void);
void uart_put_byte(unsigned char byte_val);
void uart_printf(const char * fmt, ...);

#define SET_BIT(reg, pin)		    (reg) |= (1 << (pin))
#define CLEAR_BIT(reg, pin)		  (reg) &= ~(1 << (pin))
#define WRITE_BIT(reg, pin, value)   (reg) = (((reg) & ~(1 << (pin))) | ((value) << (pin)))
#define BIT_VALUE(reg, pin)		  (((reg) >> (pin)) & 1)
#define BIT_IS_SET(reg, pin)	     (BIT_VALUE((reg),(pin))==1)

#define FREQ (16000000.0)
#define PRESCALE (256.0)

void setup(void) {
    //  (a) Initialise Timer 0 in normal mode so that it overflows
    //  with a period of approximately 0.004 seconds.
    //  Hint: use the table in Lecture 9.
    TCCR0A = 0;
    //TCCR0B = 4;

    CLEAR_BIT(TCCR0B, CS00);
    CLEAR_BIT(TCCR0B, CS01);
    SET_BIT(TCCR0B, CS02);

    //  (b) Enable timer overflow interrupt for Timer 0.
    //TIMSK0 = 1;
    SET_BIT(TIMSK0, TOIE0);

    //  (c) Turn on interrupts.
    sei();

    //  (d) Enable the I/O pin labelled A2 for digital input.
    //DDRC &= ~(PC2);
    CLEAR_BIT(DDRC, 2);

    //  (e) Send a debugging message to the serial port using
    //  the uart_printf function defined below. The message should consist of
    //  your student number, "n10795472", followed immediately by a comma,
    //  followed by the pre-scale factor that corresponds to a timer overflow
    //  period of approximately 0.004 seconds. Terminate the
    //  debugging message with a carriage-return-linefeed pair, "\r\n".
    uart_printf("n10795472,256\r\n");
}

//  (f) Create a volatile global variable called switch_counter.
//  The variable should be an 8-bit unsigned integer.
//  Initialise the variable to zero.

// INSERT GLOBAL VARIABLE HERE
volatile uint8_t switch_counter = 0b00000000;

//  (g) Define a volatile 8-bit unsigned global variable
//  called switch_state which will store the current state of the switch.
//  Initialise it to zero.

// INSERT GLOBAL VARIABLE HERE
volatile uint8_t switch_state = 0;


//  (h) Define an interrupt service routine to process timer overflow
//  interrupts for Timer 0. Every time the interrupt service
//  routine is called, switch_counter should:
//      (h.a) Left-shift switch_counter one place;
//      (h.b) Bitwise AND switch_counter with a mask in which the
//          3 bits on the right are 1 and the others are 0.
//      (h.c) Use bitwise OR to add the current open/closed value of the
//          I/O pin labelled A2 to the history.
//      (h.d) If switch_counter is equal to the bit mask, then the switch has been
//          observed 3 times in a row to be closed. Assign the value 1 to
//          switch_state, indicating that the switch should now be considered to be
//          officially "closed".
//      (h.e) If switch_counter is equal to 0, then the switch has been observed
//          to be open at least 3 in a row, so store 0 in switch_state,
//          indicating that the switch should now be considered to be officially "open".

// INSERT ISR HERE
ISR(TIMER0_OVF_vect){

  uint8_t mask = 0b00000111;
  switch_counter = ((switch_counter<<1) & mask) | ((PINC >> 2) & 0b00000001);

  if (switch_counter == mask)
  {
    switch_state = 1;
  }

  if (switch_counter == 0)
  {
    switch_state = 0;
  }

}
// -------------------------------------------------
// Helper functions.
// -------------------------------------------------

// Make sure this is not too big!
char buffer[100];

void uart_setup(void) {
#define BAUD (9600)
#define UBRR (F_CPU / 16 / BAUD - 1)
    UBRR0H = UBRR >> 8;
    UBRR0L = UBRR & 0b11111111;
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
    UCSR0C = (3 << UCSZ00);
}

void uart_printf(const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    for (int i = 0; buffer[i]; i++) {
        uart_put_byte(buffer[i]);
    }
}

#ifndef __AMS__
void uart_put_byte(unsigned char data) {
    while (!(UCSR0A & (1 << UDRE0))) { /* Wait */ }
    UDR0 = data;
}
#endif

int main() {
    uart_setup();
    setup();

    uint8_t prevState = 0;

    for (;;) {
        if (switch_state != prevState) {
            prevState = switch_state;
            uart_printf("Switch is %s.\r\n",  prevState ? "closed" : "open");
        }
    }

    return 0;
}
