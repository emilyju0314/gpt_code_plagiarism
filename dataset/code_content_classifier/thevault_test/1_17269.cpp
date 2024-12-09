uint16_t PWMeter::getLast()
{
	uint16_t ret;
	
	byte sreg = SREG;			// backup the status register
	cli();						// disable interrupts
	
	if(rptr != wptr){
		rptr = (wptr > 0) ? (wptr - 1) : (PWMETER_BUFF_SIZE - 1);
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