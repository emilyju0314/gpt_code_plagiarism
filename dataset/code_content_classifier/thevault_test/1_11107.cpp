bool ColPartitionGrid::MergePart(
    const std::function<bool(ColPartition *, TBOX *)> &box_cb,
    const std::function<bool(const ColPartition *, const ColPartition *)>
        &confirm_cb,
    ColPartition *part) {
  if (part->IsUnMergeableType()) {
    return false;
  }
  bool any_done = false;
  // Repeatedly merge part while we find a best merge candidate that works.
  bool merge_done = false;
  do {
    merge_done = false;
    TBOX box = part->bounding_box();
    bool debug = AlignedBlob::WithinTestRegion(2, box.left(), box.bottom());
    if (debug) {
      tprintf("Merge candidate:");
      box.print();
    }
    // Set up a rectangle search bounded by the part.
    if (!box_cb(part, &box)) {
      continue;
    }
    // Create a list of merge candidates.
    ColPartition_CLIST merge_candidates;
    FindMergeCandidates(part, box, debug, &merge_candidates);
    // Find the best merge candidate based on minimal overlap increase.
    int overlap_increase;
    ColPartition *neighbour = BestMergeCandidate(part, &merge_candidates, debug,
                                                 confirm_cb, &overlap_increase);
    if (neighbour != nullptr && overlap_increase <= 0) {
      if (debug) {
        tprintf("Merging:hoverlap=%d, voverlap=%d, OLI=%d\n",
                part->HCoreOverlap(*neighbour), part->VCoreOverlap(*neighbour),
                overlap_increase);
      }
      // Looks like a good candidate so merge it.
      RemoveBBox(neighbour);
      // We will modify the box of part, so remove it from the grid, merge
      // it and then re-insert it into the grid.
      RemoveBBox(part);
      part->Absorb(neighbour, nullptr);
      InsertBBox(true, true, part);
      merge_done = true;
      any_done = true;
    } else if (neighbour != nullptr) {
      if (debug) {
        tprintf("Overlapped when merged with increase %d: ", overlap_increase);
        neighbour->bounding_box().print();
      }
    } else if (debug) {
      tprintf("No candidate neighbour returned\n");
    }
  } while (merge_done);
  return any_done;
}