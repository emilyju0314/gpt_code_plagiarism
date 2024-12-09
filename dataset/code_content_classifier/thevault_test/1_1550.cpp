QString iTime::UTC(int precision) const {
    QString utc = YearString() + "-" ;
    if(Month() < 10) utc += "0" + MonthString() + "-";
    else utc += MonthString() + "-";

    if(Day() < 10) utc += "0" + DayString() + "T";
    else utc += DayString() + "T";

    if(Hour() < 10) utc += "0" + HourString() + ":";
    else utc += HourString() + ":";

    if(Minute() < 10) utc += "0" + MinuteString() + ":";
    else utc += MinuteString() + ":";

    if(Second() < 10) utc += "0" + SecondString(precision);
    else utc += SecondString(precision);
    
    return utc;
  }