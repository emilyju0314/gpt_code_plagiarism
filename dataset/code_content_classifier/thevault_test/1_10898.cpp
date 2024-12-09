void TWERD::BLNormalize(const BLOCK *block, const ROW *row, Image pix, bool inverse, float x_height,
                        float baseline_shift, bool numeric_mode, tesseract::OcrEngineMode hint,
                        const TBOX *norm_box, DENORM *word_denorm) {
  TBOX word_box = bounding_box();
  if (norm_box != nullptr) {
    word_box = *norm_box;
  }
  float word_middle = (word_box.left() + word_box.right()) / 2.0f;
  float input_y_offset = 0.0f;
  auto final_y_offset = static_cast<float>(kBlnBaselineOffset);
  float scale = kBlnXHeight / x_height;
  if (row == nullptr) {
    word_middle = word_box.left();
    input_y_offset = word_box.bottom();
    final_y_offset = 0.0f;
  } else {
    input_y_offset = row->base_line(word_middle) + baseline_shift;
  }
  for (auto blob : blobs) {
    TBOX blob_box = blob->bounding_box();
    float mid_x = (blob_box.left() + blob_box.right()) / 2.0f;
    float baseline = input_y_offset;
    float blob_scale = scale;
    if (numeric_mode) {
      baseline = blob_box.bottom();
      blob_scale = ClipToRange(kBlnXHeight * 4.0f / (3 * blob_box.height()), scale, scale * 1.5f);
    } else if (row != nullptr) {
      baseline = row->base_line(mid_x) + baseline_shift;
    }
    // The image will be 8-bit grey if the input was grey or color. Note that in
    // a grey image 0 is black and 255 is white. If the input was binary, then
    // the pix will be binary and 0 is white, with 1 being black.
    // To tell the difference pixGetDepth() will return 8 or 1.
    // The inverse flag will be true iff the word has been determined to be
    // white on black, and is independent of whether the pix is 8 bit or 1 bit.
    blob->Normalize(block, nullptr, nullptr, word_middle, baseline, blob_scale, blob_scale, 0.0f,
                    final_y_offset, inverse, pix);
  }
  if (word_denorm != nullptr) {
    word_denorm->SetupNormalization(block, nullptr, nullptr, word_middle, input_y_offset, scale,
                                    scale, 0.0f, final_y_offset);
    word_denorm->set_inverse(inverse);
    word_denorm->set_pix(pix);
  }
}