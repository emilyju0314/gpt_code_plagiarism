TEST_F(HttpPriorityDependencyTest, UpdateComplex) {
  const spdy::SpdyStreamId first_id = GetId();
  const spdy::SpdyStreamId second_id = GetId();  // pushed
  const spdy::SpdyStreamId third_id = GetId();   // pushed
  const spdy::SpdyStreamId fourth_id = GetId();
  const spdy::SpdyStreamId fifth_id = GetId();
  const spdy::SpdyStreamId sixth_id = GetId();
  const spdy::SpdyStreamId seventh_id = GetId();

  TestStreamCreation(first_id, HIGHEST, 0u);
  TestStreamCreation(second_id, LOWEST, first_id);
  TestStreamCreation(third_id, LOWEST, second_id);
  TestStreamCreation(fourth_id, HIGHEST, first_id);
  TestStreamCreation(fifth_id, MEDIUM, fourth_id);
  TestStreamCreation(sixth_id, MEDIUM, fifth_id);
  TestStreamCreation(seventh_id, LOW, sixth_id);

  const int highest_weight = spdy::Spdy3PriorityToHttp2Weight(HIGHEST);
  const int medium_weight = spdy::Spdy3PriorityToHttp2Weight(MEDIUM);
  const int lowest_weight = spdy::Spdy3PriorityToHttp2Weight(LOWEST);

  // second matches a HIGHEST priority response.
  // 3 moves under 7
  // 2 moves under 4
  TestStreamUpdate(second_id, HIGHEST,
                   {{third_id, seventh_id, lowest_weight},
                    {second_id, fourth_id, highest_weight}});

  // third matches a MEDIUM priority response.
  // 3 moves under 6
  TestStreamUpdate(third_id, MEDIUM, {{third_id, sixth_id, medium_weight}});
}