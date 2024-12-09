void WERD_RES::FakeWordFromRatings(PermuterType permuter) {
  int num_blobs = ratings->dimension();
  auto *word_choice = new WERD_CHOICE(uch_set, num_blobs);
  word_choice->set_permuter(permuter);
  for (int b = 0; b < num_blobs; ++b) {
    UNICHAR_ID unichar_id = UNICHAR_SPACE;
    // Initialize rating and certainty like in WERD_CHOICE::make_bad().
    float rating = WERD_CHOICE::kBadRating;
    float certainty = -FLT_MAX;
    BLOB_CHOICE_LIST *choices = ratings->get(b, b);
    if (choices != nullptr && !choices->empty()) {
      BLOB_CHOICE_IT bc_it(choices);
      BLOB_CHOICE *choice = bc_it.data();
      unichar_id = choice->unichar_id();
      rating = choice->rating();
      certainty = choice->certainty();
    }
    word_choice->append_unichar_id_space_allocated(unichar_id, 1, rating,
                                                   certainty);
  }
  LogNewRawChoice(word_choice);
  // Ownership of word_choice taken by word here.
  LogNewCookedChoice(1, false, word_choice);
}