TEST(ThresholdTest, OutputAsInGossamer) {
  std::pair<uint64_t, uint64_t> c;
  c.first = 5;
  c.second = 17;
  primitives::AuthorityIndex authority_index{3};
  primitives::AuthorityList authorities;
  authorities.push_back(primitives::Authority{{},/*.weight =*/ 3});
  authorities.push_back(primitives::Authority{{},/*.weight =*/ 1});
  authorities.push_back(primitives::Authority{{},/*.weight =*/ 4});
  authorities.push_back(primitives::Authority{{},/*.weight =*/ 6});
  authorities.push_back(primitives::Authority{{},/*.weight =*/ 10});

  Threshold expected{"28377230912881121443596276039380107264"};
  auto threshold = calculateThreshold(c, authorities, authority_index);
  ASSERT_EQ(threshold, expected);
}