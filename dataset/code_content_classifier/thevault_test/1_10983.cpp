bool WERD_RES::LogNewRawChoice(WERD_CHOICE *word_choice) {
  if (raw_choice == nullptr || word_choice->rating() < raw_choice->rating()) {
    delete raw_choice;
    raw_choice = new WERD_CHOICE(*word_choice);
    raw_choice->set_permuter(TOP_CHOICE_PERM);
    return true;
  }
  return false;
}