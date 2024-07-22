int number; // global variable

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.flush();  // clear junk from the buffer
  number = 0;
  while(Serial.available()==0){  // while no input
    // do nothing
  }
  Serial.flush();
  while(Serial.available() > 0){  // while input
    // do the following
    number = Serial.read()-'0';  // read input and remove the character '0' from it
    delay(5);
    while(Serial.available()> 0){  // clever trick to synthetically read in larger numbers
      number*=10;
      number += Serial.read()-'0';
    }
    Serial.println(number);
  }
}
