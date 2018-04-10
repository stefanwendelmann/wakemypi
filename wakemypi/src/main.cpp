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

bool isValidWakeDelay(String str){
  for(unsigned int i = 0; i<str.length();i++){
    if(!isDigit(str.charAt(i))){
      return false;
    }
  }
  return true;
}

void wakeIn(){
  Serial.println("WAKE YOU IN = "+s.substring(7)+" ms");
  if(!isValidWakeDelay(s.substring(7))){
    Serial.println("ERROR: "+s.substring(7)+" IS NOT A VALID WAKE UP DELAY!");
    return;
  }

  long d = s.substring(7).toInt();
  Serial.println("OK");
  delay(d);
  Serial.println("HEYWAKEUP!");
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  delay(2000);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  Serial.println("WAKEUPDONE");
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
