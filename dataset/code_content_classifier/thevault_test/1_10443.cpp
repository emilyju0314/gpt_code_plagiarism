Image C_BLOB::render_outline() {
  TBOX box = bounding_box();
  Image pix = pixCreate(box.width(), box.height(), 1);
  render_outline_list_outline(&outlines, box.left(), box.top(), pix);
  return pix;
}