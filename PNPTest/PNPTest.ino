void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  Serial.println("ON");
  
}

void loop() {
  // RESET RPi 
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  delay(2000);
  // Let RPi GO
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  delay(20000);
}
