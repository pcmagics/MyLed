#include "MyLed.h"

#define PIN_LED 16

MyLed *led = NULL;

bool blink = true;

void setup() {
  
  led = new MyLed(PIN_LED);
  led->setBlink(blink);
  
}

void loop() {

  uint32_t cur = millis();
  static uint32_t next = cur + 10 * 1000;
  if (cur >= next) 
  {
    blink = !blink;
    led->setBlink(blink);
    next = cur + 10 * 1000;    
  }

  led->loop();
}
