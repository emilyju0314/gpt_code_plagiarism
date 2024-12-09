void SR_map(unsigned char green, unsigned char red){
  for (char i=7; i>=0; i--){
    digitalWrite(SR_DATA, (red>>i)&1);
    SR_clock();
    digitalWrite(SR_DATA, (green>>i)&1);
    SR_clock();
  }
  SR_clock();
}