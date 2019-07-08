#include <Stepper.h>

#define Temperature_Sensor A5
#define DC_Relay 7
#define PinLed 9
#define DC_Engine 5
#define Step_Engine 2
#define DC_Led 3
#define Step_Led 6
#define Step_IN1 10
#define Step_IN2 11
#define Step_IN3 12
#define Step_IN4 13

float TS_Read = LOW;
int Temp_State = LOW;
const int steps = 64;
Stepper sp(steps,Step_IN1,Step_IN2,Step_IN3,Step_IN4);

void setup() {
  Serial.begin(9600);
  
  //Sensor Pins
  pinMode(Temperature_Sensor, INPUT);
  pinMode(DC_Relay, OUTPUT);
  pinMode(PinLed, OUTPUT);
  pinMode(DC_Engine, OUTPUT);
  pinMode(Step_Engine, OUTPUT);
  pinMode(DC_Led, OUTPUT);
  pinMode(Step_Led, OUTPUT);
}

void loop() {
  digitalWrite(PinLed,HIGH);
  TS_Read = (float(analogRead(Temperature_Sensor))*5/(1023))/0.01;
  if (TS_Read > 30 ){
      TS_Read = TS_Read - 6;
  }
  Serial.print("Temperature = ");
  Serial.print(TS_Read);

  Serial.println(" ºC");
  //Sensor Control
  sp.setSpeed(500);
  if (TS_Read > 30) {
  digitalWrite(PinLed,LOW);
  digitalWrite(DC_Relay,HIGH);
  analogWrite(DC_Engine,255);
  digitalWrite(Step_Engine, HIGH);
  digitalWrite(DC_Led,HIGH);
  digitalWrite(Step_Led,HIGH);
  delay(2000);
  }
  else
  {
  digitalWrite(PinLed,HIGH);
  digitalWrite(DC_Relay,HIGH);
  analogWrite(DC_Engine,180);
  digitalWrite(Step_Engine, LOW);
  digitalWrite(DC_Led,LOW);
  digitalWrite(Step_Led,LOW);
  delay(2000);
  }
  
}

/*void motor(int vel, int sentido, int voltas, int tmp){
  sp.setSpeed(vel);//RPM
  for(int i=0;i<(32*voltas);i++){
    sp.step(steps*sentido);
  }
  delay(tmp);
}*/

void motor(int vel, int sentido, int voltas, int tmp, int passos){
  sp.setSpeed(vel);//RPM
  for(int i=0;i<(passos*voltas);i++){
    sp.step(steps*sentido);
    delay(tmp);
  }
  delay(tmp*2);
}

