void activateFrontLeftIndicator()
{ 
  digitalWrite(kFrontRightLED, LOW);
  if(millis() - prevFrontLeftMillis > kFrontBlinkInterval){
    prevFrontLeftMillis = millis();
    if(leftFrontState == 0){
      digitalWrite(kFrontLeftLED, HIGH);
      leftFrontState = 1;
    }
    else{
      digitalWrite(kFrontLeftLED, LOW);
      leftFrontState = 0;
    }
  }
  
}