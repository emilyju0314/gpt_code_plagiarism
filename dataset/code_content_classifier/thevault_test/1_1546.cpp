int iTime::Minute() const {
    NaifStatus::CheckErrors();
    SpiceChar out[3];

    // Populate the private year member
    timout_c(p_et, "MN", 3, out);
    NaifStatus::CheckErrors();
    return IString(out).ToInteger();
  }