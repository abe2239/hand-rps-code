#include <Servo.h>

Servo myServo1;
Servo myServo2;
Servo myServo3;
Servo myServo4;
Servo myServo5;

const int flexPin1 = A0; //pin A0 to read analog input
const int flexPin2 = A1;
const int flexPin3 = A2;
const int flexPin4 = A3;
const int flexPin5 = A4;
int value1; //save analog value
int value2; //save analog value
int value3; //save analog value
int value4; //save analog value
int value5; //save analog value
int but = 2;
boolean Gamemode = false;
void setup(){
  
  Serial.begin(9600);       //Begin serial communication
  myServo1.attach(11);
  myServo2.attach(9);
  myServo3.attach(6);
  myServo4.attach(5);
  myServo5.attach(3);
   pinMode(but, INPUT);
   randomSeed(analogRead(0));
 pinMode(10, OUTPUT);
 pinMode(12, OUTPUT);
 pinMode(13, OUTPUT);
}

void loop(){

  //if(digitalRead(but)
Serial.print(digitalRead(but));
  
  if(digitalRead(but) == LOW){
  value1 = analogRead(flexPin1);         //Read and save analog value from potentiometer
  value1 = map(value1, 400, 670, 180, 0);
  myServo1.write(value1);
  Serial.print(value1);
  Serial.print(" ");

  value2 = analogRead(flexPin2);  //Read and save analog value from potentiometer
  value2 = map(value2, 460, 720, 170, 0);
  myServo2.write(value2);
  Serial.print(value2);
  Serial.print(" ");

  value3 = analogRead(flexPin3);         //Read and save analog value from potentiometer
  value3 = map(value3, 390, 630, 170, 0);
  myServo3.write(value3);
  Serial.print(value3);
  Serial.print(" ");

  value4 = analogRead(flexPin4);         //Read and save analog value from potentiometer
  value4 = map(value4, 340, 680, 170, 0);
  myServo4.write(value4);
  Serial.print(value4);
  Serial.print(" ");

  value5 = analogRead(flexPin5);         //Read and save analog value from potentiometer
  value5 = map(value5, 200, 450, 170, 0);
  myServo5.write(value5);
  Serial.print(value5);
  Serial.print(" ");
 
  Serial.println("");
  
  
  //Map value 0-1023 to 0-255 (PWM)
  //analogWrite(ledPin, value);          //Send PWM value to led
  delay(100);     
  }

  
  else if(digitalRead(but) == HIGH) {

long randNumber;


int userState;


if(value1 < 100 && value2 < 100 && value3 < 100 && value4 < 100 && value5 < 100){
  userState = 1;
  Serial.println("Paper");
}

else if(value1 > 100 && value2 < 100 && value3 < 100 && value4 > 100 && value5 > 100){
  userState = 2;
  Serial.println("Scissors");
}

else if(value1 > 100 && value2 > 100 && value3 > 100 && value4 > 100 && value5 > 100){
  userState = 3;
  Serial.println("Rock");
}
else {
  userState = 0;
}
//ice is myt fav
if(userState == 0){
  Serial.print("Unrecognized State");
 digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(13, LOW);
  digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(10, LOW);
  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(12, LOW);
  //Serial.print("Unrecognized State");
  }
randNumber = random(1, 4);

//if state is still zero
//light all leds
//ignore anything below (below is in an else)

if(randNumber == 1){
  myServo1.write(0) ;
  myServo2.write(0);
  myServo3.write(0);
  myServo4.write(0);
  myServo5.write(0);
  Serial.println("Paper");
  }

  else if(randNumber == 2){
  myServo1.write(170); 
  myServo2.write(0);
  myServo3.write(0);
  myServo4.write(170);
  myServo5.write(170);
  Serial.println("Scissor");
  }

else if(randNumber == 3){
  myServo1.write(170) ;
  myServo2.write(170);
  myServo3.write(170);
  myServo4.write(170);
  myServo5.write(170);
  Serial.println("Rock");
  }

  if((userState == 1 && randNumber == 1) || (userState == 2 && randNumber == 2) || (userState == 3 && randNumber == 3)){
     digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(10, LOW);
    
    }

  else if((userState == 1 && randNumber == 2) || (userState == 2 && randNumber == 3) || (userState == 3 && randNumber == 1)){
     digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(12, LOW);
    
    }

  else if((userState == 1 && randNumber == 3) || (userState == 3 && randNumber == 2) || (userState == 2 && randNumber == 1)){
     digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(13, LOW);
    
    }  
  delay(500);
  } 
}
   
   
    
