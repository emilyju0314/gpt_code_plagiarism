TEST_F(UnicharcompressTest, DoesLigaturesWithDoubles) {
  LOG(INFO) << "Testing por with ligatures";
  LoadUnicharset("por.unicharset");
  ExpectCorrect("por");
  // Check that any unichar-id that is encoded with multiple codes has the
  // correct encoded_nulll_char_ in between.
  for (int u = 0; u <= unicharset_.size(); ++u) {
    RecodedCharID code;
    int len = compressed_.EncodeUnichar(u, &code);
    if (len > 1) {
      // The should not be any null char in the code.
      for (int i = 0; i < len; ++i) {
        EXPECT_NE(encoded_null_char_, code(i));
      }
    }
  }
}