#include <Servo.h>

//left up leg
Servo servo1; //F1 30 (perpendicular) - 110 (extended upwards)
Servo servo2; //K1 20 (extended upwards) - 110 (parallel to ground) - 160 (max extended downwards)
Servo servo3; //H1 0 (maximum to the front) - 75 (straight to the side)

//left down leg
Servo servo6; //F3  0 (extended upwards) - 70 (perpendicular)
Servo servo5; //K3  45 (max extended downwards) - 70 (parallel to ground) - 180 (extended upwards)
Servo servo4; //H3  65 (straight to the side) - 140 (maximum to the back)

// right up leg
Servo servo7; //F2 70 (max extended upwards) - 160 (perpendicular)
Servo servo8; //K2 50 (max extended downwards) - 90 (parallel to ground)  - 180 (max extended upwards)
Servo servo9; //H2 90 (straight to the side) - 180 (maximum to the front)

//right down leg
Servo servo10; //F4 50 (max extended downwards) - 110 (perpendicular)
Servo servo11; //K4 0 (exnteded upwards) - 110 (parallel to ground) - 140 (extended downwards)
Servo servo12; //H4 30 (maximum to the back) - 85 (straight to the side) - 

void setup() {
  // Attach servos to pins
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);

  servo4.attach(5);
  servo5.attach(6);
  servo6.attach(7);

  //  servo7.attach(8);
  //  servo8.attach(9);
  //  servo9.attach(A0);
  //  servo10.attach(A1);
  //  servo11.attach(A2);
  //  servo12.attach(A3);

  // Set initial positions to 45 degrees
  //  servo1.write(40); //feet 1
  //  servo2.write(30); //knee 1
  //  servo3.write(0); //hip 1

  //  servo4.write(65);
  //  servo5.write(70);
  servo6.write(30);

  //  servo7.write(45);
  //  servo8.write(45);
  //  servo9.write(45);
  //  servo10.write(45);
  //  servo11.write(45);
  //  servo12.write(45);
}

void loop() {
  // Nothing needed in the loop for this example
}
