#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

// Declare a global variable named previous_state which is suitable to store a
//  single byte. Do not initialise the variable at the point of declaration.
//  The value of the variable will be managed by the init_state and edge_detected
//  functions.

// INSERT DECLARATION HERE
unsigned char previous_state;

//  Define a parameterless function called init_state which returns nothing.
//
//  The function must enable digital input from a pull-down switch connected to
//  the I/O pin labelled "PD2" on an Arduino Uno board. It should also
//  assign zero to global variable .
//
//  Apart from updating the global variable, the function must update only
//  those bits required to enable digital input from the designated switch. The
//  function must achieve the required side effect regardless of the prior
//  state of all registers. In particular, **do not assume** that memory has
//  previously been initialised with some value, zero or otherwise.

// INSERT CODE HERE.
void init_state(void) {
  DDRD &= ~(1<<PD2);
  previous_state = 0;
}

//  Define a parameterless function called edge_detected which returns an
//  int which indicates that a rising edge has been detected in the state of
//  a pull-down switch connected to I/O pin labelled "PD2" on an
//  Arduino Uno board.
//
//  The function returns 1 if a rising edge is detected in the signal from the
//  switch and 0 otherwise.
//
//  The function may read and update the value of global variable previous_state
//  but apart from that it may not alter the value of any other register or
//  global variable.
//  To detect a rising edge, use the global variable to remember the old state
//  of the switch, and compare it to the current state of the switch. If the
//  old state is 0 and it is now non-zero, you have a rising edge. Otherwise,
//  you do not have a rising edge.
//  https://www.google.com/search?q=rising+edge

// INSERT CODE HERE.
int edge_detected(void) {
  unsigned char current_state = PIND & (1<<PD2);

  int rising = (previous_state == 0) && (current_state != 0);

  previous_state = current_state;
  return rising;
}

void setup_builtin_led(void);
void toggle_builtin_led(void);
void simulate_other_setup();

int main(void) {
    simulate_other_setup();
    setup_builtin_led();
    init_state();

    while(1) {
        int rising = edge_detected();

        if (rising) toggle_builtin_led();
    }
}

void setup_builtin_led(void) {
    DDRB |= (1<<5);
}

void toggle_builtin_led(void) {
    PORTB ^= (1<<5);
}

void simulate_other_setup(void) {
    //  Simulate situation where other important setup actions have been
    //  performed prior to calling our functions.
    srand(26105);
     DDRB = rand() & 255;
     PINB = rand() & 255;
    PORTB = rand() & 255;
     DDRC = rand() & 255;
     PINC = rand() & 255;
    PORTC = rand() & 255;
     DDRD = rand() & 255;
     PIND = rand() & 255;
    PORTD = rand() & 255;
    previous_state =  rand() & 255;
}
