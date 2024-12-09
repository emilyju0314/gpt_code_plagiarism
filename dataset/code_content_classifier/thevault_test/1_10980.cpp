void WERD_RES::DebugWordChoices(bool debug, const char *word_to_debug) {
  if (debug || (word_to_debug != nullptr && *word_to_debug != '\0' &&
                best_choice != nullptr &&
                best_choice->unichar_string() == std::string(word_to_debug))) {
    if (raw_choice != nullptr) {
      raw_choice->print("\nBest Raw Choice");
    }

    WERD_CHOICE_IT it(&best_choices);
    int index = 0;
    for (it.mark_cycle_pt(); !it.cycled_list(); it.forward(), ++index) {
      WERD_CHOICE *choice = it.data();
      std::string label;
      label += "\nCooked Choice #" + std::to_string(index);
      choice->print(label.c_str());
    }
  }
}