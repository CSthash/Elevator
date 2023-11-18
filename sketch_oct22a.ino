#include <Stepper.h>

#define STEPS 2038

Stepper stepper(STEPS, 3, 5, 4, 6);

int floor1;
int floor2;
int floor3;
int floor4;

int hi = 1;

bool f1 = true;
bool f2 = false;
bool f3 = false;
bool f4 = false;

void setup() {
Serial.begin(9600);
 pinMode(2, INPUT);
 pinMode(7, INPUT);
 pinMode(8, INPUT);
 pinMode(9, INPUT);
 pinMode(A2, OUTPUT);
pinMode(A4, OUTPUT);
pinMode(A3, OUTPUT);
pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
 

}


void loop() {
floor1 = digitalRead(7);
floor2 = digitalRead(2);
floor3 = digitalRead(8);
floor4 = digitalRead(9);

if(f1 == true){
digitalWrite(10, HIGH);
digitalWrite(A2, HIGH);
digitalWrite(A4, HIGH);
digitalWrite(A3, HIGH);
digitalWrite(13, HIGH);
digitalWrite(12, HIGH);
}


if(floor2 == 1 && f1 == true){

Serial.print("f2");
  stepper.setSpeed(14);
  stepper.step(5500);
digitalWrite(10, LOW);
digitalWrite(A2, LOW);
digitalWrite(A4, LOW);
digitalWrite(A3, LOW);
digitalWrite(13, LOW);
digitalWrite(12, LOW);
digitalWrite(10, HIGH);
digitalWrite(A2, HIGH); 


f2 = true;
f1 = false;
  
}

if(floor3 == 1 && f1 == true){
f3 = true;
f1 = false;
  stepper.setSpeed(14);
  stepper.step(5500);
 digitalWrite(10, LOW);
digitalWrite(A2, LOW);
digitalWrite(A4, LOW);
digitalWrite(A3, LOW);
digitalWrite(13, LOW);
digitalWrite(12, LOW); 
digitalWrite(10, HIGH);
digitalWrite(A2, HIGH);

 stepper.step(5500);

 digitalWrite(10, LOW);
digitalWrite(A2, LOW); 

digitalWrite(10, HIGH);
digitalWrite(12, HIGH);
digitalWrite(11, HIGH);
digitalWrite(A3, HIGH);
digitalWrite(A4, HIGH);
Serial.print("f3");
}

if(floor4 == 1 && f1 == true){
Serial.print("f4");
f4 = true;
f1 = false;
}

if(floor3 == 1 && f2 == true){
  f2 = false;
  f3 = true;
  stepper.setSpeed(14);
  stepper.step(5500);
  Serial.print("kk");
digitalWrite(10, LOW);
digitalWrite(A2, LOW); 
digitalWrite(10, HIGH);
digitalWrite(12, HIGH);
digitalWrite(11, HIGH);
digitalWrite(A3, HIGH);
digitalWrite(A4, HIGH);


}

if(floor4 == HIGH && f2 == true){
  f2 = false;
  f4 = true;
}

if(floor4 == HIGH && f3 == true){
  f3 = false;
  f4 = true;
}

if(floor3 == HIGH && f4 == true){
  f4 = false;
  f3 = true;
}

if(floor2 == HIGH && f4 == true){
  f4 = false;
  f2 = true;
  Serial.print("tt");
}

if(floor1 == HIGH && f4 == true){
  f4 = false;
  f1 = true;
  Serial.print("h");
}

if(floor2 == HIGH && f3 == true){
  f3 = false;
  f2 = true;
  stepper.setSpeed(13);
  stepper.step(-5500);
 digitalWrite(10, LOW);
digitalWrite(12, LOW);
digitalWrite(11, LOW);
digitalWrite(A3, LOW);
digitalWrite(A4, LOW);  
digitalWrite(10, HIGH);
digitalWrite(A2, HIGH); 


}

if(floor1 == HIGH && f3 == true){
  f3 = false;
  f1 = true;
  stepper.setSpeed(13);
  stepper.step(-5500);
 
digitalWrite(10, LOW);
digitalWrite(12, LOW);
digitalWrite(11, LOW);
digitalWrite(A3, LOW);
digitalWrite(A4, LOW); 
digitalWrite(10, HIGH);
digitalWrite(A2, HIGH); 
  stepper.step(-5500);
digitalWrite(10, LOW);
digitalWrite(A2, LOW); 
digitalWrite(10, HIGH);
digitalWrite(A2, HIGH);
digitalWrite(A4, HIGH);
digitalWrite(A3, HIGH);
digitalWrite(13, HIGH);
digitalWrite(12, HIGH);


}

if(floor1 == HIGH && f2 == true){
  f2 = false;
  f1 = true;
  stepper.setSpeed(13);
  stepper.step(-5500);
digitalWrite(10, LOW);
digitalWrite(A2, LOW); 
digitalWrite(10, HIGH);
digitalWrite(A2, HIGH);
digitalWrite(A4, HIGH);
digitalWrite(A3, HIGH);
digitalWrite(13, HIGH);
digitalWrite(12, HIGH);

}

}
