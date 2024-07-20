/* 
 * Arduino Traffic Light sketch
 * By Keenan Cunningham, 07/20/2024
 */

/* l1 and l2 stand for light 1 and light 2; respectively */
#define l1_button 3 // light 1 button
#define l1_red 2
#define l1_yellow 1
#define l1_green 0

#define l2_button 13  // light 2 button
#define l2_red 12
#define l2_yellow 11
#define l2_green 10

/* global variables */
int LIGHT_CHANGE_DELAY = 3000;    // delay between light color changes
int MINIMUM_GREEN_LIGHT = 5000;  // minimum time a light will be green is 10 seconds
int ALL_RED = 4000;               // both lanes have reds for 3 seconds to allow through traffic

void setup() {  // this function is run when the Arduino is turned on or reset
  /* all LEDs will be set to output */
  // light 1
  pinMode(l1_red, OUTPUT);
  pinMode(l1_yellow, OUTPUT);
  pinMode(l1_green, OUTPUT);

  // light 2
  pinMode(l2_red, OUTPUT);
  pinMode(l2_yellow, OUTPUT);
  pinMode(l2_green, OUTPUT);

  /* both buttons will be set to input */
  pinMode(l1_button, INPUT);
  pinMode(l2_button, INPUT);

  /* Initial State: When we begin, we want the light 1 to be green and light 2 to be red. None
   * of the other LEDs should be on. */
   digitalWrite(l1_green, HIGH);  // light 1, green LED is on
   digitalWrite(l2_red, HIGH);    // light 2, red LED is on

   /* all other LEDs are off */
   // light 1
   digitalWrite(l1_yellow, LOW);
   digitalWrite(l1_red, LOW);

   // light 2
   digitalWrite(l2_green, LOW);
   digitalWrite(l2_yellow, LOW);
   
}
  
void loop(){  // do this until the power is shut off
  if(digitalRead(l1_button)==HIGH && digitalRead(l2_green)==HIGH){
  // if someone is waiting at the light 1, change the lights
    delay(MINIMUM_GREEN_LIGHT);     // wait the minimum amount of time for a green light
    digitalWrite(l2_yellow, HIGH);  // light2: turn yellow light on
    digitalWrite(l2_green, LOW);    // light2: turn green light off
    delay(LIGHT_CHANGE_DELAY);      // allow light to stay yellow for 3 seconds
    digitalWrite(l2_red, HIGH);     // light2: turn red light on
    digitalWrite(l2_yellow, LOW);   // light2: turn yellow light off
    delay(ALL_RED);                 // both lights stay red to let traffic through
    digitalWrite(l1_green, HIGH);   // light1: turn on the green light
    digitalWrite(l1_red, LOW);      // light1: turn off the red light
  }
  if(digitalRead(l2_button)==HIGH && digitalRead(l1_green)==HIGH){
  // if someone is waiting at light2, change the lights
    delay(MINIMUM_GREEN_LIGHT);     // wait the minimum amount of time for a green light
    digitalWrite(l1_yellow, HIGH);  // light1: turn yellow light on
    digitalWrite(l1_green, LOW);    // light1: turn green light off
    delay(LIGHT_CHANGE_DELAY);      // allow light to stay yellow for 3 seconds
    digitalWrite(l1_red, HIGH);     // light1: turn red light on
    digitalWrite(l1_yellow, LOW);   // light1: turn yellow light off
    delay(ALL_RED);                 // both lights stay red to let traffic through
    digitalWrite(l2_green, HIGH);   // light2: turn on the green light
    digitalWrite(l2_red, LOW);      // light2: turn off the red light
 
  }  
}
