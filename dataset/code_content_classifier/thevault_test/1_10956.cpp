static bool HasBetterCaseVariant(const UNICHARSET &unicharset, const BLOB_CHOICE *choice,
                                 BLOB_CHOICE_LIST *choices) {
  UNICHAR_ID choice_id = choice->unichar_id();
  UNICHAR_ID other_case = unicharset.get_other_case(choice_id);
  if (other_case == choice_id || other_case == INVALID_UNICHAR_ID) {
    return false; // Not upper or lower or not in unicharset.
  }
  if (unicharset.SizesDistinct(choice_id, other_case)) {
    return false; // Can be separated by size.
  }
  BLOB_CHOICE_IT bc_it(choices);
  for (bc_it.mark_cycle_pt(); !bc_it.cycled_list(); bc_it.forward()) {
    BLOB_CHOICE *better_choice = bc_it.data();
    if (better_choice->unichar_id() == other_case) {
      return true; // Found an earlier instance of other_case.
    } else if (better_choice == choice) {
      return false; // Reached the original choice.
    }
  }
  return false; // Should never happen, but just in case.
}