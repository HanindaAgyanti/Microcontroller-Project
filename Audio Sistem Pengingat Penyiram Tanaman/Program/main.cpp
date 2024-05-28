#include <avr/io.h>
#include <avr/eeprom.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include "suara.h" // Include the header file with the audio data

volatile bool play = false;
volatile uint8_t track = 0;
volatile uint16_t count = 0;

ISR(TIMER0_COMPA_vect) {
  if (play) {
    if (track == 0) {
      OCR1A = pgm_read_byte(&suara[count]); // Play track 0
      count++;
      if (count >= sizeof(suara)) {
        play = false;
        OCR1A = 0;
      }
    }
  }
}

ISR(INT1_vect) {
  // Reset button pressed
  play = false;
  OCR1A = 0; // Stop audio playback
}

void initPWM(void);
void TimerInit(void);
void initADC(void);
void initResetButton(void);

int main(void) {
  DDRD |= _BV(DDD6); // Set PD6 (OC0A/OC1A) as output for PWM
  PORTD |= _BV(PORTD2) | _BV(PORTD3); // Enable pull-up resistors on PD2 and PD3

  initPWM();
  TimerInit();
  initADC(); // Initialize ADC
  initResetButton(); // Initialize reset button interrupt

  sei();

  while (1) {
    // Start ADC conversion
    ADCSRA |= (1 << ADSC); 
    // Wait for conversion to complete
    while (ADCSRA & (1 << ADSC)); 
    uint16_t soilMoisture = ADC; 

    // Logic to control audio playback based on soil moisture levels
    if (soilMoisture >= 600 && !play) { // Adjust the dry threshold as needed
      play = true;
      track = 0;
      count = 0;
    } else if (soilMoisture <= 400) { // Adjust the wet threshold as needed
      play = false;
      OCR1A = 0; // Stop audio playback
    }
  }
}

void initPWM() {
  DDRB |= _BV(DDB2); // Set PB1 (OC1A) as output for PWM
  TCCR1A = _BV(WGM10) | _BV(COM1A1); // Fast PWM, 8-bit
  TCCR1B = _BV(WGM12) | _BV(CS10);   // Fast PWM, no prescaler
  OCR1A = 0; // Initialize PWM output to 0
}

void TimerInit() {
  TCCR0A = _BV(WGM01); // CTC mode
  TCCR0B = _BV(CS01);  // Prescaler 8
  OCR0A = 250;
  TIMSK0 |= _BV(OCIE0A); // Enable compare match interrupt
}

void initADC() {
  ADMUX = _BV(REFS0); // Select AVCC as voltage reference and set ADC0 as default input
  ADCSRA = _BV(ADEN) | _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0); // Enable ADC and set prescaler to 128
}

void initResetButton() {
  EICRA |= _BV(ISC11); // Trigger INT1 on falling edge
  EIMSK |= _BV(INT1);  // Enable INT1 interrupt
  EIFR |= _BV(INTF1);  // Clear any pending INT1 interrupt
}
