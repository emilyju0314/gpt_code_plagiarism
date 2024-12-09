static int ExpandImageDir(BlobNeighbourDir dir, const TBOX &im_box, const TBOX &limit_box,
                          ColPartitionGrid *part_grid, TBOX *expanded_box) {
  *expanded_box = im_box;
  switch (dir) {
    case BND_LEFT:
      expanded_box->set_left(ExpandImageLeft(im_box, limit_box.left(), part_grid));
      break;
    case BND_RIGHT:
      expanded_box->set_right(ExpandImageRight(im_box, limit_box.right(), part_grid));
      break;
    case BND_ABOVE:
      expanded_box->set_top(ExpandImageTop(im_box, limit_box.top(), part_grid));
      break;
    case BND_BELOW:
      expanded_box->set_bottom(ExpandImageBottom(im_box, limit_box.bottom(), part_grid));
      break;
    default:
      return 0;
  }
  return expanded_box->area() - im_box.area();
}