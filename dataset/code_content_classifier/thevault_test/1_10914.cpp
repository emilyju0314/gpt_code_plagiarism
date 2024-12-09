void RecodeBeamSearch::DecodeStep(const float *outputs, int t,
                                  double dict_ratio, double cert_offset,
                                  double worst_dict_cert,
                                  const UNICHARSET *charset, bool debug) {
  if (t == static_cast<int>(beam_.size())) {
    beam_.push_back(new RecodeBeam);
  }
  RecodeBeam *step = beam_[t];
  beam_size_ = t + 1;
  step->Clear();
  if (t == 0) {
    // The first step can only use singles and initials.
    ContinueContext(nullptr, BeamIndex(false, NC_ANYTHING, 0), outputs, TN_TOP2,
                    charset, dict_ratio, cert_offset, worst_dict_cert, step);
    if (dict_ != nullptr) {
      ContinueContext(nullptr, BeamIndex(true, NC_ANYTHING, 0), outputs,
                      TN_TOP2, charset, dict_ratio, cert_offset,
                      worst_dict_cert, step);
    }
  } else {
    RecodeBeam *prev = beam_[t - 1];
    if (debug) {
      int beam_index = BeamIndex(true, NC_ANYTHING, 0);
      for (int i = prev->beams_[beam_index].size() - 1; i >= 0; --i) {
        std::vector<const RecodeNode *> path;
        ExtractPath(&prev->beams_[beam_index].get(i).data(), &path);
        tprintf("Step %d: Dawg beam %d:\n", t, i);
        DebugPath(charset, path);
      }
      beam_index = BeamIndex(false, NC_ANYTHING, 0);
      for (int i = prev->beams_[beam_index].size() - 1; i >= 0; --i) {
        std::vector<const RecodeNode *> path;
        ExtractPath(&prev->beams_[beam_index].get(i).data(), &path);
        tprintf("Step %d: Non-Dawg beam %d:\n", t, i);
        DebugPath(charset, path);
      }
    }
    int total_beam = 0;
    // Work through the scores by group (top-2, top-n, the rest) while the beam
    // is empty. This enables extending the context using only the top-n results
    // first, which may have an empty intersection with the valid codes, so we
    // fall back to the rest if the beam is empty.
    for (int tn = 0; tn < TN_COUNT && total_beam == 0; ++tn) {
      auto top_n = static_cast<TopNState>(tn);
      for (int index = 0; index < kNumBeams; ++index) {
        // Working backwards through the heaps doesn't guarantee that we see the
        // best first, but it comes before a lot of the worst, so it is slightly
        // more efficient than going forwards.
        for (int i = prev->beams_[index].size() - 1; i >= 0; --i) {
          ContinueContext(&prev->beams_[index].get(i).data(), index, outputs,
                          top_n, charset, dict_ratio, cert_offset,
                          worst_dict_cert, step);
        }
      }
      for (int index = 0; index < kNumBeams; ++index) {
        if (ContinuationFromBeamsIndex(index) == NC_ANYTHING) {
          total_beam += step->beams_[index].size();
        }
      }
    }
    // Special case for the best initial dawg. Push it on the heap if good
    // enough, but there is only one, so it doesn't blow up the beam.
    for (int c = 0; c < NC_COUNT; ++c) {
      if (step->best_initial_dawgs_[c].code >= 0) {
        int index = BeamIndex(true, static_cast<NodeContinuation>(c), 0);
        RecodeHeap *dawg_heap = &step->beams_[index];
        PushHeapIfBetter(kBeamWidths[0], &step->best_initial_dawgs_[c],
                         dawg_heap);
      }
    }
  }
}