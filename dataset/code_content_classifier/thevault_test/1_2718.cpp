unsigned char AB::readVel(byte i){
  //Read the velocity of analog key i
  //i is the key index (0~6), not the analog input's address
  //returns a pressure level between 0 (not pressed) and 126.
  const float thres=0.01;
  unsigned int r = analogRead(AB_cal[i][0]);
  if (r>1018){
    return 0;
  }
  else {
    return min((1018-r)/4,126);
  }
}