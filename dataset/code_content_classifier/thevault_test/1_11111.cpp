ColPartition *ColPartitionGrid::BestMergeCandidate(
    const ColPartition *part, ColPartition_CLIST *candidates, bool debug,
    const std::function<bool(const ColPartition *, const ColPartition *)>
        &confirm_cb,
    int *overlap_increase) {
  if (overlap_increase != nullptr) {
    *overlap_increase = 0;
  }
  if (candidates->empty()) {
    return nullptr;
  }
  int ok_overlap =
      static_cast<int>(kTinyEnoughTextlineOverlapFraction * gridsize() + 0.5);
  // The best neighbour to merge with is the one that causes least
  // total pairwise overlap among all the neighbours.
  // If more than one offers the same total overlap, choose the one
  // with the least total area.
  const TBOX &part_box = part->bounding_box();
  ColPartition_C_IT it(candidates);
  ColPartition *best_candidate = nullptr;
  // Find the total combined box of all candidates and the original.
  TBOX full_box(part_box);
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    ColPartition *candidate = it.data();
    full_box += candidate->bounding_box();
  }
  // Keep valid neighbours in a list.
  ColPartition_CLIST neighbours;
  // Now run a rect search of the merged box for overlapping neighbours, as
  // we need anything that might be overlapped by the merged box.
  FindOverlappingPartitions(full_box, part, &neighbours);
  if (debug) {
    tprintf("Finding best merge candidate from %d, %d neighbours for box:",
            candidates->length(), neighbours.length());
    part_box.print();
  }
  // If the best increase in overlap is positive, then we also check the
  // worst non-candidate overlap. This catches the case of multiple good
  // candidates that overlap each other when merged. If the worst
  // non-candidate overlap is better than the best overlap, then return
  // the worst non-candidate overlap instead.
  ColPartition_CLIST non_candidate_neighbours;
  non_candidate_neighbours.set_subtract(SortByBoxLeft<ColPartition>, true,
                                        &neighbours, candidates);
  int worst_nc_increase = 0;
  int best_increase = INT32_MAX;
  int best_area = 0;
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    ColPartition *candidate = it.data();
    if (confirm_cb != nullptr && !confirm_cb(part, candidate)) {
      if (debug) {
        tprintf("Candidate not confirmed:");
        candidate->bounding_box().print();
      }
      continue;
    }
    int increase = IncreaseInOverlap(part, candidate, ok_overlap, &neighbours);
    const TBOX &cand_box = candidate->bounding_box();
    if (best_candidate == nullptr || increase < best_increase) {
      best_candidate = candidate;
      best_increase = increase;
      best_area = cand_box.bounding_union(part_box).area() - cand_box.area();
      if (debug) {
        tprintf("New best merge candidate has increase %d, area %d, over box:",
                increase, best_area);
        full_box.print();
        candidate->Print();
      }
    } else if (increase == best_increase) {
      int area = cand_box.bounding_union(part_box).area() - cand_box.area();
      if (area < best_area) {
        best_area = area;
        best_candidate = candidate;
      }
    }
    increase = IncreaseInOverlap(part, candidate, ok_overlap,
                                 &non_candidate_neighbours);
    if (increase > worst_nc_increase) {
      worst_nc_increase = increase;
    }
  }
  if (best_increase > 0) {
    // If the worst non-candidate increase is less than the best increase
    // including the candidates, then all the candidates can merge together
    // and the increase in outside overlap would be less, so use that result,
    // but only if each candidate is either a good diacritic merge with part,
    // or an ok merge candidate with all the others.
    // See TestCompatibleCandidates for more explanation and a picture.
    if (worst_nc_increase < best_increase &&
        TestCompatibleCandidates(*part, debug, candidates)) {
      best_increase = worst_nc_increase;
    }
  }
  if (overlap_increase != nullptr) {
    *overlap_increase = best_increase;
  }
  return best_candidate;
}