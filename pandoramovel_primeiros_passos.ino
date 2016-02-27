//Hugreen.Solar Pandora Movel 0.1

#include <AFMotor.h>

// Select which 'port' M1, M2, M3 or M4. In this case, M4
AF_DCMotor ThrottleMotor(1, MOTOR12_64KHZ);
// You can also make another motor on port M1
AF_DCMotor SteeringMotor(2, MOTOR12_64KHZ);

char val; // Data received from serial port
const int ledPin = 13; // the pin that the LED is attached to
int incomingByte;      // a variable to read incoming serial data into

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Hugreen Pandora v1 - DC Motor test!");

  //AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz

  // Set the speed to start, from 0 (off) to 255 (max speed)
 ThrottleMotor.setSpeed(255);
  //ThrottleMotor.run(FORWARD);
  // turn on motor
  //ThrottleMotor.run(RELEASE);

  //OTHER MOTOR
SteeringMotor.setSpeed(255);
 // SteeringMotor.run(BACKWARD);
  // turn on motor
  //SteeringMotor.run(RELEASE);

}

void loop() {
  uint8_t i;

  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    // if it's a capital H (ASCII 72), turn on the LED:
    if (incomingByte == 'W' || incomingByte == 'w') {
     ThrottleMotor.run(FORWARD);
     SteeringMotor.run(BACKWARD);
      delay(1000); 
    }
       if (incomingByte == 'Q' || incomingByte == 'q') {
     ThrottleMotor.run(BACKWARD);
     SteeringMotor.run(FORWARD);
      delay(1000); 
    }
    else {
      ThrottleMotor.run(RELEASE);
       SteeringMotor.run(RELEASE);
    }
    if (incomingByte == 'A' || incomingByte == 'a') { 
      //Forward Right Turn
      ThrottleMotor.run(FORWARD);
      delay(500);
      
    }
    if (incomingByte == 'D' || incomingByte == 'd') { 
      //Forward Right Turn
     SteeringMotor.run(BACKWARD);
      delay(500); 
      
    }
     //else {
      //ThrottleMotor.run(RELEASE);
      //SteeringMotor.run(RELEASE);
    //}
    if (incomingByte == 'C' || incomingByte == 'c') {
      SteeringMotor.run(RELEASE);
    }
    // if it's an L (ASCII 76) turn off the LED:
    if (incomingByte == 'X' || incomingByte == 'x') {
      ThrottleMotor.run(BACKWARD);
      for (i=0; i<255; i++) {
        ThrottleMotor.setSpeed(i);  
        delay(10);
      }
    }
     else {
     // ThrottleMotor.run(RELEASE);
      //SteeringMotor.run(RELEASE);
    }
    // 
    if (incomingByte == 'S' || incomingByte == 's') {
      ThrottleMotor.run(RELEASE);
      SteeringMotor.run(RELEASE);
    }
  }    
}
