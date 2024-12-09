TEST_F(HttpPriorityDependencyTest, CompletionBeforeIssue) {
  const spdy::SpdyStreamId first_id = GetId();
  const spdy::SpdyStreamId second_id = GetId();
  const spdy::SpdyStreamId third_id = GetId();

  TestStreamCreation(first_id, HIGHEST, 0u);
  OnStreamDestruction(first_id);
  TestStreamCreation(second_id, MEDIUM, 0u);
  OnStreamDestruction(second_id);
  TestStreamCreation(third_id, LOWEST, 0u);
}