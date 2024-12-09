void MMA8452Q::setupTap(byte xThs, byte yThs, byte zThs, byte timeLimit, byte latency, byte window)
{
    standby();
	// Set up single, for more info check out this app note:
	// http://cache.freescale.com/files/sensors/doc/app_note/AN4072.pdf
	// Set the threshold - minimum required acceleration to cause a tap.
	byte temp = 0;
	if (!(xThs & 0x80)) // If top bit ISN'T set
	{
		//temp |= 0x3; // Enable taps on x
		temp |= 0x1; // Enable single-tap on x
		writeRegister(PULSE_THSX, xThs);  // x thresh
	}
	if (!(yThs & 0x80))
	{
		//temp |= 0xC; // Enable taps on y
		temp |= 0x4; // Enable single-tap on y
		writeRegister(PULSE_THSY, yThs);  // y thresh
	}
	if (!(zThs & 0x80))
	{
	    //temp |= 0x30; // Enable taps on z
	    temp |= 0x10; // Enable single-tap on z
		writeRegister(PULSE_THSZ, zThs);  // z thresh
	}
	// Set up single and/or double tap detection on each axis individually.
	writeRegister(PULSE_CFG, temp | 0x40);
	// Set the time limit - the maximum time that a tap can be above the thresh
	//writeRegister(PULSE_TMLT, 0x30);  // 30ms time limit at 800Hz odr
	writeRegister(PULSE_TMLT, timeLimit);  // 30ms time limit at 800Hz odr
	// Set the pulse latency - the minimum required time between pulses
	writeRegister(PULSE_LTCY, latency);  // 200ms (at 800Hz odr) between taps min
	//writeRegister(PULSE_LTCY, 0x40);  // 200ms (at 800Hz odr) between taps min
	// Set the second pulse window - maximum allowed time between end of
	//	latency and start of second pulse
	writeRegister(PULSE_WIND, window);  // 5. 318ms (max value) between taps max

	active();
}