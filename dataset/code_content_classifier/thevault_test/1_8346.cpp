void Adafruit_MPR121_mod::open(uint8_t i2caddr, TwoWire *theWire) 
{
  _i2caddr = i2caddr;
  _wire = theWire;

  _wire->begin();  
}