static void my_timegm(struct my_tm *tm, time_t *t)
{
  static const int month_days_cumulative [12] =
    { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
  int month_, year, leap_days;

  year = tm->tm_year;
  month_ = tm->tm_mon;
  if(month_ < 0) {
    year += (11 - month_) / 12;
    month_ = 11 - (11 - month_) % 12;
  }
  else if(month_ >= 12) {
    year -= month_ / 12;
    month_ = month_ % 12;
  }

  leap_days = year - (tm->tm_mon <= 1);
  leap_days = ((leap_days / 4) - (leap_days / 100) + (leap_days / 400)
               - (1969 / 4) + (1969 / 100) - (1969 / 400));

  *t = ((((time_t) (year - 1970) * 365
          + leap_days + month_days_cumulative[month_] + tm->tm_mday - 1) * 24
         + tm->tm_hour) * 60 + tm->tm_min) * 60 + tm->tm_sec;
}