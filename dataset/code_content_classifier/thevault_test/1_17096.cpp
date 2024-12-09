TEST_F(HttpPriorityDependencyTest, UpdateThreeStreams) {
  const spdy::SpdyStreamId first_id = GetId();
  const spdy::SpdyStreamId second_id = GetId();
  const spdy::SpdyStreamId third_id = GetId();

  TestStreamCreation(first_id, HIGHEST, 0);
  TestStreamCreation(second_id, MEDIUM, first_id);
  TestStreamCreation(third_id, LOWEST, second_id);

  const int highest_weight = spdy::Spdy3PriorityToHttp2Weight(HIGHEST);
  const int medium_weight = spdy::Spdy3PriorityToHttp2Weight(MEDIUM);
  const int lowest_weight = spdy::Spdy3PriorityToHttp2Weight(LOWEST);

  std::vector<ExpectedDependencyUpdate> empty;

  // no-op: still at top.
  TestStreamUpdate(first_id, HIGHEST, empty);

  // no-op: still below first.
  TestStreamUpdate(second_id, MEDIUM, empty);

  // no-op: still below second.
  TestStreamUpdate(third_id, LOWEST, empty);

  // second moves to top, first moves below second.
  TestStreamUpdate(
      first_id, MEDIUM,
      {{second_id, 0, medium_weight}, {first_id, second_id, medium_weight}});

  // third moves to top.
  TestStreamUpdate(third_id, HIGHEST, {{third_id, 0, highest_weight}});

  // third moves to bottom.
  TestStreamUpdate(
      third_id, LOWEST,
      {{second_id, 0, medium_weight}, {third_id, first_id, lowest_weight}});

  // first moves to top.
  TestStreamUpdate(
      first_id, HIGHEST,
      {{third_id, second_id, lowest_weight}, {first_id, 0, highest_weight}});
}