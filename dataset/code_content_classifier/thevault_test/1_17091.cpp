TEST_F(HttpPriorityDependencyTest, DifferentPriorityDecreasing) {
  const spdy::SpdyStreamId first_id = GetId();
  const spdy::SpdyStreamId second_id = GetId();
  const spdy::SpdyStreamId third_id = GetId();

  TestStreamCreation(first_id, HIGHEST, 0u);
  TestStreamCreation(second_id, MEDIUM, first_id);
  TestStreamCreation(third_id, LOWEST, second_id);
}