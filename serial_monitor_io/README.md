# Serial Monitor Input/Output
Serial monitor I/O is a kind of boring Arduino program, but important step in the arduino learnig process. Nothing is required for this project except an arduino and USB cable. The 
main goal of this project is to learn to use the following functions:
```c++
/* in setup */
Serial.begin(9600);  // set up the serial monitor window; make sure the value passed is equal to the baud defined in the monitor window

/* in loop */
Serial.flush();  // flush junk from the serial monitor input
Serial.available();  // function that returns 0 when no input has been sent to the Arduino, and a positive number otherwise
Serial.read();       // read data sent from the serial monitor
```
The project shows how we read in numbers and even numbers greater than $9$ dispite the Arduino only excepting 1 digit at a time.
