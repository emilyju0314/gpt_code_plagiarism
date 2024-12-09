TEST_F(ResultIteratorTest, SubSuperTest) {
  SetImage("0146_281.3B.tif");
  char* result = api_.GetUTF8Text();
  delete [] result;
  ResultIterator* r_it = api_.GetIterator();
  // Iterate over the symbols.
  // Accuracy isn't great, so just count up and expect a decent count of
  // positives and negatives.
  const char kAllowedSupers[] = "O0123456789-";
  int found_subs = 0;
  int found_supers = 0;
  int found_normal = 0;
  do {
    if (r_it->SymbolIsSubscript()) {
      ++found_subs;
    } else if (r_it->SymbolIsSuperscript()) {
      result = r_it->GetUTF8Text(tesseract::RIL_SYMBOL);
      if (strchr(kAllowedSupers, result[0]) == nullptr) {
        char* word = r_it->GetUTF8Text(tesseract::RIL_WORD);
        LOG(ERROR) << "Char " << result << " in word " << word << " is unexpected super!";
        delete [] word;
        EXPECT_TRUE(strchr(kAllowedSupers, result[0]) != nullptr);
      }
      delete [] result;
      ++found_supers;
    } else {
      ++found_normal;
    }
  } while (r_it->Next(tesseract::RIL_SYMBOL));
  delete r_it;
  LOG(INFO) << "Subs = " << found_subs << ", supers= " << found_supers
    << ", normal = " << found_normal << "\n";
  EXPECT_GE(found_subs, 25);
  EXPECT_GE(found_supers, 25);
  EXPECT_GE(found_normal, 1350);
}