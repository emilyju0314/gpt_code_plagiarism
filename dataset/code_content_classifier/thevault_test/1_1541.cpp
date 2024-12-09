void iTime::operator=(const QString &time) {
    LoadLeapSecondKernel();

    NaifStatus::CheckErrors();
    // Convert the time string to a double ephemeris time
    SpiceDouble et;
    str2et_c(time.toLatin1().data(), &et);

    p_et = et;
    NaifStatus::CheckErrors();
  }