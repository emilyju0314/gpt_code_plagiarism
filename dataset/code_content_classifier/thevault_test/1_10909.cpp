void RecodeBeamSearch::DebugBeams(const UNICHARSET &unicharset) const {
  for (int p = 0; p < beam_size_; ++p) {
    for (int d = 0; d < 2; ++d) {
      for (int c = 0; c < NC_COUNT; ++c) {
        auto cont = static_cast<NodeContinuation>(c);
        int index = BeamIndex(d, cont, 0);
        if (beam_[p]->beams_[index].empty()) {
          continue;
        }
        // Print all the best scoring nodes for each unichar found.
        tprintf("Position %d: %s+%s beam\n", p, d ? "Dict" : "Non-Dict",
                kNodeContNames[c]);
        DebugBeamPos(unicharset, beam_[p]->beams_[index]);
      }
    }
  }
}