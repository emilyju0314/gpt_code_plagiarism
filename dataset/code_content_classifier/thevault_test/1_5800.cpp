byte MMA8452Q::begin(MMA8452Q_Scale fsr, MMA8452Q_ODR odr)
{
	scale = fsr; // Haul fsr into our class variable, scale

	Wire.begin(); // Initialize I2C

	byte c = readRegister(WHO_AM_I);  // Read WHO_AM_I register

	if (c != 0x2A) // WHO_AM_I should always be 0x2A
	{
		return 0;
	}

	standby();  // Must be in standby to change registers

	setScale(scale);  // Set up accelerometer scale
	setODR(odr);  // Set up output data rate
	setupPL();  // Set up portrait/landscape detection
	// Multiply parameter by 0.0625g to calculate threshold.
	//setupTap(0x02, 0x02, 0x02); // Disable x, y, set z to 0.5g

	active();  // Set to active to start reading

	return 1;
}