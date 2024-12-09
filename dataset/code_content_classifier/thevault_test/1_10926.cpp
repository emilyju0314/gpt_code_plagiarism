void RecodeBeamSearch::DebugUnicharPath(
    const UNICHARSET *unicharset, const std::vector<const RecodeNode *> &path,
    const std::vector<int> &unichar_ids, const std::vector<float> &certs,
    const std::vector<float> &ratings, const std::vector<int> &xcoords) const {
  auto num_ids = unichar_ids.size();
  double total_rating = 0.0;
  for (unsigned c = 0; c < num_ids; ++c) {
    int coord = xcoords[c];
    tprintf("%d %d=%s r=%g, c=%g, s=%d, e=%d, perm=%d\n", coord, unichar_ids[c],
            unicharset->debug_str(unichar_ids[c]).c_str(), ratings[c], certs[c],
            path[coord]->start_of_word, path[coord]->end_of_word,
            path[coord]->permuter);
    total_rating += ratings[c];
  }
  tprintf("Path total rating = %g\n", total_rating);
}