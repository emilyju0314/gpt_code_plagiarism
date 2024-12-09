TYPED_TEST(ObserverListPerfTest, NotifyPerformance) {
  constexpr int kMaxObservers = 128;
#if DCHECK_IS_ON()
  // The test takes about 100x longer in debug builds, mostly due to sequence
  // checker overheads when WeakPtr gets involved.
  constexpr int kLaps = 1000000;
#else
  constexpr int kLaps = 100000000;
#endif
  constexpr int kWarmupLaps = 100;
  std::vector<std::unique_ptr<TypeParam>> observers;

  for (int observer_count = 0; observer_count <= kMaxObservers;
       observer_count = observer_count ? observer_count * 2 : 1) {
    typename TestFixture::ObserverListType list;
    for (int i = 0; i < observer_count; ++i)
      observers.push_back(std::make_unique<TypeParam>());
    for (auto& o : observers)
      list.AddObserver(o.get());

    for (int i = 0; i < kWarmupLaps; ++i) {
      for (auto& o : list)
        o.Observe();
    }
    g_observer_list_perf_test_counter = 0;
    const int weighted_laps = kLaps / (observer_count + 1);

    TimeTicks start = TimeTicks::Now();
    for (int i = 0; i < weighted_laps; ++i) {
      for (auto& o : list)
        o.Observe();
    }
    TimeDelta duration = TimeTicks::Now() - start;

    observers.clear();

    EXPECT_EQ(observer_count * weighted_laps,
              g_observer_list_perf_test_counter);
    EXPECT_TRUE(observer_count == 0 || !list.empty());

    std::string story_name =
        base::StringPrintf("%s_%d", Pick<TypeParam>::GetName(), observer_count);

    // A typical value is 3-20 nanoseconds per observe in Release, 1000-2000ns
    // in an optimized build with DCHECKs and 3000-6000ns in debug builds.
    auto reporter = SetUpReporter(story_name);
    reporter.AddResult(
        kMetricNotifyTimePerObserver,
        duration.InNanoseconds() /
            static_cast<double>(g_observer_list_perf_test_counter +
                                weighted_laps));
  }
}