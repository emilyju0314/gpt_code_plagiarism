void user_loop(void) {
  nunchuck1.readData();    // Read inputs and update maps
  
  int joyX = nunchuck1.getJoyX();
  int joyY = nunchuck1.getJoyY();
//  Serial.println("joyXY(" + String(joyX) + ", " + String(joyY) + ")");
  float x = map2(joyX, low, high, -1.0, 1.0);
  float y = map2(joyY, low, high, -1.0, 1.0);
  int cornerX = (joyX - low) / divFactor;
  int cornerY = (joyY - low) / divFactor;
  int chaseColor = 0;
  if(cornerX == 1 && cornerY == 1) { // return to normal when the joystick is in the middle
    eyesNormal();
    neoPixelState = LUMINESCENT;
  } else {
    eyesToCorner(x, -y, true);
    if(cornerX < 1) {
      chaseColor = green;
      neoPixelState = CHASE_LEFT;
    } else if(cornerX > 1) {
      chaseColor = blue;
      neoPixelState = CHASE_RIGHT;
    } else if(cornerY > 1) {
      neoPixelState = CHASE_UP;
      chaseColor = green;
    } else if(cornerY < 1) {
      neoPixelState = CHASE_DOWN;
      chaseColor = blue;
    }
  }
  
  bool buttonC = nunchuck1.getButtonC();
  bool buttonZ = nunchuck1.getButtonZ();

  if(buttonC && buttonZ) {
    Serial.println("buttonC & buttonZ");
    chaseColor = red;
    if(neoPixelState == LUMINESCENT)
      neoPixelState = CHASE_UP;
  } else {
    if(buttonC) {
      Serial.println("buttonC");
      eyesWide();
      neoPixelState = SPARKLE;
    } else if(buttonZ) {
      Serial.println("buttonZ");
      eyesClose();
    }
  }

  if(strip.numPixels() > 0) {
    // Serial.println("neo state=" + String(neoPixelState));
    switch (neoPixelState) {
      case LUMINESCENT: neoShine(); break;
      case CHASE_RIGHT: neoChase(4, 3, chaseColor); break;
      case CHASE_LEFT: neoChase(2, 3,  chaseColor); break;
      case CHASE_UP: neoUpDown(chaseColor, 1); break;
      case CHASE_DOWN: neoUpDown(chaseColor, -1); break;
      case SPARKLE: neoSparkle(); break;
    }
  }
}