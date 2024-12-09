byte MMA8452Q::readRegister(MMA8452Q_Register reg)
{
	Wire.beginTransmission(address);
	Wire.write(reg);
	//endTransmission but keep the connection active
	if (Wire.endTransmission(false) == 0)
	{
        //Ask for 1 byte, once done, bus is released by default
    	if (Wire.requestFrom(address, 1) == 1)
    	    return Wire.read();
	}

    return 0;
}