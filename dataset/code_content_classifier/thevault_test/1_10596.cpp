static void MaximalImageBoundingBox(ColPartitionGrid *part_grid, TBOX *im_box) {
  bool dunnit[BND_COUNT];
  memset(dunnit, 0, sizeof(dunnit));
  TBOX limit_box(part_grid->bleft().x(), part_grid->bleft().y(), part_grid->tright().x(),
                 part_grid->tright().y());
  TBOX text_box(*im_box);
  for (int iteration = 0; iteration < BND_COUNT; ++iteration) {
    // Find the direction with least area increase.
    int best_delta = -1;
    BlobNeighbourDir best_dir = BND_LEFT;
    TBOX expanded_boxes[BND_COUNT];
    for (int dir = 0; dir < BND_COUNT; ++dir) {
      auto bnd = static_cast<BlobNeighbourDir>(dir);
      if (!dunnit[bnd]) {
        TBOX expanded_box;
        int area_delta = ExpandImageDir(bnd, text_box, limit_box, part_grid, &expanded_boxes[bnd]);
        if (best_delta < 0 || area_delta < best_delta) {
          best_delta = area_delta;
          best_dir = bnd;
        }
      }
    }
    // Run the best and remember the direction.
    dunnit[best_dir] = true;
    text_box = expanded_boxes[best_dir];
  }
  *im_box = text_box;
}