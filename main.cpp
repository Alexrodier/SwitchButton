#include <Arduino.h>

#define PIN_LED 2
#define PIN_BUTTON 12

bool ledIsOn = false;
bool buttonReleased = false;

void setup() {
  Serial.begin(9600);
  pinMode (PIN_LED, OUTPUT);
  pinMode (PIN_BUTTON, INPUT);
  // put your setup code here, to run once:
}

void doAction() {
  if(ledIsOn){
    digitalWrite (PIN_LED, HIGH);	// turn on the LED
    ledIsOn = 0;
  }else{
    digitalWrite (PIN_LED, LOW);	// turn on the LED
    ledIsOn = 1;
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