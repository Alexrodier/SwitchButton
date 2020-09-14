#include <Arduino.h>

#define PIN_LED 2
#define PIN_BUTTON 12

bool ledIsOn = false;
bool buttonReleased = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (PIN_LED, OUTPUT);
  pinMode (PIN_BUTTON, INPUT);
}

void doAction() {
  if(ledIsOn){
    digitalWrite (PIN_LED, HIGH);	// turn on the LED
    ledIsOn = false;
  }else{
    digitalWrite (PIN_LED, LOW);	// turn off the LED
    ledIsOn = true;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(PIN_BUTTON) == HIGH && !buttonReleased){
    buttonReleased = true;
    doAction();
  }
  if(digitalRead(PIN_BUTTON) == LOW){
    buttonReleased = false;
  }
}