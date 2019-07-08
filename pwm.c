#define Temperature_Sensor A5
#define DC_Relay 7
#define PinLed 9
#define DC_Engine 5

float TS_Read = LOW;
int Temp_State = LOW;

void setup() {
  Serial.begin(9600);
  
  //Sensor Pins
  pinMode(Temperature_Sensor, INPUT);
  pinMode(DC_Relay, OUTPUT);
  pinMode(PinLed, OUTPUT);
  pinMode(DC_Engine, OUTPUT);

}

void loop() {
  digitalWrite(PinLed,HIGH);
  TS_Read = (float(analogRead(Temperature_Sensor))*5/(1023))/0.01;
  if (TS_Read > 30 ){
      TS_Read = TS_Read - 4;
  }
  Serial.print("Temperature = ");
  Serial.print(TS_Read);

  Serial.println(" ºC");
  
  //Sensor Control
  if (TS_Read > 30) {
  digitalWrite(PinLed,LOW);
  digitalWrite(DC_Relay,HIGH);
  analogWrite(DC_Engine,255);
  }
  else
  {
  digitalWrite(PinLed,HIGH);
  digitalWrite(DC_Relay,HIGH);
  analogWrite(DC_Engine,180);
  }
  delay(1000);
}
