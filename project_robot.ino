//Authours: Jingyi Yang and Otavio Paz

//library of blue tooth
#include <SoftwareSerial.h>
#define pinRX 0
#define pinTX 1
SoftwareSerial blueTSerial(pinRX, pinTX); // RX、TX

//library for IIC communication
#include <Wire.h>
#include <splash.h>
//library of OLED
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // define width of OLED in pixel
#define SCREEN_HEIGHT 64 // define hight of OLED in pixel
//define reset pin for OLED, Adafruit_SSD1306
#define OLED_MOSI  A5//SDA
#define OLED_CLK   A4//SCL
#define OLED_DC    12
#define OLED_CS    13
#define OLED_RESET 28//RST
//Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

//orange PWM, red Vcc, Brown ground
//library for stepper motor
#include <Servo.h>
#define FRONTLEFT 0
#define FRONTRIGHT 1
#define BACKLEFT 2
#define BACKRIGHT 3
#define HEAP 0
#define KNEA 1
#define FEET 2

Servo servos[4][3];
const int H_START = 45;//H1 0 (maximum to the front) - 90 (straight to the side)
const int H_FRONT1 = 0;
const int H_FRONT2 = 20;
const int H_BACK = 90;

const int K_START = 90;
const int K_UP = 110;
const int K_DOWN = 70;

const int F_START = 90;
const int F_DOWN = 90;
int posServos[4][3] = {
  {H_START, K_START, F_START},//180-90
  {180 - H_START, K_START, 180-F_START},
  {180 - H_START, K_START, F_START},//0-90, 0-90
  {H_START, K_START, 180-F_START}//0-90, 180-90
  };
const int servoPins[4][3] = {{2,3,4},{8,9,10},{5,6,7},{A1,A2,A3}};


const int FORWARD = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BACKWARD = 3;

const unsigned char face_bitmap_OIP [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x80, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void setup() {
  Serial.begin(9600);
  blueTSerial.begin(38400);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  //set_up for servo motors
  for(int i = 0; i < 4; i++){
    for(int j = 0; j <3; j++){
      servos[i][j].attach(servoPins[i][j]);
      delay(20);
      servos[i][j].write(posServos[i][j]);
      delay(20);
    }
  }
  face_display();
}

void blueTooth(){
  if (blueTSerial.available())
    Serial.print(blueTSerial.read());
  blueTSerial.print(Serial.read());
  blueTSerial.write(Serial.read());
}

void face_display(){
  display.clearDisplay();//clear the display
  display.drawBitmap(0, 0 , face_bitmap_OIP, 128, 64, WHITE);
  display.display();
}

void moveForward3(){
  servoMove(FRONTRIGHT,KNEA,K_UP);
  servoMove(FRONTRIGHT,HEAP,180 - H_FRONT1);
  servoMove(FRONTRIGHT,KNEA,K_DOWN);

  servoMove(BACKLEFT,KNEA,K_UP);
  servoMove(BACKLEFT,HEAP,180 - H_FRONT1);
  servoMove(BACKLEFT,KNEA,K_DOWN);

  servoMove(FRONTRIGHT,HEAP,180 - H_START);
  servoMove(BACKLEFT,HEAP,180 - H_START);
  
  delay(200);
  servoMove(FRONTRIGHT,KNEA,K_START);
  servoMove(BACKLEFT,KNEA,K_START);

  servoMove(FRONTLEFT,KNEA,180 - K_UP);
  servoMove(FRONTLEFT,HEAP,H_FRONT1);
  servoMove(FRONTLEFT,KNEA,180 - K_DOWN);

  servoMove(BACKRIGHT,KNEA,180 - K_UP);
  servoMove(BACKRIGHT,HEAP,H_FRONT1);
  servoMove(BACKRIGHT,KNEA,180 - K_DOWN);

  servoMove(FRONTLEFT,HEAP,H_START);
  servoMove(BACKRIGHT,HEAP,H_START);

  delay(200);
  servoMove(FRONTLEFT,KNEA,K_START);
  servoMove(BACKRIGHT,KNEA,K_START);
}

void moveBackward(){
  servoMove(FRONTRIGHT,KNEA,K_UP);
  servoMove(FRONTRIGHT,HEAP,180 - H_BACK);
  servoMove(FRONTRIGHT,KNEA,K_DOWN);

  servoMove(BACKLEFT,KNEA,K_UP);
  servoMove(BACKLEFT,HEAP,180 - H_BACK);
  servoMove(BACKLEFT,KNEA,K_DOWN);

  servoMove(FRONTRIGHT,HEAP,180 - H_START);
  servoMove(BACKLEFT,HEAP,180 - H_START);
  
  delay(200);
  servoMove(FRONTRIGHT,KNEA,K_START);
  servoMove(BACKLEFT,KNEA,K_START);

  servoMove(FRONTLEFT,KNEA,180 - K_UP);
  servoMove(FRONTLEFT,HEAP,H_BACK);
  servoMove(FRONTLEFT,KNEA,180 - K_DOWN);

  servoMove(BACKRIGHT,KNEA,180 - K_UP);
  servoMove(BACKRIGHT,HEAP,H_BACK);
  servoMove(BACKRIGHT,KNEA,180 - K_DOWN);

  servoMove(FRONTLEFT,HEAP,H_START);
  servoMove(BACKRIGHT,HEAP,H_START);

  delay(200);
  servoMove(FRONTLEFT,KNEA,K_START);
  servoMove(BACKRIGHT,KNEA,K_START);
}

//R is direction of the leg, C is components of the leg
void servoMove(int r, int c,int pos){
  if(pos > posServos[r][c]){
    for(int i = posServos[r][c]; i < pos; i++){
      servos[r][c].write(i);
      delay(10);
    }
  }
  else{
    for(int i = posServos[r][c]; i > pos; i--){
      servos[r][c].write(i);
      delay(10);
    }
  }
  posServos[r][c] = pos;
}

void move(int direction){
  switch(direction){
    case FORWARD:
      moveForward3();
      break;
    case BACKWARD:
      break;
    case LEFT:
      break;
    case RIGHT:
      break;
  }
}



void loop() {
  while(Serial.available()){
    if(Serial.read()=='f'){
      moveForward3();
    }
  }
}
