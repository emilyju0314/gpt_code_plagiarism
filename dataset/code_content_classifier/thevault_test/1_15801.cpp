void activateHeadLights(bool lights){
  if(lights){
    digitalWrite(headLight, HIGH); 
  }
    else digitalWrite(headLight, LOW); 
}