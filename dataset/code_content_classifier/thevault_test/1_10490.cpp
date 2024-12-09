TEST_F(RecodeBeamTest, DISABLED_MultiCodeSequences) {
  LOG(INFO) << "Testing duplicates in multi-code sequences"
            << "\n";
  LoadUnicharset("vie.d.unicharset");
  tesseract::SetupBasicProperties(false, true, &ccutil_.unicharset);
  TRand random;
  GENERIC_2D_ARRAY<float> outputs =
      GenerateSyntheticOutputs(kViTops, kViTopScores, kVi2nds, kVi2ndScores, &random);
  PointerVector<WERD_RES> words;
  std::string truth_str;
  tesseract::NormalizeUTF8String(tesseract::UnicodeNormMode::kNFKC, tesseract::OCRNorm::kNormalize,
                                 tesseract::GraphemeNorm::kNone, "vậy tội", &truth_str);
  ExpectCorrect(outputs, truth_str, nullptr, &words);
}