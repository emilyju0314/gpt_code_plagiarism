void RecodeBeamSearch::PushDupOrNoDawgIfBetter(
    int length, bool dup, int code, int unichar_id, float cert,
    float worst_dict_cert, float dict_ratio, bool use_dawgs,
    NodeContinuation cont, const RecodeNode *prev, RecodeBeam *step) {
  int index = BeamIndex(use_dawgs, cont, length);
  if (use_dawgs) {
    if (cert > worst_dict_cert) {
      PushHeapIfBetter(kBeamWidths[length], code, unichar_id,
                       prev ? prev->permuter : NO_PERM, false, false, false,
                       dup, cert, prev, nullptr, &step->beams_[index]);
    }
  } else {
    cert *= dict_ratio;
    if (cert >= kMinCertainty || code == null_char_) {
      PushHeapIfBetter(kBeamWidths[length], code, unichar_id,
                       prev ? prev->permuter : TOP_CHOICE_PERM, false, false,
                       false, dup, cert, prev, nullptr, &step->beams_[index]);
    }
  }
}