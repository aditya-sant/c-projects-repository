#include <avr/io.h>

unsigned char rx_buf;

static volatile uint8_t tx_buffer[TX_BUFFER_SIZE];
static volatile uint8_t tx_buffer_head;
static volatile uint8_t tx_buffer_tail;
static volatile uint8_t rx_buffer[RX_BUFFER_SIZE];
static volatile uint8_t rx_buffer_head;
static volatile uint8_t rx_buffer_tail;


//Functions declaration
void setup(void);
void process(void);
void uart_init(unsigned int ubrr);
//uart functions
void uart_putchar(uint8_t c);
uint8_t uart_getchar(void);
uint8_t uart_available(void);
void uart_putstring(unsigned char* s);
void uart_getLine(unsigned char* buf, uint8_t n);
//ADC functions
uint16_t adc_read(uint8_t channel);
void adc_init();

// END function declarations


//main loop
int main() {
    setup();

    for ( ;; ) {
        process();
        _delay_ms(50);
    }
    return 0;
}

//initialises ADC and UART port
void setup(void) {
  ADMUX = (0 << REFS1) | (1 << REFS0) | 0b0011;
  //prescale 128 ~ 0b111;
  ADCSRA = (1 <<  ADEN) | 0b111;

  //init uart
  uart_init(MYUBRR);


}

void process(void) {
  //
  ADCSRA |= (1<<ADSC);

  //
  while (ADCRSA & (1 << ADSC)) {
    _delay_us(100);
  }

  //data is ready in ADCH and ADCL (or the combined regsiter ADC)
  uint16_t val = ADC;

  char buffer[10];

  //convert integer to string (base 10)
  itoa(val, buffer, 10);

  uart_putstring((unsigned char *) buffer);
  uart_putchar((uint8_t) '\n');
}

void uart_init(unsigned int ubrr) {

    cli();

    UBRR0H = (unsigned char)(ubrr>>8);
    UBRR0L = (unsigned char)(ubrr);
    UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
    tx_buffer_head = tx_buffer_tail = 0;
    rx_buffer_head = rx_buffer_tail = 0;

    sei();

}



// Transmit a byte
void uart_putchar(uint8_t c) {
    uint8_t i;

    i = tx_buffer_head + 1;
    if ( i >= TX_BUFFER_SIZE ) i = 0;
    while ( tx_buffer_tail == i ); // wait until space in buffer
    //cli();
    tx_buffer[i] = c;
    tx_buffer_head = i;
    UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0) | (1 << UDRIE0);
    //sei();
}

// Receive a byte
uint8_t uart_getchar(void) {
    uint8_t c, i;

    while ( rx_buffer_head == rx_buffer_tail ); // wait for character
    i = rx_buffer_tail + 1;
    if ( i >= RX_BUFFER_SIZE ) i = 0;
    c = rx_buffer[i];
    rx_buffer_tail = i;
    return c;
}


// Transmit a string
void uart_putstring(unsigned char* s)
{
    // transmit character until NULL is reached
    while(*s > 0) uart_putchar(*s++);
}


// Receive a string
void uart_getLine(unsigned char* buf, uint8_t n)
{
    uint8_t bufIdx = 0;
    unsigned char c;

    // while received character is not carriage return
    // and end of buffer has not been reached
    do
    {
        // receive character
        c = uart_getchar();

        // store character in buffer
        buf[bufIdx++] = c;
    }
    while((bufIdx < n) && (c != '\n'));

    // ensure buffer is null terminated
    buf[bufIdx] = 0;
}



uint8_t uart_available(void) {
    uint8_t head, tail;

    head = rx_buffer_head;
    tail = rx_buffer_tail;
    if ( head >= tail ) return head - tail;
    return RX_BUFFER_SIZE + head - tail;
}


// Transmit Interrupt
ISR(USART_UDRE_vect) {
    uint8_t i;

    if ( tx_buffer_head == tx_buffer_tail ) {
        // buffer is empty, disable transmit interrupt
        UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);
    }
    else {
        i = tx_buffer_tail + 1;
        if ( i >= TX_BUFFER_SIZE ) i = 0;
        UDR0 = tx_buffer[i];
        tx_buffer_tail = i;
    }
}

// Receive Interrupt
ISR(USART_RX_vect) {
    uint8_t c, i;

    c = UDR0;
    i = rx_buffer_head + 1;
    if ( i >= RX_BUFFER_SIZE ) i = 0;
    if ( i != rx_buffer_tail ) {
        rx_buffer[i] = c;
        rx_buffer_head = i;
    }
}
