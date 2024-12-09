TEST_F(HttpPriorityDependencyTest, UpdateSingleStream) {
  const spdy::SpdyStreamId id = GetId();

  TestStreamCreation(id, HIGHEST, 0);

  std::vector<ExpectedDependencyUpdate> empty;
  TestStreamUpdate(id, HIGHEST, empty);
  TestStreamUpdate(id, MEDIUM, empty);
  TestStreamUpdate(id, LOWEST, empty);
  TestStreamUpdate(id, HIGHEST, empty);
}