void C_OUTLINE::render_outline(int left, int top, Image pix) const {
  ICOORD pos = start;
  for (int stepindex = 0; stepindex < stepcount; ++stepindex) {
    ICOORD next_step = step(stepindex);
    if (next_step.y() < 0) {
      pixSetPixel(pix, pos.x() - left, top - pos.y(), 1);
    } else if (next_step.y() > 0) {
      pixSetPixel(pix, pos.x() - left - 1, top - pos.y() - 1, 1);
    } else if (next_step.x() < 0) {
      pixSetPixel(pix, pos.x() - left - 1, top - pos.y(), 1);
    } else if (next_step.x() > 0) {
      pixSetPixel(pix, pos.x() - left, top - pos.y() - 1, 1);
    }
    pos += next_step;
  }
}