Image TraceBlockOnReducedPix(BLOCK *block, int gridsize, ICOORD bleft, int *left, int *bottom) {
  const TBOX &box = block->pdblk.bounding_box();
  Image pix = GridReducedPix(box, gridsize, bleft, left, bottom);
  int wpl = pixGetWpl(pix);
  l_uint32 *data = pixGetData(pix);
  ICOORDELT_IT it(block->pdblk.poly_block()->points());
  for (it.mark_cycle_pt(); !it.cycled_list();) {
    ICOORD pos = *it.data();
    it.forward();
    ICOORD next_pos = *it.data();
    ICOORD line_vector = next_pos - pos;
    int major, minor;
    ICOORD major_step, minor_step;
    line_vector.setup_render(&major_step, &minor_step, &major, &minor);
    int accumulator = major / 2;
    while (pos != next_pos) {
      int grid_x = (pos.x() - bleft.x()) / gridsize - *left;
      int grid_y = (pos.y() - bleft.y()) / gridsize - *bottom;
      SET_DATA_BIT(data + grid_y * wpl, grid_x);
      pos += major_step;
      accumulator += minor;
      if (accumulator >= major) {
        accumulator -= major;
        pos += minor_step;
      }
    }
  }
  return pix;
}