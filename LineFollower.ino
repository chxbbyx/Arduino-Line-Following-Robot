//***************************************************************************Line Following Robot*************************************************************************************
//``````````````````````````````````````````````````````````````````````````DCST Project Group 04`````````````````````````````````````````````````````````````````````````````````````

/* Sensor Panel
                                @              @              @               @                @
                                ^              ^              ^               ^                ^
                            most left        left           middle          right           most right
                             (mLeft)        (left)         (middle)        (right)           (mRight)
 */



// Left Motor
int leftMotor= 9;  //left motor enA
int leftForward = 3; // in1
int leftBackward = 2; // in2

//Right Motor
int rightMotor = 10; // right motor enB
int rightBackward = 5; // in3
int rightForward= 4; // in4


// Line Following Sensors
int mostLeft = 22;
int leftSens = 24;
int middleSens =26;
int rightSens = 28;
int mostRight =30;

// Ultrasonic Sensor
int trigger = 6;    // Trigger pin of the ultrasonic sensor
int echo = 7;       // Echo pin of the ultrasonic sensor
int alarm = 11;      // Bulb control pin



void motorSpeed (int rightSpeed ,int leftSpeed){
  Serial.print("  Left Motor Speed: ");
  Serial.print(leftSpeed);
  Serial.print("  Right Motor Speed: ");
  Serial.println(rightSpeed);
  
  analogWrite(leftMotor, leftSpeed); // Set the speed value between 0 and 255
  analogWrite(rightMotor, rightSpeed);

  digitalWrite(leftForward, HIGH);
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, HIGH);
  digitalWrite(rightBackward, LOW);

  }


void setup() {
  // Set the motor control pins as outputs
  pinMode(leftMotor, OUTPUT); // Left Motor pin9
  pinMode(leftForward, OUTPUT); //pin22
  pinMode(leftBackward, OUTPUT);// pin 24
  
  pinMode(rightMotor, OUTPUT); // pin 10
  pinMode(rightForward, OUTPUT); //pin 28
  pinMode(rightBackward, OUTPUT); //pin 26

  // Initialize the Serial communication
  Serial.begin(9600);
  pinMode(mostLeft, INPUT); 
  pinMode(leftSens, INPUT);
  pinMode(middleSens, INPUT);
  pinMode(rightSens, INPUT);
  pinMode(mostRight, INPUT);


  // Ultrasonic sensor pins
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  
  // Bulb control pin
  pinMode(alarm, OUTPUT);
  
  // Initialize the Serial communication
  Serial.begin(9600);



}

void loop() {
  
  // Reaing sensor values

  int mLeft = digitalRead(mostLeft);
  int left = digitalRead(leftSens);
  int middle = digitalRead(middleSens);
  int right = digitalRead(rightSens);
  int mRight = digitalRead(mostRight);



// Ultrasonic sensor variables
  long duration, distance;
  
// Trigger the ultrasonic sensor 
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  
//calculate the distance
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;
  long length= distance;
  
  Serial.print("Distance: ");
  Serial.print(length);
  Serial.println(" cm");
  
// Check if an object is within a certain distance
  if (length>5) {
    // Object detected,
    digitalWrite(alarm, HIGH);
    motorSpeed(0, 0);
    
  } else {
   // No object detected, 
    digitalWrite(alarm, LOW);
  }


  

  if ((mLeft== 0) && (left== 0) && (middle==1) && (right== 0) && (mRight== 0)) { // Straight
    motorSpeed (80,75); 
  }
  else if ((mLeft== 0) && (left== 0) && (middle==  1) && (right== 1) && (mRight== 0)) { //  low left double
    motorSpeed (65,55);
  }  
  else if ((mLeft== 0 )&& (left== 0) && (middle==  0) && (right== 1) && (mRight== 0)) { //  low left
    motorSpeed (65,55); 
  }
  else if ((mLeft== 0) && (left== 0) && (middle==  0) && (right== 1) && (mRight== 1)){ // high left double
    motorSpeed(60,65);
  }
  else if ((mLeft== 0) && (left== 0) && (middle==  0) && (right== 0) && (mRight== 1)){ // high left
    motorSpeed(60,65);
  }
  else if ((mLeft== 0) && (left== 1) && (middle==  1) && (right== 0) && (mRight== 0)) { //  low right double
    motorSpeed (63,55);
  } 
  else if ((mLeft== 0) && (left== 1) && (middle==  0) && (right== 0) && (mRight== 0)){ // low right
    motorSpeed(62,55);
  }
  else if ((mLeft== 1) && (left== 0) && (middle==  0) && (right== 0) && (mRight== 0)){ //high right
    motorSpeed(65,55);
  }
  else if ((mLeft== 1) && (left== 1) && (middle==  0 )&& (right== 0) && (mRight== 0)){ //high right double
    motorSpeed(65,55);
  }
  else if ((mLeft== 1) && (left== 1) && (middle==  1) && (right== 0) && (mRight== 0)){ // turn left
    motorSpeed(0,55);
  }
  else if ((mLeft== 1) && (left== 1) && (middle==  1) && (right== 0) && (mRight== 0)){ // turn right
    motorSpeed(65,0);
  }
  else if ((mLeft== 1) && (left== 1) && (middle==  1) && (right== 1) && (mRight== 1)){ // stop
    motorSpeed(0,0);
  }
  
  else if ((mLeft== 0) &&( left== 0) && (middle==  0) && (right== 0) && (mRight== 0)){ // stop
    motorSpeed(0,0);
  } 
  

  // Printing sensor values
  /*
  Serial.print("Most Left: ");
  Serial.print(mLeft);
  Serial.print("  Left: ");
  Serial.print(left);
  Serial.print("  Middle: ");
  Serial.print(middle);
  Serial.print("  Right: ");
  Serial.print(right);
  Serial.print("  Most Right: ");
  Serial.println(mRight);
*/
  

  

  







  
}

