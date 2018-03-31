void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  Serial.println("ON");
}

String s;

void loop() {
  if(Serial.available()>0){
    s = Serial.readString();
    if(s.substring(0,5) == "TIME="){
      setTime();
    }else if(s.substring(0,7) == "WAKEIN="){
      wakeIn();
    }
    //Serial.println(s);
  }
}

void setTime(){
  Serial.println("TIME SET TO = "+s.substring(5));
  Serial.println("OK");
}

void wakeIn(){
  Serial.println("WAKE YOU IN = "+s.substring(7)+" ms");
  Serial.println("OK");
}

