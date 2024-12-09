TEST_F(TesseractTest, BasicLSTMTest) {
  tesseract::TessBaseAPI api;
  std::string truth_text;
  std::string ocr_text;
  if (api.Init(TessdataPath().c_str(), "eng", tesseract::OEM_LSTM_ONLY) == -1) {
    // eng.traineddata not found.
    GTEST_SKIP();
    return;
  }
  Image src_pix = pixRead(TestDataNameToPath("phototest_2.tif").c_str());
  CHECK(src_pix);
  ocr_text = GetCleanedTextResult(&api, src_pix);
  CHECK_OK(
      file::GetContents(TestDataNameToPath("phototest.gold.txt"), &truth_text, file::Defaults()));
  trim(truth_text);
  EXPECT_STREQ(truth_text.c_str(), ocr_text.c_str());
  src_pix.destroy();
}