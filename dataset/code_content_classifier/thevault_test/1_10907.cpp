void RecodeBeamSearch::ExtractBestPathAsUnicharIds(
    bool debug, const UNICHARSET *unicharset, std::vector<int> *unichar_ids,
    std::vector<float> *certs, std::vector<float> *ratings,
    std::vector<int> *xcoords) const {
  std::vector<const RecodeNode *> best_nodes;
  ExtractBestPaths(&best_nodes, nullptr);
  ExtractPathAsUnicharIds(best_nodes, unichar_ids, certs, ratings, xcoords);
  if (debug) {
    DebugPath(unicharset, best_nodes);
    DebugUnicharPath(unicharset, best_nodes, *unichar_ids, *certs, *ratings,
                     *xcoords);
  }
}