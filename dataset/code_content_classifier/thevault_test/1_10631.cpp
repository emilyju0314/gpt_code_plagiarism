TEST(ValidatorTest, MostFrequentViramaScript) {
  // The most frequent virama script should come out correct, despite
  // distractions from other scripts.
  EXPECT_EQ(ViramaScript::kTelugu, TestableValidator::TestableMostFrequentViramaScript({0xc05}));
  // It is still Telugu surrounded by Latin.
  EXPECT_EQ(ViramaScript::kTelugu,
            TestableValidator::TestableMostFrequentViramaScript({'a', 0xc05, 'b', 'c'}));
  // But not still Telugu surrounded by Devanagari.
  EXPECT_EQ(ViramaScript::kDevanagari,
            TestableValidator::TestableMostFrequentViramaScript({0x905, 0xc05, 0x906, 0x907}));
  EXPECT_EQ(ViramaScript::kKannada,
            TestableValidator::TestableMostFrequentViramaScript({0xc85, 0xc05, 0xc86, 0xc87}));
  EXPECT_EQ(ViramaScript::kBengali,
            TestableValidator::TestableMostFrequentViramaScript({0x985, 0xc05, 0x986, 0x987}));
  // Danda and double Danda don't count as Devanagari, as they are common.
  EXPECT_EQ(ViramaScript::kTelugu,
            TestableValidator::TestableMostFrequentViramaScript({0x964, 0xc05, 0x965, 0x965}));
}