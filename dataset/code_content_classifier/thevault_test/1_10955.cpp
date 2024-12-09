static void ScanParentsForCaseMix(const UNICHARSET &unicharset, LanguageModelState *parent_node) {
  if (parent_node == nullptr) {
    return;
  }
  ViterbiStateEntry_IT vit(&parent_node->viterbi_state_entries);
  for (vit.mark_cycle_pt(); !vit.cycled_list(); vit.forward()) {
    ViterbiStateEntry *vse = vit.data();
    vse->competing_vse = nullptr;
    UNICHAR_ID unichar_id = vse->curr_b->unichar_id();
    if (unicharset.get_isupper(unichar_id) || unicharset.get_islower(unichar_id)) {
      UNICHAR_ID other_case = unicharset.get_other_case(unichar_id);
      if (other_case == unichar_id) {
        continue; // Not in unicharset.
      }
      // Find other case in same list. There could be multiple entries with
      // the same unichar_id, but in theory, they should all point to the
      // same BLOB_CHOICE, and that is what we will be using to decide
      // which to keep.
      ViterbiStateEntry_IT vit2(&parent_node->viterbi_state_entries);
      for (vit2.mark_cycle_pt();
           !vit2.cycled_list() && vit2.data()->curr_b->unichar_id() != other_case; vit2.forward()) {
      }
      if (!vit2.cycled_list()) {
        vse->competing_vse = vit2.data();
      }
    }
  }
}