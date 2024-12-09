bool LanguageModel::GetTopLowerUpperDigit(BLOB_CHOICE_LIST *curr_list, BLOB_CHOICE **first_lower,
                                          BLOB_CHOICE **first_upper,
                                          BLOB_CHOICE **first_digit) const {
  BLOB_CHOICE_IT c_it(curr_list);
  const UNICHARSET &unicharset = dict_->getUnicharset();
  BLOB_CHOICE *first_unichar = nullptr;
  for (c_it.mark_cycle_pt(); !c_it.cycled_list(); c_it.forward()) {
    UNICHAR_ID unichar_id = c_it.data()->unichar_id();
    if (unicharset.get_fragment(unichar_id)) {
      continue; // skip fragments
    }
    if (first_unichar == nullptr) {
      first_unichar = c_it.data();
    }
    if (*first_lower == nullptr && unicharset.get_islower(unichar_id)) {
      *first_lower = c_it.data();
    }
    if (*first_upper == nullptr && unicharset.get_isalpha(unichar_id) &&
        !unicharset.get_islower(unichar_id)) {
      *first_upper = c_it.data();
    }
    if (*first_digit == nullptr && unicharset.get_isdigit(unichar_id)) {
      *first_digit = c_it.data();
    }
  }
  ASSERT_HOST(first_unichar != nullptr);
  bool mixed = (*first_lower != nullptr || *first_upper != nullptr) && *first_digit != nullptr;
  if (*first_lower == nullptr) {
    *first_lower = first_unichar;
  }
  if (*first_upper == nullptr) {
    *first_upper = first_unichar;
  }
  if (*first_digit == nullptr) {
    *first_digit = first_unichar;
  }
  return mixed;
}