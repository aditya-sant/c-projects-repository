#define F_CPU(16000000UL)
#include <avr/io.h>
#include <util/delay.h>

#define BAUD(9600)
#define MYUBRR F_CPU/16/BAUD 1)

void uart_init(void);
unit8_t uart_getbyte(void);
int main() {

  uart_init();

  uinit8_t data = 0b000000001;
  while (1) {
    //send data
    uart_putbyte(data);

    //modify data for next bit.
    data++;

    _delay_ms(500);
    }
  return 0;
}

void uart_init(void) {
  //sets both UBRR0H and UBRR0L properly.
  UBRR0 = MYUBRR;

  //enable transmitter.
  UCSR0B |= (1<<RXEN0) | (0 << UCSZ02);
  //char size 8 bits   (with this ^).
  UCSROC |= (1<<UCSZ01) | (UCSZ00);
}

unit8_t uart_getbyte(unit8_t data) {
  //if receive complete flag is 1
  while(!(UCSR0A & (1<<UDRE0))) {
    //do nothing
    _delay_ms(1);
  }

  UDR0 = data;
}
