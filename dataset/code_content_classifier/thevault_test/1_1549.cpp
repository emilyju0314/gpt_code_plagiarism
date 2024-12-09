int iTime::DayOfYear() const {
    NaifStatus::CheckErrors();
    SpiceChar out[4];

    // Populate the private year member
    timout_c(p_et, "DOY", 4, out);
    NaifStatus::CheckErrors();
    return IString(out).ToInteger();
  }