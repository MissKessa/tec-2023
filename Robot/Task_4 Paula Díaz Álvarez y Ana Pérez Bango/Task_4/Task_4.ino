/*
Made by Paula Díaz Álvarez and Ana Pérez Bango
*/


//RIGHT MOTOR
#define AIN1_pin 2 //forward if 1,0
#define AIN2_pin 3 //backwards

//LEFT MOTOR
#define BIN1_pin 4 //forward
#define BIN2_pin 5 //backwards

//Speed motors
#define PWMA_pin 9 //right
#define PWMB_pin 10 //left

//Enable motors
#define STBY_pin 13

//Photo transistors
#define PhotoLeft_pin A0 //tracking sensor pin left
#define PhotoRight_pin A1 //tracking sensor pin right

//Example mototr speed
int speed = 128;
//int speed = 100;
int speed_rotate = 60;

//BLACK
int black = 300;
int i=0;

void setup() {
  Serial.begin(115200);
  //initialize the motor control pins as output:
  //Right motor
  pinMode(AIN1_pin, OUTPUT);
  pinMode(AIN2_pin, OUTPUT);
  //Left motor
  pinMode(BIN1_pin, OUTPUT);
  pinMode(BIN2_pin, OUTPUT);
  //Standby mode
  pinMode(STBY_pin, OUTPUT);
  //Speed of the motor PWM
  pinMode(PWMA_pin, OUTPUT); //right
  pinMode(PWMB_pin, OUTPUT); //left

  //initialize the tracking sensor pin as input
  pinMode(PhotoLeft_pin, INPUT);
  pinMode(PhotoRight_pin, INPUT);

  start();
}

void loop() {
  photoRead();
}

void photoRead(){
  //variables for reading the photo track sensors
  int PhotoLeft, PhotoRight = 0;
  //Example to save reading input and store on PhotoLeft, PhotoRight
  PhotoLeft = analogRead(PhotoLeft_pin);
  //Serial.println(PhotoLeft);
  //delay(1000);
  PhotoRight = analogRead(PhotoRight_pin);
  //Serial.println(PhotoRight);
  //delay(1000);
 
  if (PhotoLeft<=black && PhotoRight<=black) {
    forward();
    delay(10);
    i=0;
  } else if (PhotoLeft<=black && PhotoRight>black) {
    i=1;
    turnRight();
    //circlesRight();
    //delay(10);
  } else if (PhotoLeft>black && PhotoRight<=black) {
    i=2;
    turnLeft();
    //delay(10);
  } else{
    analogWrite(PWMA_pin, 0);
    analogWrite(PWMB_pin, 0);
    turnRight();
  }
}

void forward(){
  digitalWrite(AIN1_pin, HIGH);
  digitalWrite(AIN2_pin, LOW);

  digitalWrite(BIN1_pin, HIGH);
  digitalWrite(BIN2_pin, LOW);

  analogWrite(PWMA_pin, speed);
  analogWrite(PWMB_pin, speed);
}

void backward(){
  digitalWrite(AIN1_pin, LOW);
  digitalWrite(AIN2_pin, HIGH);

  digitalWrite(BIN1_pin, LOW);
  digitalWrite(BIN2_pin, HIGH);

  analogWrite(PWMA_pin, speed);
  analogWrite(PWMB_pin, speed);
}

void stop(){
  //digitalWrite(STBY_pin, LOW);
  analogWrite(PWMA_pin, 0);
  analogWrite(PWMB_pin, 0);
  digitalWrite(STBY_pin, LOW);
}

void start(){
  digitalWrite(STBY_pin, HIGH);
}



void turnRight(){
  analogWrite(PWMA_pin, speed_rotate/3);
  analogWrite(PWMB_pin, speed_rotate);
}

void circlesRight(){
  analogWrite(PWMA_pin, speed_rotate);
  analogWrite(PWMB_pin, speed);
}

void turnLeft(){
  analogWrite(PWMA_pin, speed_rotate);
  analogWrite(PWMB_pin, speed_rotate/3);
}

void circlesLeft(){
  analogWrite(PWMA_pin, speed_rotate);
  analogWrite(PWMB_pin, speed);
}
void accelerate(){
  for (int i=0; i<=speed;i++){
    analogWrite(PWMA_pin, i);
    analogWrite(PWMB_pin, i);
    delay(100);
  }
}

void deccelerate(){
  for (int i=speed; i>=0;i--){
    analogWrite(PWMA_pin, i);
    analogWrite(PWMB_pin, i);
    delay(100);
  }
}