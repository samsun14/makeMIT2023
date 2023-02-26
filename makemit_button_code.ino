#include <Servo.h>
Servo servo1;
Servo servo2;
int lastStateG = 0;
int lastStateB = 1;

void setup() {
  servo1.attach(11);
  servo2.attach(12);
  Serial.begin(9600); // Starts the serial communication
  pinMode(7, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);


}

void loop() {
  servo1.write(0);
  servo2.write(90);
  int currentStateG = digitalRead(7);
  int currentStateB = digitalRead(6);

  if (currentStateG == 0 && lastStateG ==1){
    servo1.write(90);
    lastStateG = 0;
    delay(2000);
    servo1.write(0);
  } 
  if (currentStateG == 1 && lastStateG ==0){
    servo1.write(90);
    lastStateG = 1;
    delay(2000);
    servo1.write(0);
  }
  if (currentStateB == 0 && lastStateB ==1){
    servo2.write(0);
    lastStateB = 0;
    delay(2000);
    servo1.write(90);
  } 
  if (currentStateB == 1 && lastStateB ==0){
    servo2.write(0);
    lastStateB = 1;
    delay(2000);
    servo1.write(90);
  }


}
