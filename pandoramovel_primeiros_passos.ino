//Hugreen.Solar Pandora Movel 0.1

#include <AFMotor.h>

// Select which 'port' M1, M2, M3 or M4. In this case, M4
AF_DCMotor Motor1Motor(1, MOTOR12_64KHZ);
// You can also make another motor on port M1
AF_DCMotor Motor2Motor(2, MOTOR12_64KHZ);

char val; // Data received from serial port
const int led = 2; // the pin that the LED is attached to
int incomingByte;      // a variable to read incoming serial data into
int photocellPin = 5;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the sensor divider



void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Hugreen Pandora v1 - DC Motor test!");
  pinMode(led, OUTPUT); 
  //AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz

  // Set the speed to start, from 0 (off) to 255 (max speed)
Motor1Motor.setSpeed(255);
Motor2Motor.setSpeed(255);

}

void loop() {
  uint8_t i;

  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    // if it's a capital H (ASCII 72), turn on the LED:
    if (incomingByte == 'W' || incomingByte == 'w') {
     //Para tras 
     Serial.println("Frente");
     Motor1Motor.run(BACKWARD);
     Motor2Motor.run(BACKWARD);;
      delay(250); 
    }
               if (incomingByte == 'S' || incomingByte == 's') {
     Serial.println("Marcha reh");
     Motor1Motor.run(FORWARD);
     Motor2Motor.run(FORWARD);
      delay(250); 
    }
                   if (incomingByte == 'A' || incomingByte == 'a') {
     Serial.println("Esquerda");
     Motor1Motor.run(BACKWARD);
     Motor2Motor.run(FORWARD);
      delay(250); 
    }
       if (incomingByte == 'D' || incomingByte == 'd') {
     Serial.println("Direita");
     Motor1Motor.run(FORWARD);
     Motor2Motor.run(BACKWARD);
      delay(250); 
    }
     
           if (incomingByte == 'L' || incomingByte == 'l') {
     Serial.println("Lazer jidi");
     digitalWrite(led, HIGH);
      delay(500); 
     digitalWrite(led, LOW);

    }
     if (incomingByte == 'B' || incomingByte == 'b') {
     Serial.print("Analog reading = ");
     Serial.println(photocellReading); 
     delay(500); 
    
    }
    
        if (incomingByte == 'Q' || incomingByte == 'q') {
     //Para tras 
     Motor1Motor.run(BACKWARD);
     Motor2Motor.run(BACKWARD);
      delay(250); 
    }
    else {
      Motor1Motor.run(RELEASE);
      Motor2Motor.run(RELEASE);
    }

     
    if (incomingByte == 'X' || incomingByte == 'x') {
      Motor1Motor.run(RELEASE);
      Motor2Motor.run(RELEASE);
    }
  }    
}
