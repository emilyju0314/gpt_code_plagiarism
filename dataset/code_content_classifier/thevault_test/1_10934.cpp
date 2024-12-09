TEST_F(UnicharcompressTest, GetEncodingAsString) {
  LoadUnicharset("trivial.unicharset");
  ExpectCorrect("trivial");
  std::string encoding = compressed_.GetEncodingAsString(unicharset_);
  std::string encoding_str(&encoding[0], encoding.length());
  std::vector<std::string> lines = split(encoding_str, '\n');
  EXPECT_EQ(5, lines.size());
  // The first line is always space.
  EXPECT_EQ("0\t ", lines[0]);
  // Next we have i.
  EXPECT_EQ("1\ti", lines[1]);
  // Next we have f.
  EXPECT_EQ("2\tf", lines[2]);
  // Next we have the fi ligature: ﬁ. There are no nulls in it, as there are no
  // repeated letter ligatures in this unicharset, unlike por.unicharset above.
  EXPECT_EQ("2,1\tﬁ", lines[3]);
  // Finally the null character.
  EXPECT_EQ("3\t<nul>", lines[4]);
}