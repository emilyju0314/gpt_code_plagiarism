Image TraceOutlineOnReducedPix(C_OUTLINE *outline, int gridsize, ICOORD bleft, int *left,
                              int *bottom) {
  const TBOX &box = outline->bounding_box();
  Image pix = GridReducedPix(box, gridsize, bleft, left, bottom);
  int wpl = pixGetWpl(pix);
  l_uint32 *data = pixGetData(pix);
  int length = outline->pathlength();
  ICOORD pos = outline->start_pos();
  for (int i = 0; i < length; ++i) {
    int grid_x = (pos.x() - bleft.x()) / gridsize - *left;
    int grid_y = (pos.y() - bleft.y()) / gridsize - *bottom;
    SET_DATA_BIT(data + grid_y * wpl, grid_x);
    pos += outline->step(i);
  }
  return pix;
}