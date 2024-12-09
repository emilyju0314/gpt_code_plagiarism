QString iTime::SecondString(int precision) const {
    ostringstream osec;
    osec.setf(ios::fixed);
    osec << setprecision(precision) << Second();
    QString sSeconds(osec.str().c_str());
    sSeconds = sSeconds.remove(QRegExp("(\\.0*|0*)$"));

    if(sSeconds.isEmpty()) sSeconds = "0";
    return sSeconds;
  }