void UpdateSoilTemp(float* TempMode, char* ASCII)
{
    ADMUX = (0<<REFS1)|(1<<REFS0)|(0<<ADLAR)|(0<<MUX3)|(0<<MUX2)|(0<<MUX1)|
            (0<<MUX0);   // Select Analog Port 0 and Internal Reference Voltage

    uint8_t i ;                         // for loop counter
    uint16_t DataH ;                    // ADC High Bits
    uint16_t DataL ;                    // ADC Low Bits
    float DataFloat ;                   // Needed for int -> float cast
    float RawValues[10] ;               // Samples for mode function

    uint8_t Counts[10] ;                // Occurrence of each value in RawData
    uint8_t MaxCount ;                  // Array location of the highest count

    // Take 10 measurements
    for (i = 0 ; i<10 ; i++)
    {
        ADCSRA |= (1<<ADSC) ;           // Begin ADC conversion on Channel 0
        while( ADCSRA & (1<<ADSC)) ;    // Wait for ADC conversion to complete

        DataL = ADCL ;
        DataH = ADCH << 8 ;
        DataH = DataH + DataL ;

        DataFloat = DataH ;             // Cast to Float
        RawValues[i] = ( ( (DataFloat / 1024)  *5 ) * 75.006 ) - 40 ;
                                        // Equation from THERM200 Datasheet
    }

    // Begin finding mode of the measured data

    qsort(RawValues, 10, sizeof(float), CompareFloat) ; // Ascending sort
    // Count occurrence of each value
    Counts[0] = 1 ;                                     // Count the first value
    for (i = 1 ; i<10 ; i++)                            // Count the rest
    {
        if ( RawValues[i] == RawValues[i-1] )
        {
            Counts[i] = Counts[i-1] + 1 ;
        }
        else
        {
            Counts[i] = 1 ;								// restart the count
        }
    }

    // Finds the largest count
    MaxCount = 0 ;                                      // Count the first value
    for (i = 1 ; i<10 ; i++)                            // Count the rest
    {
        if ( Counts[i] > Counts[MaxCount] ) MaxCount = i ;
        // Update the MaxCount as necessary
    }

    *TempMode = RawValues[MaxCount] ;
    dtostrf( RawValues[MaxCount], 6, 2, ASCII) ;
}