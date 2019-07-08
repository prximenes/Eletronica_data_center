#define Temperature_Sensor A5
#define DC_Relay 7
#define PinLed 9

float TS_Read = LOW;
int Temp_State = LOW;

void setup() {
  Serial.begin(9600);
  
  //Sensor Pins
  pinMode(Temperature_Sensor, INPUT);
  pinMode(DC_Relay, OUTPUT);
  pinMode(PinLed, OUTPUT);

}

void loop() {
  digitalWrite(PinLed,HIGH);
  TS_Read = (float(analogRead(Temperature_Sensor))*5/(1023))/0.01;
  Serial.print("Temperature = ");
  Serial.print(TS_Read);
  Serial.println(" ºC");
  
  //Sensor Control
  if (TS_Read > 29.0) {
    Temp_State = LOW;
  }
  else if (TS_Read <= 29.0)
  {
    Temp_State = HIGH;
  }
  digitalWrite(PinLed,Temp_State);
  digitalWrite(DC_Relay,!Temp_State);
  delay(1000);
}
