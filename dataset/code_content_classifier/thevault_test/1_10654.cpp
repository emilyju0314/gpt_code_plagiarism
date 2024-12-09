void Tesseract::LSTMRecognizeWord(const BLOCK &block, ROW *row, WERD_RES *word,
                                  PointerVector<WERD_RES> *words) {
  TBOX word_box = word->word->bounding_box();
  // Get the word image - no frills.
  if (tessedit_pageseg_mode == PSM_SINGLE_WORD || tessedit_pageseg_mode == PSM_RAW_LINE) {
    // In single word mode, use the whole image without any other row/word
    // interpretation.
    word_box = TBOX(0, 0, ImageWidth(), ImageHeight());
  } else {
    float baseline = row->base_line((word_box.left() + word_box.right()) / 2);
    if (baseline + row->descenders() < word_box.bottom()) {
      word_box.set_bottom(baseline + row->descenders());
    }
    if (baseline + row->x_height() + row->ascenders() > word_box.top()) {
      word_box.set_top(baseline + row->x_height() + row->ascenders());
    }
  }
  ImageData *im_data = GetRectImage(word_box, block, kImagePadding, &word_box);
  if (im_data == nullptr) {
    return;
  }

  bool do_invert = tessedit_do_invert;
  lstm_recognizer_->RecognizeLine(*im_data, do_invert, classify_debug_level > 0,
                                  kWorstDictCertainty / kCertaintyScale, word_box, words,
                                  lstm_choice_mode, lstm_choice_iterations);
  delete im_data;
  SearchWords(words);
}