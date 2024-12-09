void C_OUTLINE::render(int left, int top, Image pix) const {
  ICOORD pos = start;
  for (int stepindex = 0; stepindex < stepcount; ++stepindex) {
    ICOORD next_step = step(stepindex);
    if (next_step.y() < 0) {
      pixRasterop(pix, 0, top - pos.y(), pos.x() - left, 1, PIX_NOT(PIX_DST), nullptr, 0, 0);
    } else if (next_step.y() > 0) {
      pixRasterop(pix, 0, top - pos.y() - 1, pos.x() - left, 1, PIX_NOT(PIX_DST), nullptr, 0, 0);
    }
    pos += next_step;
  }
}