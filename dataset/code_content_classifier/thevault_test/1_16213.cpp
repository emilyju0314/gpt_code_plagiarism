time_t convert_to_timestamp(int day, int month, int year, int hour, int minute, int seconde){
  tm time;
  time.tm_year = year - 1900;
  time.tm_mon = month - 1;
  time.tm_mday = day;
  time.tm_hour = hour;
  time.tm_min = minute;
  time.tm_sec = seconde;
  return timegm(&time);
}