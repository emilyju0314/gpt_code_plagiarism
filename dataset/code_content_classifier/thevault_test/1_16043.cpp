void UpdateSoilMoist(float* MoistMode, char* ASCII)
{
    ADMUX = (0<<REFS1)|(1<<REFS0)|(0<<ADLAR)|(0<<MUX3)|(0<<MUX2)|(0<<MUX1)|
            (1<<MUX0) ;
    // Select Analog Port 1 and Internal Reference Voltage;

    uint8_t i ;
    uint16_t DataH ;
    uint16_t DataL ;
    float Voltage ;                      // Voltage for piecewise approximation
    float RawValues[10] ;                // Samples for mode function

    uint8_t Counts[10] ;                 // Occurrence of each value in RawData
    uint8_t MaxCount ;                   // Address of the highest count

    // Take 10 measurements
    for (i = 0 ; i<10 ; i++)
    {
        ADCSRA |= (1<<ADSC) ;            // Begin ADC conversion on Channel 0
        while( ADCSRA & (1<<ADSC)) ;     // Wait for ADC conversion to complete

        DataL = ADCL ;
        DataH = ADCH << 8 ;
        DataH = DataH + DataL ;

        Voltage = DataH ;                // Cast to Float
        Voltage = (Voltage / 1024) * 5 ; // Convert to Voltage

        // Piecewise approximation for Voltage -> VWC from VH400 Datasheet
        if (Voltage < 1.1)            RawValues[i] = (10 * Voltage) - 1 ;
        else if (Voltage < 1.3)        RawValues[i] = (25 * Voltage) - 17.5 ;
        else if (Voltage < 1.8)        RawValues[i] = (48.08 * Voltage) - 47.5 ;
        else if (Voltage < 2.2)        RawValues[i] = (26.32 * Voltage) - 7.89 ;
        else                        RawValues[i] = (62.5 * Voltage) - 7.89 ;
    }

    // Begin finding mode of the measured data

    qsort(RawValues, 10, sizeof(float), CompareFloat) ;// Sorts ascendingly

    // Count occurrence of each value
    Counts[0] = 1 ;
    for (i = 1 ; i<10 ; i++)
    {
        if ( RawValues[i] == RawValues[i-1] )
        {
            Counts[i] = Counts[i-1] + 1 ;
        }
        else
        {
            Counts[i] = 1 ;
        }
    }

    // Finds the largest count
    MaxCount = 0 ;
    for (i = 1 ; i<10 ; i++)
    {
        if ( Counts[i] > Counts[MaxCount] ) MaxCount = i ;
    }

    *MoistMode = RawValues[MaxCount] ;
    dtostrf( RawValues[MaxCount], 6, 2, ASCII) ;
}