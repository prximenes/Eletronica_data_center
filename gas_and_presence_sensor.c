#define Presence_Sensor 4
#define Temperature_Sensor A5
#define Gas_Sensor A0

#define Presence_Sensor_Led 7
#define Gas_Sensor_Led 8

#define Most_Bit 9
#define Middle_Bit 10
#define Least_Bit 11

int PS_Read = LOW;
float GS_Read, TS_Read;
int temp;
void setup() {
  Serial.begin(9600);
  
  //Sensor Pins
  pinMode(Presence_Sensor, INPUT);
  pinMode(Gas_Sensor, INPUT);
  pinMode(Temperature_Sensor, INPUT);

  //Buffer Leds
  pinMode(Presence_Sensor_Led, OUTPUT);
  pinMode(Gas_Sensor_Led, OUTPUT);
  pinMode(Most_Bit, OUTPUT);
  pinMode(Middle_Bit, OUTPUT);
  pinMode(Least_Bit, OUTPUT);

}

void loop() {
  

  PS_Read = digitalRead(Presence_Sensor);
  GS_Read = analogRead(Gas_Sensor);
  TS_Read = (float(analogRead(Temperature_Sensor))*5/(1023))/0.01;
  Serial.print("Presence = ");
  Serial.println(PS_Read);
  Serial.print("Gas Detector = ");
  Serial.println(GS_Read);
 // Serial.print("Temperature = ");
  //Serial.print(TS_Read);
//  Serial.println(" ºC");
  
  //Sensor Control
  if (GS_Read > 850) {
    digitalWrite(Presence_Sensor_Led,PS_Read);
    digitalWrite(Most_Bit,LOW);
    digitalWrite(Middle_Bit,HIGH);
    digitalWrite(Least_Bit,LOW);
    digitalWrite(Gas_Sensor_Led,HIGH);
    delay(1000);
    digitalWrite(Presence_Sensor_Led,PS_Read);
    digitalWrite(Most_Bit,LOW);
    digitalWrite(Middle_Bit,HIGH);
    digitalWrite(Least_Bit,HIGH);
    digitalWrite(Gas_Sensor_Led,HIGH);
    delay(1000);
    digitalWrite(Presence_Sensor_Led,PS_Read);
    digitalWrite(Most_Bit,HIGH);
    digitalWrite(Middle_Bit,HIGH);
    digitalWrite(Least_Bit,HIGH);
    digitalWrite(Gas_Sensor_Led,HIGH);
    delay(1000);
  }
  else
  {
    digitalWrite(Presence_Sensor_Led,PS_Read);
    digitalWrite(Most_Bit,LOW);
    digitalWrite(Middle_Bit,LOW);
    digitalWrite(Least_Bit,LOW);
    digitalWrite(Gas_Sensor_Led,LOW);
  }
  delay(1000);
}
