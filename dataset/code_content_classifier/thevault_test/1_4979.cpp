void Srf08::ping(){
    // write command to read in CM
    Wire.beginTransmission(SRF_ADDR+_device);
    Wire.write(SRF_COMMAND);
    Wire.write(SRF_CMD_CM);
    Wire.endTransmission();
}