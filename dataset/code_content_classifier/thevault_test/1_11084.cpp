TEST_F(TesseractTest, HOCRContainsBaseline) {
  tesseract::TessBaseAPI api;
  if (api.Init(TessdataPath().c_str(), "eng", tesseract::OEM_TESSERACT_ONLY) == -1) {
    // eng.traineddata not found.
    GTEST_SKIP();
    return;
  }
  Image src_pix = pixRead(TestDataNameToPath("HelloGoogle.tif").c_str());
  CHECK(src_pix);
  api.SetInputName("HelloGoogle.tif");
  api.SetImage(src_pix);
  char *result = api.GetHOCRText(0);
  EXPECT_TRUE(result != nullptr);
  EXPECT_THAT(result, HasSubstr("Hello"));
  EXPECT_TRUE(std::regex_search(
      result, std::regex{"<span class='ocr_line'[^>]* baseline [-.0-9]+ [-.0-9]+"}));

  delete[] result;
  src_pix.destroy();
}