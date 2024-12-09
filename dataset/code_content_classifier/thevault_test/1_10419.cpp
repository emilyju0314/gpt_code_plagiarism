void Tesseract::reject_edge_blobs(WERD_RES *word) {
  TBOX word_box = word->word->bounding_box();
  // Use the box_word as it is already denormed back to image coordinates.
  int blobcount = word->box_word->length();

  if (word_box.left() < tessedit_image_border || word_box.bottom() < tessedit_image_border ||
      word_box.right() + tessedit_image_border > ImageWidth() - 1 ||
      word_box.top() + tessedit_image_border > ImageHeight() - 1) {
    ASSERT_HOST(word->reject_map.length() == blobcount);
    for (int blobindex = 0; blobindex < blobcount; blobindex++) {
      TBOX blob_box = word->box_word->BlobBox(blobindex);
      if (blob_box.left() < tessedit_image_border || blob_box.bottom() < tessedit_image_border ||
          blob_box.right() + tessedit_image_border > ImageWidth() - 1 ||
          blob_box.top() + tessedit_image_border > ImageHeight() - 1) {
        word->reject_map[blobindex].setrej_edge_char();
        // Close to edge
      }
    }
  }
}