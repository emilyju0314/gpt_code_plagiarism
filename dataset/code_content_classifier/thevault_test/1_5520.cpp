TEST(ContinuousTimeSwendsenWang, Place_Cuts) {
    using namespace openjij;
    using TimeType = typename system::ContinuousTimeIsing<graph::Sparse<double>>::TimeType;
    using CutPoint = typename system::ContinuousTimeIsing<graph::Sparse<double>>::CutPoint;

    std::vector<CutPoint> timeline;
    timeline.emplace_back(1.0, 1);
    timeline.emplace_back(2.0, 2);
    timeline.emplace_back(3.0, 2);
    timeline.emplace_back(4.0, 3);
    timeline.emplace_back(5.0, 3);
    timeline.emplace_back(6.0, 4);
    timeline.emplace_back(7.0, 4);

    std::vector<TimeType> cuts { 0.5, 1.5, 3.5, 4.5, 5.5, 7.5, 8.5 };
    timeline = updater::ContinuousTimeSwendsenWang<system::ContinuousTimeIsing<graph::Sparse<double>>>::create_timeline(timeline, cuts);

    std::vector<CutPoint> correct_timeline;
    correct_timeline.emplace_back(0.5, 4);
    correct_timeline.emplace_back(1.0, 1);
    correct_timeline.emplace_back(1.5, 1);
    correct_timeline.emplace_back(2.0, 2);
    correct_timeline.emplace_back(3.5, 2);
    correct_timeline.emplace_back(4.0, 3);
    correct_timeline.emplace_back(4.5, 3);
    correct_timeline.emplace_back(5.5, 3);
    correct_timeline.emplace_back(6.0, 4);
    correct_timeline.emplace_back(7.5, 4);
    correct_timeline.emplace_back(8.5, 4);

    EXPECT_EQ(timeline, correct_timeline);
}