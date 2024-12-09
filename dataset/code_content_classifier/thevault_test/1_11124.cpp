TEST_F(ResultIteratorTest, EasyTest) {
  SetImage("phototest.tif");
  // Just run layout analysis.
  PageIterator *p_it = api_.AnalyseLayout();
  EXPECT_FALSE(p_it == nullptr);
  // Check iterator position.
  EXPECT_TRUE(p_it->IsAtBeginningOf(tesseract::RIL_BLOCK));
  // This should be a single block.
  EXPECT_FALSE(p_it->Next(tesseract::RIL_BLOCK));
  EXPECT_FALSE(p_it->IsAtBeginningOf(tesseract::RIL_BLOCK));

  // The images should rebuild almost perfectly.
  LOG(INFO) << "Verifying image rebuilds 1 (pageiterator)"
            << "\n";
  VerifyRebuilds(10, 10, 0, 0, 0, p_it);
  delete p_it;

  char *result = api_.GetUTF8Text();
  ocr_text_ = result;
  delete[] result;
  ResultIterator *r_it = api_.GetIterator();
  // The images should rebuild almost perfectly.
  LOG(INFO) << "Verifying image rebuilds 2a (resultiterator)"
            << "\n";
  VerifyRebuilds(8, 8, 0, 0, 40, r_it, tesseract::RIL_WORD);
  // Test the text.
  LOG(INFO) << "Verifying text rebuilds 1 (resultiterator)"
            << "\n";
  VerifyAllText(ocr_text_, r_it);

  // The images should rebuild almost perfectly.
  LOG(INFO) << "Verifying image rebuilds 2b (resultiterator)"
            << "\n";
  VerifyRebuilds(8, 8, 0, 0, 40, r_it, tesseract::RIL_WORD);

  r_it->Begin();
  // Test baseline of the first line.
  int x1, y1, x2, y2;
  r_it->Baseline(tesseract::RIL_TEXTLINE, &x1, &y1, &x2, &y2);
  LOG(INFO) << "Baseline ("
     << x1 << ',' << y1 << ")->(" << x2 << ',' << y2 << ")\n";
  // Make sure we have a decent vector.
  EXPECT_GE(x2, x1 + 400);
  // The point 200,116 should be very close to the baseline.
  // (x3,y3) is the vector from (x1,y1) to (200,116)
  int x3 = 200 - x1;
  int y3 = 116 - y1;
  x2 -= x1;
  y2 -= y1;
  // The cross product (x2,y1)x(x3,y3) should be small.
  int product = x2 * y3 - x3 * y2;
  EXPECT_LE(abs(product), x2);

  // Test font attributes for each word.
  do {
    float confidence = r_it->Confidence(tesseract::RIL_WORD);
#ifndef DISABLED_LEGACY_ENGINE
    int pointsize, font_id;
    bool bold, italic, underlined, monospace, serif, smallcaps;
    const char *font = r_it->WordFontAttributes(&bold, &italic, &underlined, &monospace, &serif,
                                                &smallcaps, &pointsize, &font_id);
    EXPECT_GE(confidence, 80.0f);
#endif
    char *word_str = r_it->GetUTF8Text(tesseract::RIL_WORD);

#ifdef DISABLED_LEGACY_ENGINE
    LOG(INFO) << "Word " << word_str << ", conf " << confidence << "\n";
#else
    LOG(INFO) << "Word " << word_str << " in font " << font
      << ", id " << font_id << ", size " << pointsize
      << ", conf " << confidence << "\n";
#endif // def DISABLED_LEGACY_ENGINE
    delete[] word_str;
#ifndef DISABLED_LEGACY_ENGINE
    EXPECT_FALSE(bold);
    EXPECT_FALSE(italic);
    EXPECT_FALSE(underlined);
    EXPECT_FALSE(monospace);
    EXPECT_FALSE(serif);
    // The text is about 31 pixels high.  Above we say the source is 200 ppi,
    // which translates to:
    // 31 pixels / textline * (72 pts / inch) / (200 pixels / inch) = 11.16 pts
    EXPECT_GE(pointsize, 11.16 - 1.50);
    EXPECT_LE(pointsize, 11.16 + 1.50);
#endif // def DISABLED_LEGACY_ENGINE
  } while (r_it->Next(tesseract::RIL_WORD));
  delete r_it;
}