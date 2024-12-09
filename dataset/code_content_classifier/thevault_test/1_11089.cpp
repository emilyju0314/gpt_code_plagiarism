TEST(TesseractInstanceTest, TestMultipleTessInstanceVariables) {
  std::string illegal_name = "an_illegal_name";
  std::string langs[2] = {"eng", "hin"};
  std::string int_param_name = "tessedit_pageseg_mode";
  int int_param[2] = {1, 2};
  std::string int_param_str[2] = {"1", "2"};
  std::string bool_param_name = "tessedit_ambigs_training";
  bool bool_param[2] = {false, true};
  std::string bool_param_str[2] = {"F", "T"};
  std::string str_param_name = "tessedit_char_blacklist";
  std::string str_param[2] = {"abc", "def"};
  std::string double_param_name = "segment_penalty_dict_frequent_word";
  std::string double_param_str[2] = {"0.01", "2"};
  double double_param[2] = {0.01, 2};

  const std::string kTessdataPath = TESSDATA_DIR;

  tesseract::TessBaseAPI tess1, tess2;
  for (int i = 0; i < 2; ++i) {
    tesseract::TessBaseAPI *api = (i == 0) ? &tess1 : &tess2;
    api->Init(kTessdataPath.c_str(), langs[i].c_str());
    api->SetVariable(illegal_name.c_str(), "none");
    api->SetVariable(int_param_name.c_str(), int_param_str[i].c_str());
    api->SetVariable(bool_param_name.c_str(), bool_param_str[i].c_str());
    api->SetVariable(str_param_name.c_str(), str_param[i].c_str());
    api->SetVariable(double_param_name.c_str(), double_param_str[i].c_str());
  }
  for (int i = 0; i < 2; ++i) {
    tesseract::TessBaseAPI *api = (i == 0) ? &tess1 : &tess2;
    EXPECT_FALSE(api->GetStringVariable(illegal_name.c_str()));
    int intvar;
    EXPECT_TRUE(api->GetIntVariable(int_param_name.c_str(), &intvar));
    EXPECT_EQ(int_param[i], intvar);
    bool boolvar;
    EXPECT_TRUE(api->GetBoolVariable(bool_param_name.c_str(), &boolvar));
    EXPECT_EQ(bool_param[i], boolvar);
    EXPECT_STREQ(str_param[i].c_str(), api->GetStringVariable(str_param_name.c_str()));
    double doublevar;
    EXPECT_TRUE(api->GetDoubleVariable(double_param_name.c_str(), &doublevar));
    EXPECT_EQ(double_param[i], doublevar);
  }
}