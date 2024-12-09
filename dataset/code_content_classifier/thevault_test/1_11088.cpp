TEST(TesseractInstanceTest, TestMultipleTessInstances) {
  int num_langs = 0;
  while (langs[num_langs] != nullptr) {
    ++num_langs;
  }

  const std::string kTessdataPath = TESSDATA_DIR;

  // Preload images and verify that OCR is correct on them individually.
  std::vector<Image > pix(num_langs);
  for (int i = 0; i < num_langs; ++i) {
    std::string tracestring = "Single instance test with lang = ";
    tracestring += langs[i];
    SCOPED_TRACE(tracestring);
    std::string path = file::JoinPath(TESTING_DIR, image_files[i]);
    pix[i] = pixRead(path.c_str());
    QCHECK(pix[i] != nullptr) << "Could not read " << path;

    tesseract::TessBaseAPI tess;
    EXPECT_EQ(0, tess.Init(kTessdataPath.c_str(), langs[i]));
    std::string ocr_result = GetCleanedTextResult(&tess, pix[i]);
    EXPECT_STREQ(gt_text[i], ocr_result.c_str());
  }

  // Process the images in all pairwise combinations of associated languages.
  std::string ocr_result[2];
  for (int i = 0; i < num_langs; ++i) {
    for (int j = i + 1; j < num_langs; ++j) {
      tesseract::TessBaseAPI tess1, tess2;
      tess1.Init(kTessdataPath.c_str(), langs[i]);
      tess2.Init(kTessdataPath.c_str(), langs[j]);

      ocr_result[0] = GetCleanedTextResult(&tess1, pix[i]);
      ocr_result[1] = GetCleanedTextResult(&tess2, pix[j]);

      EXPECT_FALSE(strcmp(gt_text[i], ocr_result[0].c_str()) ||
                   strcmp(gt_text[j], ocr_result[1].c_str()))
          << "OCR failed on language pair " << langs[i] << "-" << langs[j];
    }
  }

  for (int i = 0; i < num_langs; ++i) {
    pix[i].destroy();
  }
}