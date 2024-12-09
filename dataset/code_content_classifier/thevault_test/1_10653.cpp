ImageData *Tesseract::GetRectImage(const TBOX &box, const BLOCK &block, int padding,
                                   TBOX *revised_box) const {
  TBOX wbox = box;
  wbox.pad(padding, padding);
  *revised_box = wbox;
  // Number of clockwise 90 degree rotations needed to get back to tesseract
  // coords from the clipped image.
  int num_rotations = 0;
  if (block.re_rotation().y() > 0.0f) {
    num_rotations = 1;
  } else if (block.re_rotation().x() < 0.0f) {
    num_rotations = 2;
  } else if (block.re_rotation().y() < 0.0f) {
    num_rotations = 3;
  }
  // Handle two cases automatically: 1 the box came from the block, 2 the box
  // came from a box file, and refers to the image, which the block may not.
  if (block.pdblk.bounding_box().major_overlap(*revised_box)) {
    revised_box->rotate(block.re_rotation());
  }
  // Now revised_box always refers to the image.
  // BestPix is never colormapped, but may be of any depth.
  Image pix = BestPix();
  int width = pixGetWidth(pix);
  int height = pixGetHeight(pix);
  TBOX image_box(0, 0, width, height);
  // Clip to image bounds;
  *revised_box &= image_box;
  if (revised_box->null_box()) {
    return nullptr;
  }
  Box *clip_box = boxCreate(revised_box->left(), height - revised_box->top(), revised_box->width(),
                            revised_box->height());
  Image box_pix = pixClipRectangle(pix, clip_box, nullptr);
  boxDestroy(&clip_box);
  if (box_pix == nullptr) {
    return nullptr;
  }
  if (num_rotations > 0) {
    Image rot_pix = pixRotateOrth(box_pix, num_rotations);
    box_pix.destroy();
    box_pix = rot_pix;
  }
  // Convert sub-8-bit images to 8 bit.
  int depth = pixGetDepth(box_pix);
  if (depth < 8) {
    Image grey;
    grey = pixConvertTo8(box_pix, false);
    box_pix.destroy();
    box_pix = grey;
  }
  bool vertical_text = false;
  if (num_rotations > 0) {
    // Rotated the clipped revised box back to internal coordinates.
    FCOORD rotation(block.re_rotation().x(), -block.re_rotation().y());
    revised_box->rotate(rotation);
    if (num_rotations != 2) {
      vertical_text = true;
    }
  }
  return new ImageData(vertical_text, box_pix);
}