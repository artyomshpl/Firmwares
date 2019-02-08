#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
Adafruit_BMP280 bmp; 

int MD= 7;
int AS= A0;

void setup() {
  Serial.begin(9600);
 pinMode(MD, INPUT);
 pinMode(AS, INPUT); 
}

void loop() {
 //Датчик движения HC-SR-501
 if(MoveDetector() == 1){
  Serial.println("Move!");
 }
 else{
  Serial.println("No move.");
 }

 //Датчик звука
 Serial.println(AudioSensor());

}
bool MoveDetector(){
  int valMD;

  valMD = digitalRead(MD);

  if(valMD == 1){
    return(1);
  }
  else{
    return(0);
  }
}

 int AudioSensor(){
  return(analogRead(AS));
 }
  


