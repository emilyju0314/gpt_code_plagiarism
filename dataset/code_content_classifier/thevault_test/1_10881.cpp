TBLOB *TBLOB::ClassifyNormalizeIfNeeded() const {
  TBLOB *rotated_blob = nullptr;
  // If necessary, copy the blob and rotate it. The rotation is always
  // +/- 90 degrees, as 180 was already taken care of.
  if (denorm_.block() != nullptr && denorm_.block()->classify_rotation().y() != 0.0) {
    TBOX box = bounding_box();
    int x_middle = (box.left() + box.right()) / 2;
    int y_middle = (box.top() + box.bottom()) / 2;
    rotated_blob = new TBLOB(*this);
    const FCOORD &rotation = denorm_.block()->classify_rotation();
    // Move the rotated blob back to the same y-position so that we
    // can still distinguish similar glyphs with differeny y-position.
    float target_y =
        kBlnBaselineOffset + (rotation.y() > 0 ? x_middle - box.left() : box.right() - x_middle);
    rotated_blob->Normalize(nullptr, &rotation, &denorm_, x_middle, y_middle, 1.0f, 1.0f, 0.0f,
                            target_y, denorm_.inverse(), denorm_.pix());
  }
  return rotated_blob;
}