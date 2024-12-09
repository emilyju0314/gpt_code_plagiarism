static bool OKMergeCandidate(const ColPartition *part,
                             const ColPartition *candidate, bool debug) {
  const TBOX &part_box = part->bounding_box();
  if (candidate == part) {
    return false; // Ignore itself.
  }
  if (!part->TypesMatch(*candidate) || candidate->IsUnMergeableType()) {
    return false; // Don't mix inappropriate types.
  }

  const TBOX &c_box = candidate->bounding_box();
  if (debug) {
    tprintf("Examining merge candidate:");
    c_box.print();
  }
  // Candidates must be within a reasonable distance.
  if (candidate->IsVerticalType() || part->IsVerticalType()) {
    int h_dist = -part->HCoreOverlap(*candidate);
    if (h_dist >= std::max(part_box.width(), c_box.width()) / 2) {
      if (debug) {
        tprintf("Too far away: h_dist = %d\n", h_dist);
      }
      return false;
    }
  } else {
    // Coarse filter by vertical distance between partitions.
    int v_dist = -part->VCoreOverlap(*candidate);
    if (v_dist >= std::max(part_box.height(), c_box.height()) / 2) {
      if (debug) {
        tprintf("Too far away: v_dist = %d\n", v_dist);
      }
      return false;
    }
    // Candidates must either overlap in median y,
    // or part or candidate must be an acceptable diacritic.
    if (!part->VSignificantCoreOverlap(*candidate) &&
        !part->OKDiacriticMerge(*candidate, debug) &&
        !candidate->OKDiacriticMerge(*part, debug)) {
      if (debug) {
        tprintf("Candidate fails overlap and diacritic tests!\n");
      }
      return false;
    }
  }
  return true;
}