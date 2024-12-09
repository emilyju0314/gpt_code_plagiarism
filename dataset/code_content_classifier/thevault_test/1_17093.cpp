TEST_F(HttpPriorityDependencyTest, SomeCompletions) {
  const spdy::SpdyStreamId first_id = GetId();
  const spdy::SpdyStreamId second_id = GetId();
  const spdy::SpdyStreamId third_id = GetId();

  TestStreamCreation(first_id, HIGHEST, 0u);
  TestStreamCreation(second_id, MEDIUM, first_id);
  OnStreamDestruction(second_id);
  TestStreamCreation(third_id, LOWEST, first_id);
}