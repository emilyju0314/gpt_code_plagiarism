TEST_F(TesseractTest, AdaptToWordStrTest) {
#ifdef DISABLED_LEGACY_ENGINE
  // Skip test because TessBaseAPI::AdaptToWordStr is missing.
  GTEST_SKIP();
#else
  static const char *kTrainingPages[] = {"136.tif", "256.tif", "410.tif", "432.tif", "540.tif",
                                         "692.tif", "779.tif", "793.tif", "808.tif", "815.tif",
                                         "12.tif",  "12.tif",  nullptr};
  static const char *kTrainingText[] = {"1 3 6", "2 5 6", "4 1 0", "4 3 2", "5 4 0",
                                        "6 9 2", "7 7 9", "7 9 3", "8 0 8", "8 1 5",
                                        "1 2",   "1 2",   nullptr};
  static const char *kTestPages[] = {"324.tif", "433.tif", "12.tif", nullptr};
  static const char *kTestText[] = {"324", "433", "12", nullptr};
  tesseract::TessBaseAPI api;
  std::string truth_text;
  std::string ocr_text;
  if (api.Init(TessdataPath().c_str(), "eng", tesseract::OEM_TESSERACT_ONLY) == -1) {
    // eng.traineddata not found.
    GTEST_SKIP();
    return;
  }
  api.SetVariable("matcher_sufficient_examples_for_prototyping", "1");
  api.SetVariable("classify_class_pruner_threshold", "220");
  // Train on the training text.
  for (int i = 0; kTrainingPages[i] != nullptr; ++i) {
    std::string image_file = TestDataNameToPath(kTrainingPages[i]);
    Image src_pix = pixRead(image_file.c_str());
    CHECK(src_pix);
    api.SetImage(src_pix);
    EXPECT_TRUE(api.AdaptToWordStr(tesseract::PSM_SINGLE_WORD, kTrainingText[i]))
        << "Failed to adapt to text \"" << kTrainingText[i] << "\" on image " << image_file;
    src_pix.destroy();
  }
  // Test the test text.
  api.SetVariable("tess_bn_matching", "1");
  api.SetPageSegMode(tesseract::PSM_SINGLE_WORD);
  for (int i = 0; kTestPages[i] != nullptr; ++i) {
    Image src_pix = pixRead(TestDataNameToPath(kTestPages[i]).c_str());
    CHECK(src_pix);
    ocr_text = GetCleanedTextResult(&api, src_pix);
    trim(truth_text);
    EXPECT_STREQ(kTestText[i], ocr_text.c_str());
    src_pix.destroy();
  }
#endif
}