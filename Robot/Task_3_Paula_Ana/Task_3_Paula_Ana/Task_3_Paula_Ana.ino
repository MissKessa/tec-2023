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
int blackLeft = 161;
int blackRight = 127;
int speedLeft;
int speedRight;
int speed = 50;
int speed_rotate = 60;

//BLACK
int black = 150;
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

void checkout(bool out){
  if (out){
   
   
    analogWrite(PWMB_pin, 0);
    analogWrite(PWMA_pin, 0);
    digitalWrite(STBY_pin, LOW);
  }
}

void photoRead(){
  int PhotoLeft, PhotoRight = 0;

  PhotoLeft = analogRead(PhotoLeft_pin);
  PhotoLeft = map(PhotoLeft, blackLeft, 1023, 0, 102);

  PhotoRight = analogRead(PhotoRight_pin);
  PhotoRight = map(PhotoRight, blackRight, 1023, 0, 102);

  speedLeft = map(PhotoLeft, 0, 52, 150, 80);
 
  speedRight = map(PhotoRight, 0, 52, 150, 80);

  digitalWrite(AIN1_pin, HIGH);
  digitalWrite(AIN2_pin, LOW);

  digitalWrite(BIN1_pin, HIGH);
  digitalWrite(BIN2_pin, LOW);
  
  analogWrite(PWMA_pin, speedLeft);
  analogWrite(PWMB_pin, speedRight);
}

void forward(){
  digitalWrite(AIN1_pin, HIGH);
  digitalWrite(AIN2_pin, LOW);

  digitalWrite(BIN1_pin, HIGH);
  digitalWrite(BIN2_pin, LOW);

  analogWrite(PWMA_pin, speedLeft);
  analogWrite(PWMB_pin, speedRight);
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
  analogWrite(PWMA_pin, 0);
  analogWrite(PWMB_pin, speed_rotate);
}

void turnLeft(){
  analogWrite(PWMA_pin, speed_rotate);
  analogWrite(PWMB_pin, 0);
}

void values(){
  int PhotoLeft, PhotoRight = 0;
  PhotoLeft = analogRead(PhotoLeft_pin);
  PhotoRight = analogRead(PhotoRight_pin);

  Serial.print("Right: ");
  Serial.println(PhotoRight);
  Serial.print("Left: ");
  Serial.println(PhotoLeft);
}

void circlesRight(){
  analogWrite(PWMA_pin, speed_rotate);
  analogWrite(PWMB_pin, speed);
 
}
