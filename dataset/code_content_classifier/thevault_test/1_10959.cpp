ViterbiStateEntry *LanguageModel::GetNextParentVSE(bool just_classified, bool mixed_alnum,
                                                   const BLOB_CHOICE *bc,
                                                   LanguageModelFlagsType blob_choice_flags,
                                                   const UNICHARSET &unicharset, WERD_RES *word_res,
                                                   ViterbiStateEntry_IT *vse_it,
                                                   LanguageModelFlagsType *top_choice_flags) const {
  for (; !vse_it->cycled_list(); vse_it->forward()) {
    ViterbiStateEntry *parent_vse = vse_it->data();
    // Only consider the parent if it has been updated or
    // if the current ratings cell has just been classified.
    if (!just_classified && !parent_vse->updated) {
      continue;
    }
    if (language_model_debug_level > 2) {
      parent_vse->Print("Considering");
    }
    // If the parent is non-alnum, then upper counts as lower.
    *top_choice_flags = blob_choice_flags;
    if ((blob_choice_flags & kUpperCaseFlag) && !parent_vse->HasAlnumChoice(unicharset)) {
      *top_choice_flags |= kLowerCaseFlag;
    }
    *top_choice_flags &= parent_vse->top_choice_flags;
    UNICHAR_ID unichar_id = bc->unichar_id();
    const BLOB_CHOICE *parent_b = parent_vse->curr_b;
    UNICHAR_ID parent_id = parent_b->unichar_id();
    // Digits do not bind to alphas if there is a mix in both parent and current
    // or if the alpha is not the top choice.
    if (unicharset.get_isdigit(unichar_id) && unicharset.get_isalpha(parent_id) &&
        (mixed_alnum || *top_choice_flags == 0)) {
      continue; // Digits don't bind to alphas.
    }
    // Likewise alphas do not bind to digits if there is a mix in both or if
    // the digit is not the top choice.
    if (unicharset.get_isalpha(unichar_id) && unicharset.get_isdigit(parent_id) &&
        (mixed_alnum || *top_choice_flags == 0)) {
      continue; // Alphas don't bind to digits.
    }
    // If there is a case mix of the same alpha in the parent list, then
    // competing_vse is non-null and will be used to determine whether
    // or not to bind the current blob choice.
    if (parent_vse->competing_vse != nullptr) {
      const BLOB_CHOICE *competing_b = parent_vse->competing_vse->curr_b;
      UNICHAR_ID other_id = competing_b->unichar_id();
      if (language_model_debug_level >= 5) {
        tprintf("Parent %s has competition %s\n", unicharset.id_to_unichar(parent_id),
                unicharset.id_to_unichar(other_id));
      }
      if (unicharset.SizesDistinct(parent_id, other_id)) {
        // If other_id matches bc wrt position and size, and parent_id, doesn't,
        // don't bind to the current parent.
        if (bc->PosAndSizeAgree(*competing_b, word_res->x_height,
                                language_model_debug_level >= 5) &&
            !bc->PosAndSizeAgree(*parent_b, word_res->x_height, language_model_debug_level >= 5)) {
          continue; // Competing blobchoice has a better vertical match.
        }
      }
    }
    vse_it->forward();
    return parent_vse; // This one is good!
  }
  return nullptr; // Ran out of possibilities.
}