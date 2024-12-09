void	LowPowerClass::adcNoiseReduction(period_t period, adc_t adc, 
										 timer2_t timer2)
{
	// Temporary clock source variable 
	unsigned char clockSource = 0;
	
	#if !defined(__AVR_ATmega32U4__)
	if (timer2 == TIMER2_OFF)
	{
		if (TCCR2B & CS22) clockSource |= (1 << CS22);
		if (TCCR2B & CS21) clockSource |= (1 << CS21);
		if (TCCR2B & CS20) clockSource |= (1 << CS20);
	
		// Remove the clock source to shutdown Timer2
		TCCR2B &= ~(1 << CS22);
		TCCR2B &= ~(1 << CS21);
		TCCR2B &= ~(1 << CS20);
	}
	#endif
	
	if (adc == ADC_OFF)	ADCSRA &= ~(1 << ADEN);
	
	if (period != SLEEP_FOREVER)
	{
		wdt_enable(period);
		WDTCSR |= (1 << WDIE);	
	}
	
	lowPowerBodOn(SLEEP_MODE_ADC);
	
	if (adc == ADC_OFF) ADCSRA |= (1 << ADEN);
	
	#if !defined(__AVR_ATmega32U4__)
	if (timer2 == TIMER2_OFF)
	{
		if (clockSource & CS22) TCCR2B |= (1 << CS22);
		if (clockSource & CS21) TCCR2B |= (1 << CS21);
		if (clockSource & CS20) TCCR2B |= (1 << CS20);
		
	}
	#endif
}