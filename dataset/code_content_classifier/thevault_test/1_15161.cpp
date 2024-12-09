int daysInFollowingMonth(int year, int month)
{
  month +=1;
  if (month == 12)
  {
    year += 1;
    month -= 12;
  }
  static const int days[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int d = days[month];
  if (month == 1 && ((year % 100 != 0) ^ (year % 400 == 0)) && (year % 4 == 0)) // February of a leap year
    ++d;
  return d;
}