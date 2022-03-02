#include <avr/io.h>
#include <util/delay.h>

int main(){
  //LED connected to C0.
  //Button on C5.

  //Port C:
  //PORTC: Controlling voltage on pins.
  //PINC: Reading voltage on pins.
  //DDRC: Specify data direction.

  //set bit 0 of DDRC to say C0 is an output.
  DDRC |= (1<<0);
  //clear bit 5 of DDRC to say C5 is an input.
  DDRC &=  ~(1<<5);

  // if (PINC & (1<<5)){
  //   //bit 5 of PINC is set,
  //   //C5 has 5V on it.
  //   PORTC |= (1<<0);
  // }
  //set bit 0 of PORTC to turn on pin C0.

  while(1) //infinite loop, 1 = true
  {
    if (PINC & (1 << 5))
    {
      PORTC ^= (1<<0);
    }
  }

  return 0;
}
