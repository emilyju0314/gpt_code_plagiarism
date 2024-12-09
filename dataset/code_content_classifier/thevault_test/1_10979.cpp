bool WERD_RES::StatesAllValid() {
  unsigned ratings_dim = ratings->dimension();
  if (raw_choice->TotalOfStates() != ratings_dim) {
    tprintf("raw_choice has total of states = %u vs ratings dim of %u\n",
            raw_choice->TotalOfStates(), ratings_dim);
    return false;
  }
  WERD_CHOICE_IT it(&best_choices);
  unsigned index = 0;
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward(), ++index) {
    WERD_CHOICE *choice = it.data();
    if (choice->TotalOfStates() != ratings_dim) {
      tprintf("Cooked #%u has total of states = %u vs ratings dim of %u\n",
              index, choice->TotalOfStates(), ratings_dim);
      return false;
    }
  }
  return true;
}