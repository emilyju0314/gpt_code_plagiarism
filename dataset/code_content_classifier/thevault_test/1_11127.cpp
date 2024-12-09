TEST_F(ResultIteratorTest, SmallCapDropCapTest) {
#ifdef DISABLED_LEGACY_ENGINE
  // Skip test as LSTM mode does not recognize smallcaps & dropcaps attributes.
  GTEST_SKIP();
#else
  SetImage("8071_093.3B.tif");
  char *result = api_.GetUTF8Text();
  delete[] result;
  ResultIterator *r_it = api_.GetIterator();
  // Iterate over the words.
  int found_dropcaps = 0;
  int found_smallcaps = 0;
  int false_positives = 0;
  do {
    bool bold, italic, underlined, monospace, serif, smallcaps;
    int pointsize, font_id;
    r_it->WordFontAttributes(&bold, &italic, &underlined, &monospace, &serif, &smallcaps,
                             &pointsize, &font_id);
    char *word_str = r_it->GetUTF8Text(tesseract::RIL_WORD);
    if (word_str != nullptr) {
      LOG(INFO) << "Word " << word_str
        << " is " << (smallcaps ? "SMALLCAPS" : "Normal") << "\n";
      if (r_it->SymbolIsDropcap()) {
        ++found_dropcaps;
      }
      if (strcmp(word_str, "SHE") == 0 || strcmp(word_str, "MOPED") == 0 ||
          strcmp(word_str, "RALPH") == 0 || strcmp(word_str, "KINNEY") == 0 || // Not working yet.
          strcmp(word_str, "BENNETT") == 0) {
        EXPECT_TRUE(smallcaps) << word_str;
        ++found_smallcaps;
      } else {
        if (smallcaps) {
          ++false_positives;
        }
      }
      // No symbol other than the first of any word should be dropcap.
      ResultIterator s_it(*r_it);
      while (s_it.Next(tesseract::RIL_SYMBOL) && !s_it.IsAtBeginningOf(tesseract::RIL_WORD)) {
        if (s_it.SymbolIsDropcap()) {
          char *sym_str = s_it.GetUTF8Text(tesseract::RIL_SYMBOL);
          LOG(ERROR) << "Symbol " << sym_str << " of word " << word_str << " is dropcap";
          delete[] sym_str;
        }
        EXPECT_FALSE(s_it.SymbolIsDropcap());
      }
      delete[] word_str;
    }
  } while (r_it->Next(tesseract::RIL_WORD));
  delete r_it;
  EXPECT_EQ(1, found_dropcaps);
  EXPECT_GE(4, found_smallcaps);
  EXPECT_LE(false_positives, 3);
#endif // DISABLED_LEGACY_ENGINE
}