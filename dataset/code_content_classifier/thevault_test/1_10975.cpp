bool WERD_RES::SetupForRecognition(const UNICHARSET &unicharset_in,
                                   tesseract::Tesseract *tess, Image pix,
                                   int norm_mode, const TBOX *norm_box,
                                   bool numeric_mode, bool use_body_size,
                                   bool allow_detailed_fx, ROW *row,
                                   const BLOCK *block) {
  auto norm_mode_hint = static_cast<tesseract::OcrEngineMode>(norm_mode);
  tesseract = tess;
  POLY_BLOCK *pb = block != nullptr ? block->pdblk.poly_block() : nullptr;
  if ((norm_mode_hint != tesseract::OEM_LSTM_ONLY &&
       word->cblob_list()->empty()) ||
      (pb != nullptr && !pb->IsText())) {
    // Empty words occur when all the blobs have been moved to the rej_blobs
    // list, which seems to occur frequently in junk.
    SetupFake(unicharset_in);
    word->set_flag(W_REP_CHAR, false);
    return false;
  }
  ClearResults();
  SetupWordScript(unicharset_in);
  chopped_word = TWERD::PolygonalCopy(allow_detailed_fx, word);
  float word_xheight =
      use_body_size && row != nullptr && row->body_size() > 0.0f
          ? row->body_size()
          : x_height;
  chopped_word->BLNormalize(block, row, pix, word->flag(W_INVERSE),
                            word_xheight, baseline_shift, numeric_mode,
                            norm_mode_hint, norm_box, &denorm);
  blob_row = row;
  SetupBasicsFromChoppedWord(unicharset_in);
  SetupBlamerBundle();
  int num_blobs = chopped_word->NumBlobs();
  ratings = new MATRIX(num_blobs, kWordrecMaxNumJoinChunks);
  tess_failed = false;
  return true;
}