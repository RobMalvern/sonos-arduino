#ifndef Buttons_h
#define Buttons_h

#include "Arduino.h"

class Button {
  public:
    enum Event { None, SingleClick, LongClick };
	enum InputType { Digital, Analogue };
    Button(byte pin);
	Button(uint8_t pin, unsigned int Level);
    void turnOnPullUp();
    void turnOffPullUp();
    Event getEvent();
    
  private:
    enum LastEventType { Unknown, Off, SingleClickOn };
    enum MomentaryState { Up, Down };
	InputType _pinInputType;
    byte _pin;
	unsigned int _voltageLevel; // used for buttons on Analogue input (a la LCD shield)
	unsigned int _shortClick;
    unsigned int _longClick;
    unsigned long _lastEventTime;
    LastEventType _lastEventType;
    
    MomentaryState getState();
    
};

#endif
