void loop() {
  // The core of your code will likely live here.
  matrix.clear();
  dx=fmap(analogRead(JoyStick_X), ADC_MIN, ADC_MAX, -1, 1);
  dy=fmap(analogRead(JoyStick_Y), ADC_MIN, ADC_MAX, -1, 1);
  z=digitalRead(JoyStick_Z);
  if(x + dx >= 0 && x + dx < 8) {
    x += dx;
  }
  if(y + dy >= 0 && y + dy < 8) {
    y += dy;
  }
  matrix.drawPixel(x,y, LED_ON);
	matrix.writeDisplay();
  Serial.print(x);
  Serial.print('-');
  Serial.print(y);
  Serial.println();
  delay(100);
}