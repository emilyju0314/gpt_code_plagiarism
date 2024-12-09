void Adafruit_MPR121_mod::begin(uint8_t ecr) {
    // enable X electrodes and start MPR121
  writeRegister(MPR121_ECR, 0x0);  
  writeRegister(MPR121_ECR, ecr); 
}