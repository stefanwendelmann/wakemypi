#include <Arduino.h>

String s;

void setup() {
      Serial.begin(9600);
      pinMode(2, OUTPUT); // 4N35 RPi Reset
      pinMode(3, OUTPUT); // Singal LED
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      Serial.println("ON");
}

void wakeIn(){
  Serial.println("WAKE YOU IN = "+s.substring(7)+" ms");
  Serial.println("OK");
}

void loop() {
  if(Serial.available()>0){
    s = Serial.readString();
    if(s.substring(0,7) == "WAKEIN="){
      wakeIn();
    }
    //Serial.println(s);
  }
}
