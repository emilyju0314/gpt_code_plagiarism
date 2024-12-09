TEST_F(HttpPriorityDependencyTest, DifferentPriorityIncreasing) {
  const spdy::SpdyStreamId first_id = GetId();
  const spdy::SpdyStreamId second_id = GetId();
  const spdy::SpdyStreamId third_id = GetId();

  TestStreamCreation(first_id, LOWEST, 0u);
  TestStreamCreation(second_id, MEDIUM, 0u);
  TestStreamCreation(third_id, HIGHEST, 0u);
}