void ADC_init()
{
    ADMUX = (0<<REFS1)|(1<<REFS0)|(0<<ADLAR)|(0<<MUX3)|(0<<MUX2)|(0<<MUX1)|
            (0<<MUX0);
    // Select Analog Port 0 and Internal Reference Voltage;
    ADCSRA = (1<<ADEN)|(1<<ADIE)|(1<<ADPS2)|(0<<ADPS1)|(0<<ADPS0);
    // Enable A/D, Enable Interrupt, Set A/D Prescalar
    DIDR0 = (1<<ADC0D) | (1<<ADC1D);
    // Disable Input Buffers
}