void WERD_RES::BestChoiceToCorrectText() {
  correct_text.clear();
  ASSERT_HOST(best_choice != nullptr);
  for (unsigned i = 0; i < best_choice->length(); ++i) {
    UNICHAR_ID choice_id = best_choice->unichar_id(i);
    const char *blob_choice = uch_set->id_to_unichar(choice_id);
    correct_text.emplace_back(blob_choice);
  }
}