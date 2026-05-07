#include <Pixy2.h>
#include <Stepper.h>

int MotorPin = 10;

int LeftSensorA = A0;
int LeftSensorB = A1;
int LeftSensorC = A2;


int RightSensorA = A3;
int RightSensorB = A4;
int RightSensorC = A5;


//Pixy setup
Pixy2 pixy;

//Stepper Setup
const int Steps = 10;
Stepper stepper(Steps, 8, 9, 10, 11);


void setup()
{
  Serial.begin(115200);
  Serial.print("Starting...\n");
  pixy.init();


  //Motor setup
  pinMode(MotorPin, OUTPUT);
 
  //IR Sensor setup
  pinMode(LeftSensorA,INPUT);
  pinMode(LeftSensorB,INPUT);
  pinMode(LeftSensorC,INPUT);


  pinMode(RightSensorA,INPUT);
  pinMode(RightSensorB,INPUT);
  pinMode(RightSensorC,INPUT);
}


void loop()
{
  Stop(MotorPin);  
  IRSensors();
}


void Stop(int MotorPin) {
//Keep going until an object is detected


pixy.ccc.getBlocks();


 for (int i=0; i<pixy.ccc.numBlocks; i++) {
    if (pixy.ccc.blocks[i].m_signature == 1) {
        Serial.print("Red light detected ");
        digitalWrite(MotorPin, LOW);
    }
    else if (pixy.ccc.blocks[i].m_signature == 2){
        Serial.print("Yellow light detected ");
        digitalWrite(MotorPin, LOW);
    }
    else if (pixy.ccc.blocks[i].m_signature == 3){
        Serial.print("Green light detected ");
        digitalWrite(MotorPin, HIGH);
    }
    else{
        Serial.print("No light detected ");
        digitalWrite(MotorPin, HIGH);
    }
 }
}


void IRSensors() {


int right_statusA = analogRead(RightSensorA);
int right_statusB = analogRead(RightSensorB);
int right_statusC = analogRead(RightSensorC);


int left_statusA = analogRead(LeftSensorA);
int left_statusB = analogRead(LeftSensorB);
int left_statusC = analogRead(LeftSensorC);




//IR sensors A
//HEEEEEELP!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  if (left_statusA < 500) {
    stepper.step(1);
  }
  else if (left_statusA > 500) {
    stepper.step(-1);
  }


//IR sensors B
  if (left_statusB < 500) {
    stepper.step(1);
  }
  else if (left_statusB > 500) {
    stepper.step(-1);
  }


//IR sensors C
  if (left_statusC < 500) {
    stepper.step(1);
  }
  else if (left_statusC > 500) {
    stepper.step(-1)
  }


}



