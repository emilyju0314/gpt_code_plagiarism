void RecodeBeamSearch::ContinueUnichar(int code, int unichar_id, float cert,
                                       float worst_dict_cert, float dict_ratio,
                                       bool use_dawgs, NodeContinuation cont,
                                       const RecodeNode *prev,
                                       RecodeBeam *step) {
  if (use_dawgs) {
    if (cert > worst_dict_cert) {
      ContinueDawg(code, unichar_id, cert, cont, prev, step);
    }
  } else {
    RecodeHeap *nodawg_heap = &step->beams_[BeamIndex(false, cont, 0)];
    PushHeapIfBetter(kBeamWidths[0], code, unichar_id, TOP_CHOICE_PERM, false,
                     false, false, false, cert * dict_ratio, prev, nullptr,
                     nodawg_heap);
    if (dict_ != nullptr &&
        ((unichar_id == UNICHAR_SPACE && cert > worst_dict_cert) ||
         !dict_->getUnicharset().IsSpaceDelimited(unichar_id))) {
      // Any top choice position that can start a new word, ie a space or
      // any non-space-delimited character, should also be considered
      // by the dawg search, so push initial dawg to the dawg heap.
      float dawg_cert = cert;
      PermuterType permuter = TOP_CHOICE_PERM;
      // Since we use the space either side of a dictionary word in the
      // certainty of the word, (to properly handle weak spaces) and the
      // space is coming from a non-dict word, we need special conditions
      // to avoid degrading the certainty of the dict word that follows.
      // With a space we don't multiply the certainty by dict_ratio, and we
      // flag the space with NO_PERM to indicate that we should not use the
      // predecessor nulls to generate the confidence for the space, as they
      // have already been multiplied by dict_ratio, and we can't go back to
      // insert more entries in any previous heaps.
      if (unichar_id == UNICHAR_SPACE) {
        permuter = NO_PERM;
      } else {
        dawg_cert *= dict_ratio;
      }
      PushInitialDawgIfBetter(code, unichar_id, permuter, false, false,
                              dawg_cert, cont, prev, step);
    }
  }
}