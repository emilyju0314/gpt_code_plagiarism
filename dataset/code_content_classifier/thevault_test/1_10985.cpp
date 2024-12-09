void WERD_RES::PrintBestChoices() const {
  std::string alternates_str;
  WERD_CHOICE_IT it(const_cast<WERD_CHOICE_LIST *>(&best_choices));
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    if (!it.at_first()) {
      alternates_str += "\", \"";
    }
    alternates_str += it.data()->unichar_string();
  }
  tprintf("Alternates for \"%s\": {\"%s\"}\n",
          best_choice->unichar_string().c_str(), alternates_str.c_str());
}