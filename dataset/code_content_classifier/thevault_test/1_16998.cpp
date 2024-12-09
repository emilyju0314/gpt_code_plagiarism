TEST(Time, ExtendedConversionSaturation) {
  const absl::TimeZone syd =
      absl::time_internal::LoadTimeZone("Australia/Sydney");
  const absl::TimeZone nyc =
      absl::time_internal::LoadTimeZone("America/New_York");
  const absl::Time max =
      absl::FromUnixSeconds(std::numeric_limits<int64_t>::max());
  absl::TimeZone::CivilInfo ci;
  absl::Time t;

  // The maximal time converted in each zone.
  ci = syd.At(max);
  EXPECT_CIVIL_INFO(ci, 292277026596, 12, 5, 2, 30, 7, 39600, true);
  t = absl::FromCivil(absl::CivilSecond(292277026596, 12, 5, 2, 30, 7), syd);
  EXPECT_EQ(max, t);
  ci = nyc.At(max);
  EXPECT_CIVIL_INFO(ci, 292277026596, 12, 4, 10, 30, 7, -18000, false);
  t = absl::FromCivil(absl::CivilSecond(292277026596, 12, 4, 10, 30, 7), nyc);
  EXPECT_EQ(max, t);

  // One second later should push us to infinity.
  t = absl::FromCivil(absl::CivilSecond(292277026596, 12, 5, 2, 30, 8), syd);
  EXPECT_EQ(absl::InfiniteFuture(), t);
  t = absl::FromCivil(absl::CivilSecond(292277026596, 12, 4, 10, 30, 8), nyc);
  EXPECT_EQ(absl::InfiniteFuture(), t);

  // And we should stick there.
  t = absl::FromCivil(absl::CivilSecond(292277026596, 12, 5, 2, 30, 9), syd);
  EXPECT_EQ(absl::InfiniteFuture(), t);
  t = absl::FromCivil(absl::CivilSecond(292277026596, 12, 4, 10, 30, 9), nyc);
  EXPECT_EQ(absl::InfiniteFuture(), t);

  // All the way up to a saturated date/time, without overflow.
  t = absl::FromCivil(absl::CivilSecond::max(), syd);
  EXPECT_EQ(absl::InfiniteFuture(), t);
  t = absl::FromCivil(absl::CivilSecond::max(), nyc);
  EXPECT_EQ(absl::InfiniteFuture(), t);
}