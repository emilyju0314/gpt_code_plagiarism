uint16_t PWMeter::get()
{
	uint16_t ret;
	
	byte sreg = SREG;			// backup the status register
	cli();						// disable interrupts
	
	if(rptr != wptr){
		ret = buffer[rptr];
		if(++rptr >= PWMETER_BUFF_SIZE) rptr = 0;
	}else{
		ret = 0xFFFF;
	}
	
	//sei();					// enable interrupts
	SREG = sreg;				// restore the status register
	
	// CPU clock = 16MHz or 8MHz?
	if(F_CPU == 16000000UL){
		if(ret != 0xFFFF) ret /= 2; // 0.5usec count => 1usec count
	}
	
	return ret;
}