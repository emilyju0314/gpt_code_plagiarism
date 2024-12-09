int iTime::Year() const {
    NaifStatus::CheckErrors();
    SpiceChar out[5];

    // Populate the private year member
    timout_c(p_et, "YYYY", 5, out);
    NaifStatus::CheckErrors();
    return IString(out).ToInteger();
  }