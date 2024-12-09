void	LowPowerClass::powerDown(period_t period, adc_t adc, bod_t bod)
{
	if (adc == ADC_OFF)	ADCSRA &= ~(1 << ADEN);
	
	if (period != SLEEP_FOREVER)
	{
		wdt_enable(period);
		WDTCSR |= (1 << WDIE);	
	}
	if (bod == BOD_OFF)	
	{
		#if defined (__AVR_ATmega328P__) || defined (__AVR_ATmega168P__)
			lowPowerBodOff(SLEEP_MODE_PWR_DOWN);
		#else
			lowPowerBodOn(SLEEP_MODE_PWR_DOWN);
		#endif
	}
	else	
	{
		lowPowerBodOn(SLEEP_MODE_PWR_DOWN);
	}
	
	if (adc == ADC_OFF) ADCSRA |= (1 << ADEN);
}