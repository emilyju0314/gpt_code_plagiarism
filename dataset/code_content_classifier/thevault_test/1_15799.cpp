void activateBrakeLights(bool brake){
  if(brake){
    digitalWrite(brakes, HIGH); 
  }
    else digitalWrite(brakes, LOW); 
}