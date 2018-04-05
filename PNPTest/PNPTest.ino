void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT); // LED
  pinMode(3, OUTPUT); // PNP Transistor 
  pinMode(4, OUTPUT); // Optokopller 4N35
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  Serial.println("ON");
  
}

void loop() {
  // RESET RPi 
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  delay(2000);
  // Let RPi GO
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  delay(20000);
}
