TTime::TTime()
{
  time_t ltime;
  time(&ltime);
  struct tm *t = localtime(&ltime);

  // Construct the date.  The time struct returns int, so casts are used.
  //
  TDate today( (DayTy)t->tm_mday,
               (MonthTy)(t->tm_mon + 1),
               (YearTy)t->tm_year + 1900 );

  *this = TTime( today,
                 (HourTy)t->tm_hour,
                 (MinuteTy)t->tm_min,
                 (SecondTy)t->tm_sec );
}