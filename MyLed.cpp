#include "MyLed.h"

MyLed::MyLed(int pin, bool pinActive)
{
  this->pin = pin; 
  this->pinActive = pinActive;

  setBlink(true);
  
  pinMode(this->pin, OUTPUT);
}

MyLed::~MyLed() 
{
  // do nothing 
}

void MyLed::setBlink(bool blink)
{
  this->blink = blink;
  if (this->blink)
    _next = millis() + 500;
}

void MyLed::loop()
{
  uint32_t cur = millis();
  if (blink)
  {
    if (cur >= _next) {
      digitalWrite(pin, !digitalRead(pin));
      _next = cur + 500;
    }
  } else {
    // turn off led
    digitalWrite(pin, this->pinActive == LOW ? HIGH : LOW);  
  }
}
