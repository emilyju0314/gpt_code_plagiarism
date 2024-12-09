int LanguageModel::SetTopParentLowerUpperDigit(LanguageModelState *parent_node) const {
  if (parent_node == nullptr) {
    return -1;
  }
  UNICHAR_ID top_id = INVALID_UNICHAR_ID;
  ViterbiStateEntry *top_lower = nullptr;
  ViterbiStateEntry *top_upper = nullptr;
  ViterbiStateEntry *top_digit = nullptr;
  ViterbiStateEntry *top_choice = nullptr;
  float lower_rating = 0.0f;
  float upper_rating = 0.0f;
  float digit_rating = 0.0f;
  float top_rating = 0.0f;
  const UNICHARSET &unicharset = dict_->getUnicharset();
  ViterbiStateEntry_IT vit(&parent_node->viterbi_state_entries);
  for (vit.mark_cycle_pt(); !vit.cycled_list(); vit.forward()) {
    ViterbiStateEntry *vse = vit.data();
    // INVALID_UNICHAR_ID should be treated like a zero-width joiner, so scan
    // back to the real character if needed.
    ViterbiStateEntry *unichar_vse = vse;
    UNICHAR_ID unichar_id = unichar_vse->curr_b->unichar_id();
    float rating = unichar_vse->curr_b->rating();
    while (unichar_id == INVALID_UNICHAR_ID && unichar_vse->parent_vse != nullptr) {
      unichar_vse = unichar_vse->parent_vse;
      unichar_id = unichar_vse->curr_b->unichar_id();
      rating = unichar_vse->curr_b->rating();
    }
    if (unichar_id != INVALID_UNICHAR_ID) {
      if (unicharset.get_islower(unichar_id)) {
        if (top_lower == nullptr || lower_rating > rating) {
          top_lower = vse;
          lower_rating = rating;
        }
      } else if (unicharset.get_isalpha(unichar_id)) {
        if (top_upper == nullptr || upper_rating > rating) {
          top_upper = vse;
          upper_rating = rating;
        }
      } else if (unicharset.get_isdigit(unichar_id)) {
        if (top_digit == nullptr || digit_rating > rating) {
          top_digit = vse;
          digit_rating = rating;
        }
      }
    }
    if (top_choice == nullptr || top_rating > rating) {
      top_choice = vse;
      top_rating = rating;
      top_id = unichar_id;
    }
  }
  if (top_choice == nullptr) {
    return -1;
  }
  bool mixed = (top_lower != nullptr || top_upper != nullptr) && top_digit != nullptr;
  if (top_lower == nullptr) {
    top_lower = top_choice;
  }
  top_lower->top_choice_flags |= kLowerCaseFlag;
  if (top_upper == nullptr) {
    top_upper = top_choice;
  }
  top_upper->top_choice_flags |= kUpperCaseFlag;
  if (top_digit == nullptr) {
    top_digit = top_choice;
  }
  top_digit->top_choice_flags |= kDigitFlag;
  top_choice->top_choice_flags |= kSmallestRatingFlag;
  if (top_id != INVALID_UNICHAR_ID && dict_->compound_marker(top_id) &&
      (top_choice->top_choice_flags & (kLowerCaseFlag | kUpperCaseFlag | kDigitFlag))) {
    // If the compound marker top choice carries any of the top alnum flags,
    // then give it all of them, allowing words like I-295 to be chosen.
    top_choice->top_choice_flags |= kLowerCaseFlag | kUpperCaseFlag | kDigitFlag;
  }
  return mixed ? 1 : 0;
}