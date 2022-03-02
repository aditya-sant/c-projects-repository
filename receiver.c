#define F_CPU(16000000UL)
#include <avr/io.h>
#include <util/delay.h>

#define BAUD(9600)
#define MYUBRR F_CPU/16/BAUD 1)

void uart_init(void);
unit8_t uart_getbyte(void);

int main(){

  uart_init();
  //D7 connected to other device
  DDRD |= 0b11111100;

  while(1)
  {
    unit8_t data = uart_getbyte()

    //shift to the position the LEDs are in.
    data <<= 2;

    PORTD &= ~(0b00111111);
    PORTD |= data;

    _delay_ms(10);
  }

  return 0;
}

void uart_init(void) {
  //sets both UBRR0H and UBRR0L properly.
  UBRR0 = MYUBRR;

  //enable receiver.
  UCSR0B |= (1<<RXEN0) | (0 << UCSZ02);
  //char size 8 bits   (with this ^).
  UCSROC |= (1<<UCSZ01) | (UCSZ00);
}

unit8_t uart_getbyte(void) {
  //if receive complete flag is 1
  while(!(UCSR0A & (1<<RXC0))) {
    //do nothing
    _delay_ms(1);
  }

  return UDR0;
}
