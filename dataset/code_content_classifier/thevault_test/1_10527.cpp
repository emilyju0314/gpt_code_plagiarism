TEST_F(BaseapiThreadTest, TestBasicSanity) {
  for (int i = 0; i < num_langs_; ++i) {
    TessBaseAPI tess;
    InitTessInstance(&tess, langs_[i]);
    std::string ocr_text;
    GetCleanedText(&tess, pix_[i], ocr_text);
    CHECK(strcmp(gt_text_[i].c_str(), ocr_text.c_str()) == 0) << "Failed with lang = " << langs_[i];
  }
}