TEST_F(TesseractTest, LSTMGeometryTest) {
  Image src_pix = pixRead(TestDataNameToPath("deslant.tif").c_str());
  FriendlyTessBaseAPI api;
  if (api.Init(TessdataPath().c_str(), "eng", tesseract::OEM_LSTM_ONLY) == -1) {
    // eng.traineddata not found.
    GTEST_SKIP();
    return;
  }
  api.SetImage(src_pix);
  ASSERT_EQ(api.Recognize(nullptr), 0);

  const PAGE_RES *page_res = api.GetPageRes();
  PAGE_RES_IT page_res_it(const_cast<PAGE_RES *>(page_res));
  page_res_it.restart_page();
  BLOCK *block = page_res_it.block()->block;
  CHECK(block);

  // extract word and character boxes for each word
  for (page_res_it.restart_page(); page_res_it.word() != nullptr; page_res_it.forward()) {
    WERD_RES *word = page_res_it.word();
    CHECK(word);
    CHECK(word->best_choice);
    CHECK_GT(word->best_choice->length(), 0);
    CHECK(word->word);
    CHECK(word->box_word);
    // tesseract's word box
    TBOX tess_blob_box;
    tess_blob_box = word->word->bounding_box();
    tess_blob_box.rotate(block->re_rotation());
    // verify that each of LSTM's character boxes lies close to within
    // tesseract's word box
    for (int i = 0; i < word->box_word->length(); ++i) {
      TBOX lstm_blob_box = word->box_word->BlobBox(i);
      // LSTM character box should not spill out of tesseract word box
      // by more than a few pixels in any direction
      EXPECT_LT(tess_blob_box.left() - lstm_blob_box.left(), 5);
      EXPECT_LT(lstm_blob_box.right() - tess_blob_box.right(), 5);
      EXPECT_LT(tess_blob_box.bottom() - lstm_blob_box.bottom(), 5);
      EXPECT_LT(lstm_blob_box.top() - tess_blob_box.top(), 5);
    }
  }
  src_pix.destroy();
}