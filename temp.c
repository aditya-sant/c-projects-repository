#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <util/delay.h>

#include <LiquidCrystal.h>
#define B1 9
#define B0 8
#define D4 4
#define D5 5
#define D6 6
#define D7 7

#define SET_BIT(reg, pin)           (reg) |= (1 << (pin))
#define CLEAR_BIT(reg, pin)         (reg) &= ~(1 << (pin))
#define WRITE_BIT(reg, pin, value)  (reg) = (((reg) & ~(1 << (pin))) | ((value) << (pin)))
#define BIT_VALUE(reg, pin)         (((reg) >> (pin)) & 1)
#define BIT_IS_SET(reg, pin)        (BIT_VALUE((reg),(pin))==1)

//uart definitions
#define BAUD (9600)
#define MYUBRR (F_CPU/16/BAUD-1)

// These buffers may be any size from 2 to 256 bytes.
#define  RX_BUFFER_SIZE  64
#define  TX_BUFFER_SIZE  64

//uart definitions
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
unsigned char pressed;

uint8_t rs = PD2, en = PD3;

LiquidCrystal lcd(rs, en, D4, D5, D6, D7);

//END function declarations.
void pwm_setup( uint16_t division_factor ) {
    //  Configure the digital I/O pin corresponding to OCR0A for output.
    //  Modify at most one pin in the DDR.
    DDRC |= (1<<PC0);

    //  Update the value of TCCR0A so that register OC0A will clear on compare
    //  match.
    TCCR0A |= (1<<COM0A1) | (0<<COM0A0);
    TCCR0A &= 0b10000011;
    //  Update TCCR0B to disable Force Output Compare functionality.
    TCCR0B |= (0<<FOC0A) | (0<<FOC0B);
    //  Update TCCR0B to ensure that the clock pre-scaler matches the
    //  designated division factor.
    if (division_factor == 1)
    {
      SET_BIT(TCCR0B, CS00);
      TCCR0B &= 0b00000001;
    }

    else if (division_factor == 8)
    {
      SET_BIT(TCCR0B, CS01);
      TCCR0B &= 0b00000010;
    }

    else if (division_factor == 64)
    {
      SET_BIT(TCCR0B, CS00);
      SET_BIT(TCCR0B, CS01);
      TCCR0B &= 0b00000011;
    }

    else if (division_factor == 256)
    {
      SET_BIT(TCCR0B, CS02);
      TCCR0B &= 0b00000100;
    }

    else if (division_factor == 1024)
    {
      SET_BIT(TCCR0B, CS00);
      SET_BIT(TCCR0B, CS02);
      TCCR0B &= 0b00000101;
    }
    TCCR0A |= (1<<WGM01) | (1<<WGM00);
}

void pwm_write( uint8_t duration) {
    OCR0A = duration;
}

void init_state(void) {
  DDRC &= ~(1<<PC0);
  pressed = 0;
}

int main() {
    uint16_t divider = 64;

    uint16_t duration = 32;

    pwm_setup(divider);
    pwm_write(duration);

  setup();
  init_state();

  for (;;) {
    process();
    _delay_ms(50);
  }
}

void setup(void) {
  //initialise UART.
  uart_init(MYUBRR);

  //Enable the matrix (PB0, PB1, PB2);
  SET_BIT(DDRB, 0);
  SET_BIT(DDRB, 1);
  SET_BIT(DDRB, 2);

  //initialise ADC
  ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

  //select channel PC0.
  ADMUX = (1<<REFS0);
}

void process(void) {
  char temp_buf[64];

  //Start singal conversion by setting ADSC bit in ADCSRA
  ADCSRA |= (1<<ADSC);

  // Wait for ADSC bit to clear, signalling conversion complete.
	 while ( ADCSRA & (1 << ADSC) ) {}

	// Result now available in ADC
	 uint16_t temp = ADC;

  // convert uint16_t to string
  itoa(temp, (char *)temp_buf,10);

  	double millivolts = temp * 5;
  	double offset = millivolts / 1024;
  	double current_temp = (offset - 0.49)*100;
  	uint16_t valid_temp = current_temp;
    itoa(valid_temp, (char *)temp_buf, 10);
  	lcd.begin(16, 2);
  	lcd.setCursor(0, 0);
  	lcd.print(valid_temp);
  	lcd.setCursor(7, 0);
  	lcd.print("CELSIUS");
  	lcd.setCursor(0, 0);

    //if value is above 40, turn on LED.
    if (temp > 188)
    {
      lcd.setCursor(0, 1);
      lcd.print("WARNING!");
      SET_BIT(PORTB, PB2);
      _delay_ms(500);

      CLEAR_BIT(PORTB, PB2);
      _delay_ms(500);

    }

    if (temp >= 211)
    {
	  lcd.setCursor(0, 1);
      lcd.print("EVACUATE!");
      SET_BIT(PORTB, PB1);
      SET_BIT(PORTB, PB2);
      _delay_ms(500);

      CLEAR_BIT(PORTB, PB1);
      CLEAR_BIT(PORTB, PB2);
      _delay_ms(500);
    }

    if (temp >= 266)
    {
	  lcd.setCursor(0, 1);
      lcd.print("CALL (000)!");
      SET_BIT(PORTB, PB0);
      SET_BIT(PORTB, PB1);
      SET_BIT(PORTB, PB2);
      _delay_ms(500);

      CLEAR_BIT(PORTB, PB0);
      CLEAR_BIT(PORTB, PB1);
      CLEAR_BIT(PORTB, PB2);
      _delay_ms(500);
    }

    else
    {
      CLEAR_BIT(PORTB, PB0);
      CLEAR_BIT(PORTB, PB1);
      CLEAR_BIT(PORTD, PB2);
    }

    //send serial data
   uart_putstring((unsigned char *) temp_buf);
   uart_putchar('\n');
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
