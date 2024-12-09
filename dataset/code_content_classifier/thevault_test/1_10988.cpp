BLOB_CHOICE *WERD_RES::GetBlobChoice(unsigned index) const {
  if (index >= best_choice->length()) {
    return nullptr;
  }
  BLOB_CHOICE_LIST *choices = GetBlobChoices(index);
  return FindMatchingChoice(best_choice->unichar_id(index), choices);
}