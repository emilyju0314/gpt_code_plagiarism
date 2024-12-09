TEST_F(AlgorithmTest, Bidir) {
  {
    auto api = gurka::do_action(valhalla::Options::route, map, {"4", "0"}, "auto");
    EXPECT_EQ(api.trip().routes(0).legs(0).algorithms(0), "bidirectional_a*");
    EXPECT_EQ(speed_from_edge(api), constrained);
  }

  {
    auto api = gurka::do_action(valhalla::Options::route, map, {"A", "2"}, "auto",
                                {{"/date_time/type", "3"},
                                 {"/date_time/value", "2020-10-30T09:00"},
                                 {"/costing_options/auto/speed_types/0", "constrained"}});
    EXPECT_EQ(api.trip().routes(0).legs(0).algorithms(0), "bidirectional_a*");
    EXPECT_EQ(speed_from_edge(api), constrained);
  }

  {
    auto api = gurka::do_action(valhalla::Options::route, map, {"A", "2"}, "auto",
                                {{"/date_time/type", "3"},
                                 {"/date_time/value", "2020-10-30T09:00"},
                                 {"/costing_options/auto/speed_types/0", "predicted"}});
    EXPECT_EQ(api.trip().routes(0).legs(0).algorithms(0), "bidirectional_a*");
    EXPECT_EQ(speed_from_edge(api), historical);
  }

  {
    auto api = gurka::do_action(valhalla::Options::route, map, {"A", "2"}, "auto",
                                {{"/date_time/type", "3"},
                                 {"/date_time/value", "2020-10-30T09:00"},
                                 {"/costing_options/auto/speed_types/0", "current"}});
    EXPECT_EQ(api.trip().routes(0).legs(0).algorithms(0), "bidirectional_a*");
    EXPECT_EQ(speed_from_edge(api), current);
  }

  {
    auto api = gurka::do_action(valhalla::Options::route, map, {"A", "2"}, "auto",
                                {{"/date_time/type", "3"},
                                 {"/date_time/value", "2020-10-28T04:00"},
                                 {"/costing_options/auto/speed_types/0", "freeflow"}});
    EXPECT_EQ(api.trip().routes(0).legs(0).algorithms(0), "bidirectional_a*");
    EXPECT_EQ(speed_from_edge(api), freeflow);
  }
}