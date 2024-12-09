double iTime::Second() const {
    NaifStatus::CheckErrors();
    SpiceChar out[256];

    // Populate the private year member
    timout_c(p_et, "SC.#######::RND", 256, out);
    NaifStatus::CheckErrors();
    return IString(out).ToDouble();
  }