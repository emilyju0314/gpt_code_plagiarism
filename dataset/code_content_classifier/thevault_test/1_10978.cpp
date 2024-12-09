bool WERD_RES::AlternativeChoiceAdjustmentsWorseThan(float threshold) const {
  // The choices are not changed by this iteration.
  WERD_CHOICE_IT wc_it(const_cast<WERD_CHOICE_LIST *>(&best_choices));
  for (wc_it.forward(); !wc_it.at_first(); wc_it.forward()) {
    WERD_CHOICE *choice = wc_it.data();
    if (choice->adjust_factor() <= threshold) {
      return false;
    }
  }
  return true;
}