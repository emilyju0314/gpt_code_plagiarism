void TextlineProjection::ProjectBlobs(BLOBNBOX_LIST *blobs, const FCOORD &rotation,
                                      const TBOX &nontext_map_box, Image nontext_map) {
  BLOBNBOX_IT blob_it(blobs);
  for (blob_it.mark_cycle_pt(); !blob_it.cycled_list(); blob_it.forward()) {
    BLOBNBOX *blob = blob_it.data();
    TBOX bbox = blob->bounding_box();
    ICOORD middle((bbox.left() + bbox.right()) / 2, (bbox.bottom() + bbox.top()) / 2);
    bool spreading_horizontally = PadBlobBox(blob, &bbox);
    // Rotate to match the nontext_map.
    bbox.rotate(rotation);
    middle.rotate(rotation);
    if (rotation.x() == 0.0f) {
      spreading_horizontally = !spreading_horizontally;
    }
    // Clip to the image before applying the increments.
    bbox &= nontext_map_box; // This is in-place box intersection.
    // Check for image pixels before spreading.
    TruncateBoxToMissNonText(middle.x(), middle.y(), spreading_horizontally, nontext_map, &bbox);
    if (bbox.area() > 0) {
      IncrementRectangle8Bit(bbox);
    }
  }
}