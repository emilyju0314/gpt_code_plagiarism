TEST_F(TesseractTest, IteratesParagraphsEvenIfNotDetected) {
  tesseract::TessBaseAPI api;
  if (api.Init(TessdataPath().c_str(), "eng", tesseract::OEM_TESSERACT_ONLY) != -1) {
    api.SetPageSegMode(tesseract::PSM_SINGLE_BLOCK);
    api.SetVariable("paragraph_debug_level", "3");
#if 0 // TODO: b622.png is missing
    Pix* src_pix = pixRead(TestDataNameToPath("b622.png").c_str());
    CHECK(src_pix);
    api.SetImage(src_pix);
    Boxa* para_boxes =
        api.GetComponentImages(tesseract::RIL_PARA, true, nullptr, nullptr);
    EXPECT_TRUE(para_boxes != nullptr);
    Boxa* block_boxes =
        api.GetComponentImages(tesseract::RIL_BLOCK, true, nullptr, nullptr);
    EXPECT_TRUE(block_boxes != nullptr);
    // TODO(eger): Get paragraphs out of this page pre-text.
    EXPECT_GE(boxaGetCount(para_boxes), boxaGetCount(block_boxes));
    boxaDestroy(&block_boxes);
    boxaDestroy(&para_boxes);
    src_pix.destroy();
#endif
  } else {
    // eng.traineddata not found.
    GTEST_SKIP();
  }
}