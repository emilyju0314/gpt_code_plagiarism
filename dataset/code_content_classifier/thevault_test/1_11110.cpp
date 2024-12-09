static bool TestCompatibleCandidates(const ColPartition &part, bool debug,
                                     ColPartition_CLIST *candidates) {
  ColPartition_C_IT it(candidates);
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    ColPartition *candidate = it.data();
    if (!candidate->OKDiacriticMerge(part, false)) {
      ColPartition_C_IT it2(it);
      for (it2.mark_cycle_pt(); !it2.cycled_list(); it2.forward()) {
        ColPartition *candidate2 = it2.data();
        if (candidate2 != candidate &&
            !OKMergeCandidate(candidate, candidate2, false)) {
          if (debug) {
            tprintf("NC overlap failed:Candidate:");
            candidate2->bounding_box().print();
            tprintf("fails to be a good merge with:");
            candidate->bounding_box().print();
          }
          return false;
        }
      }
    }
  }
  return true;
}