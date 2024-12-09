void forward(){
  analogWrite(ENA, ABS);      // PWM (pulse-width modulated) enable lines
  analogWrite(ENB, ABS);      // makes it go less than full speed (by a factor of ABS/127)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("go forward!");
}