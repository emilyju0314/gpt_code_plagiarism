int iTime::Hour() const {
    NaifStatus::CheckErrors();
    SpiceChar out[3];

    // Populate the private year member
    timout_c(p_et, "HR", 3, out);
    NaifStatus::CheckErrors();
    return IString(out).ToInteger();
  }