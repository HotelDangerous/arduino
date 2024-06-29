
// Demonstrating a Digital Input:
// Pressing a button to turn on an LED light.

#define LED 3
#define BUTTON 7

bool LED_ON = false;  // global variable

void setup() { // put your setup code here, to run once:
  pinMode(LED, OUTPUT);    // output for LED
  pinMode(BUTTON, INPUT);  // input for BUTTON
  
}

void loop() { // put your main code here, to run repeatedly:

  if(digitalRead(BUTTON) == HIGH){  // if the button was pressed
    if(LED_ON == false){            // and LED_ON is false
        digitalWrite(LED, HIGH);    // turn on the led
        LED_ON = true;             // set LED_ON to true
      }
    else{                           // otherwise
      digitalWrite(LED, LOW);       // turn the LED off
      LED_ON = false;              // set LED_ON to false
    }
  }
}
