TEST(LogUniformIntDistributionTest, StabilityTest) {
  using testing::ElementsAre;
  // absl::uniform_int_distribution stability relies on
  // absl::random_internal::LeadingSetBit, std::log, std::pow.
  absl::random_internal::sequence_urbg urbg(
      {0x0003eb76f6f7f755ull, 0xFFCEA50FDB2F953Bull, 0xC332DDEFBE6C5AA5ull,
       0x6558218568AB9702ull, 0x2AEF7DAD5B6E2F84ull, 0x1521B62829076170ull,
       0xECDD4775619F1510ull, 0x13CCA830EB61BD96ull, 0x0334FE1EAA0363CFull,
       0xB5735C904C70A239ull, 0xD59E9E0BCBAADE14ull, 0xEECC86BC60622CA7ull});

  std::vector<int> output(6);

  {
    absl::log_uniform_int_distribution<int32_t> dist(0, 256);
    std::generate(std::begin(output), std::end(output),
                  [&] { return dist(urbg); });
    EXPECT_THAT(output, ElementsAre(256, 66, 4, 6, 57, 103));
  }
  urbg.reset();
  {
    absl::log_uniform_int_distribution<int32_t> dist(0, 256, 10);
    std::generate(std::begin(output), std::end(output),
                  [&] { return dist(urbg); });
    EXPECT_THAT(output, ElementsAre(8, 4, 0, 0, 0, 69));
  }
}