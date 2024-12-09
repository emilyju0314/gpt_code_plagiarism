int TextlineProjection::DistanceOfBoxFromPartition(const TBOX &box, const ColPartition &part,
                                                   const DENORM *denorm, bool debug) const {
  // Compute a partition box that uses the median top/bottom of the blobs
  // within and median left/right for vertical.
  TBOX part_box = part.bounding_box();
  if (part.IsHorizontalType()) {
    part_box.set_top(part.median_top());
    part_box.set_bottom(part.median_bottom());
  } else {
    part_box.set_left(part.median_left());
    part_box.set_right(part.median_right());
  }
  // Now use DistanceOfBoxFromBox to make the actual calculation.
  return DistanceOfBoxFromBox(box, part_box, part.IsHorizontalType(), denorm, debug);
}