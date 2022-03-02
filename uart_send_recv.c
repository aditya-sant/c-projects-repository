#include <stdint.h>
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void uart_putbyte(unsigned char data);
int uart_getbyte(unsigned char *buffer);

/*
**  Define a function named uart_send_chars which transmits the contents of
**  a standard C string (i.e. a null-terminated char array) over UART. The
**  function should iterate over the characters in the array, using a cast to
**  convert each to an unsigned char, and transmitting the resulting byte via
**  uart_putbyte. The end of the string should be signalled by sending a single
**  null byte. That is, the number 0, not the character '0'.
**
**  Param: str - string to be transmitted.
**
**  Returns: Nothing.
*/

// INSERT CODE HERE.
void uart_send_chars(char s[]) {
  int i = 0;
  while(s[i] != 0)
  {
    uart_putbyte(s[i]);
    i++;
  }
  uart_putbyte(0);
}

/*
**  Define a function named uart_receive_chars which uses uart_getbyte to fetch
**  the contents of a standard C string (i.e. a null-terminated char array)
**  from UART. The function should wait for characters, and must not return
**  until a complete string has been retrieved.
**
**  Note that uart_getbyte will return 1 if a byte is available, and zero
**  otherwise. Therefore, to fetch a byte and store it in a variable named x,
**  you will need to use a construct of the form:
**      unsigned char x;
**      while (! uart_getbyte(&x)) {
**          // Do nothing.
**      }
**
**  Param: buffer - a char array which has capacity to store a string
**      containing at most (buff_len-1) characters. If more than (buff_len-1)
**      characters are received, the first (buff_len-1) of them should be
**      stored consecutively in the buffer, and any others discarded. The
**      string must be terminated correctly with a null terminator in all
**      circumstances.
**
**  Param: buff_len - an int which specifies the capacity of the buffer.
**
**  Returns: Nothing. However, up to buff_len elements of buffer may have been
**      overwritten by incoming data.
*/

// INSERT CODE HERE.
void uart_receive_chars(char *buff, int buff_len) {
  int i = 0;
  unsigned char ch;

  for (;;)
  {
    while(!uart_getbyte(&ch)){}
    if (ch == 0)
    {
      break;
    }
    else if (i < (buff_len-1))
    {
      buff[i] = ch;
      i++;
    }
  }
  buff[i] = 0;
}
/*
***************************************************************************
**  Initialise UART.
***************************************************************************
*/
void uart_init(void) {
    UBRR0 = F_CPU / 16 / 9600 - 1;
    UCSR0A = 0;
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
    UCSR0C = (3 << UCSZ00);
}

/*
**************************************************************************
**  Send one byte, protecting against overrun in the transmit buffer.
**
**  Param: data - a byte to be transmitted.
**
**  Returns: Nothing.
***************************************************************************
*/
#ifndef __AMS__
void uart_putbyte(unsigned char data) {
    // Wait for empty transmit buffer
    while (!(UCSR0A & (1 << UDRE0)));

    // Send data by assigning into UDR0
    UDR0 = data;
}
#endif

/*
***************************************************************************
**  Attempt to receive one byte, returning immediately to sender.
**
**  Param: buffer - the address of a byte in which a result may be stored.
**
**  Returns: If a byte is available returns 1 and stores the incoming byte in
**      location referenced by buffer. Otherwise returns 0 and makes no other
**      change to the state.
***************************************************************************
*/
#ifndef __AMS__
int uart_getbyte(unsigned char *buffer) {
    // If receive buffer contains data...
    if (UCSR0A & (1 << RXC0)) {
        // Copy received byte from UDR0 into memory location (*buffer)
        *buffer = UDR0;
        //
        return 1;
    }
    else {
        return 0;
    }
}
#endif

/*
***************************************************************************
**  Implement main event loop.
***************************************************************************
*/
void process() {
    // Use two devices, as indicated in the supplied TinkerCad model. One
    //  device acts as the sender (is_sender = 1), the other as receiver
    // (is_sender = 0). Change this to set the role accordingly.
    const int is_sender = 1;

    if (is_sender) {
        static char * messages_to_send[] = {
            "", // Empty string
            "A", // String with one symbol.
            "Hello from CAB202!", // Multiple symbols
            "1234567890abcdefghijklmnopqrstuvwxyz", // Longer than buffer size.
            NULL, // End of list
        };

        static int next_message = 0;
        uart_send_chars(messages_to_send[next_message]);
        next_message ++;
        if (messages_to_send[next_message] == NULL) next_message = 0;
        _delay_ms(300);
    }
    else {
        #define BUFF_SIZE 20
        char buffer[BUFF_SIZE];
        uart_receive_chars(buffer, BUFF_SIZE);
        uart_send_chars(buffer);
        uart_putbyte('\r');
        uart_putbyte('\n');
    }
}



int main(void) {
    uart_init();

    while (1) {
        process();
    }

    return 0;
}
