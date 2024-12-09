Image TrainingSample::GetSamplePix(int padding, Image page_pix) const {
  if (page_pix == nullptr) {
    return nullptr;
  }
  int page_width = pixGetWidth(page_pix);
  int page_height = pixGetHeight(page_pix);
  TBOX padded_box = bounding_box();
  padded_box.pad(padding, padding);
  // Clip the padded_box to the limits of the page
  TBOX page_box(0, 0, page_width, page_height);
  padded_box &= page_box;
  Box *box =
      boxCreate(page_box.left(), page_height - page_box.top(), page_box.width(), page_box.height());
  Image sample_pix = pixClipRectangle(page_pix, box, nullptr);
  boxDestroy(&box);
  return sample_pix;
}