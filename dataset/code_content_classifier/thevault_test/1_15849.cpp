TTime TTime::BuildLocal( const TDate & date, HourTy h )
{
    return TTime( SECONDS_IN_DAY * (date-RefDate) +
                  SECONDS_IN_HOUR * h +
                  _timezone);
}