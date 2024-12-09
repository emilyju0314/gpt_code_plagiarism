bool ValidateJavanese::ConsumeConsonantHeadIfValid() {
  const unsigned num_codes = codes_.size();
  // Consonant aksara
  do {
    CodeOnlyToOutput();
    // Special Sinhala case of [H Z Yayana/Rayana].
    int index = output_.size() - 3;
    if (output_used_ + 3 <= output_.size() &&
        (output_.back() == kPengkal || output_.back() == kCakra) && IsVirama(output_[index]) &&
        output_[index + 1] == kZeroWidthJoiner) {
      MultiCodePart(3);
    }
    bool have_nukta = false;
    if (codes_used_ < num_codes && codes_[codes_used_].first == CharClass::kNukta) {
      have_nukta = true;
      CodeOnlyToOutput();
    }
    // Test for subscript conjunct.
    index = output_.size() - 2 - have_nukta;
    if (output_used_ + 2 + have_nukta <= output_.size() && IsSubscriptScript() &&
        IsVirama(output_[index])) {
      // Output previous virama, consonant + optional nukta.
      MultiCodePart(2 + have_nukta);
    }
    IndicPair joiner(CharClass::kOther, 0);
    if (codes_used_ < num_codes && (codes_[codes_used_].second == kZeroWidthJoiner ||
                                    (codes_[codes_used_].second == kZeroWidthNonJoiner &&
                                     script_ == ViramaScript::kMalayalam))) {
      joiner = codes_[codes_used_];
      if (++codes_used_ == num_codes) {
        if (report_errors_) {
          tprintf("Skipping ending joiner: 0x%x 0x%x\n", output_.back(), joiner.second);
        }
        return true;
      }
      if (codes_[codes_used_].first == CharClass::kVirama) {
        output_.push_back(joiner.second);
      } else {
        if (report_errors_) {
          tprintf("Skipping unnecessary joiner: 0x%x 0x%x 0x%x\n", output_.back(), joiner.second,
                  codes_[codes_used_].second);
        }
        joiner = std::make_pair(CharClass::kOther, 0);
      }
    }
    if (codes_used_ < num_codes && codes_[codes_used_].first == CharClass::kVirama) {
      if (!ConsumeViramaIfValid(joiner, false)) {
        return false;
      }
    } else {
      break; // No virama, so the run of consonants is over.
    }
  } while (codes_used_ < num_codes && codes_[codes_used_].first == CharClass::kConsonant);
  if (output_used_ < output_.size()) {
    MultiCodePart(1);
  }
  return true;
}