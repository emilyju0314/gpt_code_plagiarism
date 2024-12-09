Image C_BLOB::render() {
  TBOX box = bounding_box();
  Image pix = pixCreate(box.width(), box.height(), 1);
  render_outline_list(&outlines, box.left(), box.top(), pix);
  return pix;
}