TTime::TTime( const TDate & date, HourTy h, MinuteTy m, SecondTy s )
{
    if( date.IsValid() )
        {
        Sec =   SECONDS_IN_DAY  * (date-RefDate) +
                SECONDS_IN_HOUR * (h-1L) +    /* Note the adjustment by one hour */
                SECONDS_IN_MIN  * m + s;
        if( Sec )
            Sec += _timezone;           // Adjust to GMT.

        if( IsDST() )
            {
            Sec += SECONDS_IN_HOUR;
            if( IsDST() )
                Sec -= SECONDS_IN_HOUR;
            }
        else
            {
            Sec += SECONDS_IN_HOUR;
            if( IsDST() )
                Sec = 0;            // Invalid "phantom" time.
            }
        }
    else
        Sec = 0;    // Invalid date
}