static void ComputeSearchBoxAndScaling(BlobNeighbourDir direction,
                                       const TBOX &part_box, int min_padding,
                                       TBOX *search_box, ICOORD *dist_scaling) {
  *search_box = part_box;
  // Generate a pad value based on the min dimension of part_box, but at least
  // min_padding and then scaled by kMaxPadFactor.
  int padding = std::min(part_box.height(), part_box.width());
  padding = std::max(padding, min_padding);
  padding *= kMaxPadFactor;
  search_box->pad(padding, padding);
  // Truncate the box in the appropriate direction and make the distance
  // metric slightly biased in the truncated direction.
  switch (direction) {
    case BND_LEFT:
      search_box->set_left(part_box.left());
      *dist_scaling = ICOORD(2, 1);
      break;
    case BND_BELOW:
      search_box->set_bottom(part_box.bottom());
      *dist_scaling = ICOORD(1, 2);
      break;
    case BND_RIGHT:
      search_box->set_right(part_box.right());
      *dist_scaling = ICOORD(2, 1);
      break;
    case BND_ABOVE:
      search_box->set_top(part_box.top());
      *dist_scaling = ICOORD(1, 2);
      break;
    default:
      ASSERT_HOST(false);
  }
}