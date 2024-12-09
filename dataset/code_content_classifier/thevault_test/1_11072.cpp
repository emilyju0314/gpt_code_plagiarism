Image PDBLK::render_mask(const FCOORD &rerotation, TBOX *mask_box) {
  TBOX rotated_box(box);
  rotated_box.rotate(rerotation);
  Image pix = pixCreate(rotated_box.width(), rotated_box.height(), 1);
  if (hand_poly != nullptr) {
    // We are going to rotate, so get a deep copy of the points and
    // make a new POLY_BLOCK with it.
    ICOORDELT_LIST polygon;
    polygon.deep_copy(hand_poly->points(), ICOORDELT::deep_copy);
    POLY_BLOCK image_block(&polygon, hand_poly->isA());
    image_block.rotate(rerotation);
    // Block outline is a polygon, so use a PB_LINE_IT to get the
    // rasterized interior. (Runs of interior pixels on a line.)
    auto *lines = new PB_LINE_IT(&image_block);
    for (int y = box.bottom(); y < box.top(); ++y) {
      const std::unique_ptr</*non-const*/ ICOORDELT_LIST> segments(lines->get_line(y));
      if (!segments->empty()) {
        ICOORDELT_IT s_it(segments.get());
        // Each element of segments is a start x and x size of the
        // run of interior pixels.
        for (s_it.mark_cycle_pt(); !s_it.cycled_list(); s_it.forward()) {
          int start = s_it.data()->x();
          int xext = s_it.data()->y();
          // Set the run of pixels to 1.
          pixRasterop(pix, start - rotated_box.left(),
                      rotated_box.height() - 1 - (y - rotated_box.bottom()), xext, 1, PIX_SET,
                      nullptr, 0, 0);
        }
      }
    }
    delete lines;
  } else {
    // Just fill the whole block as there is only a bounding box.
    pixRasterop(pix, 0, 0, rotated_box.width(), rotated_box.height(), PIX_SET, nullptr, 0, 0);
  }
  if (mask_box != nullptr) {
    *mask_box = rotated_box;
  }
  return pix;
}