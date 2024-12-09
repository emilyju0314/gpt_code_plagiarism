void RecodeBeamSearch::ExtractPathAsUnicharIds(
    const std::vector<const RecodeNode *> &best_nodes,
    std::vector<int> *unichar_ids, std::vector<float> *certs,
    std::vector<float> *ratings, std::vector<int> *xcoords,
    std::vector<int> *character_boundaries) {
  unichar_ids->clear();
  certs->clear();
  ratings->clear();
  xcoords->clear();
  std::vector<int> starts;
  std::vector<int> ends;
  // Backtrack extracting only valid, non-duplicate unichar-ids.
  int t = 0;
  int width = best_nodes.size();
  while (t < width) {
    double certainty = 0.0;
    double rating = 0.0;
    while (t < width && best_nodes[t]->unichar_id == INVALID_UNICHAR_ID) {
      double cert = best_nodes[t++]->certainty;
      if (cert < certainty) {
        certainty = cert;
      }
      rating -= cert;
    }
    starts.push_back(t);
    if (t < width) {
      int unichar_id = best_nodes[t]->unichar_id;
      if (unichar_id == UNICHAR_SPACE && !certs->empty() &&
          best_nodes[t]->permuter != NO_PERM) {
        // All the rating and certainty go on the previous character except
        // for the space itself.
        if (certainty < certs->back()) {
          certs->back() = certainty;
        }
        ratings->back() += rating;
        certainty = 0.0;
        rating = 0.0;
      }
      unichar_ids->push_back(unichar_id);
      xcoords->push_back(t);
      do {
        double cert = best_nodes[t++]->certainty;
        // Special-case NO-PERM space to forget the certainty of the previous
        // nulls. See long comment in ContinueContext.
        if (cert < certainty || (unichar_id == UNICHAR_SPACE &&
                                 best_nodes[t - 1]->permuter == NO_PERM)) {
          certainty = cert;
        }
        rating -= cert;
      } while (t < width && best_nodes[t]->duplicate);
      ends.push_back(t);
      certs->push_back(certainty);
      ratings->push_back(rating);
    } else if (!certs->empty()) {
      if (certainty < certs->back()) {
        certs->back() = certainty;
      }
      ratings->back() += rating;
    }
  }
  starts.push_back(width);
  if (character_boundaries != nullptr) {
    calculateCharBoundaries(&starts, &ends, character_boundaries, width);
  }
  xcoords->push_back(width);
}