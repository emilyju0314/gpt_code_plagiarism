int iTime::Month() const {
    NaifStatus::CheckErrors();
    SpiceChar out[3];

    // Populate the private year member
    timout_c(p_et, "MM", 3, out);
    NaifStatus::CheckErrors();
    return IString(out).ToInteger();
  }