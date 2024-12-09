TEST_F(TesseractTest, HOCRWorksWithoutSetInputName) {
  tesseract::TessBaseAPI api;
  if (api.Init(TessdataPath().c_str(), "eng", tesseract::OEM_TESSERACT_ONLY) == -1) {
    // eng.traineddata not found.
    GTEST_SKIP();
    return;
  }
  Image src_pix = pixRead(TestDataNameToPath("HelloGoogle.tif").c_str());
  CHECK(src_pix);
  api.SetImage(src_pix);
  char *result = api.GetHOCRText(0);
  EXPECT_TRUE(result != nullptr);
  EXPECT_THAT(result, HasSubstr("Hello"));
  EXPECT_THAT(result, HasSubstr("<div class='ocr_page'"));
  delete[] result;
  src_pix.destroy();
}