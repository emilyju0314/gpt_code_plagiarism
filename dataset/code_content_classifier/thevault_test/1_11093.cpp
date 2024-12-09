void Wordrec::ResetNGramSearch(WERD_RES *word_res, BestChoiceBundle *best_choice_bundle,
                               std::vector<SegSearchPending> &pending) {
  // TODO(rays) More refactoring required here.
  // Delete existing viterbi states.
  for (auto &col : best_choice_bundle->beam) {
    col->Clear();
  }
  // Reset best_choice_bundle.
  word_res->ClearWordChoices();
  best_choice_bundle->best_vse = nullptr;
  // Clear out all existing pendings and add a new one for the first column.
  pending[0].SetColumnClassified();
  for (auto &data : pending) {
    data.Clear();
  }
}