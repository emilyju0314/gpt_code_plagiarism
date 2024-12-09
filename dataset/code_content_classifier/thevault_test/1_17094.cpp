TEST_F(HttpPriorityDependencyTest, Complex) {
  const spdy::SpdyStreamId first_id = GetId();
  const spdy::SpdyStreamId second_id = GetId();
  const spdy::SpdyStreamId third_id = GetId();
  const spdy::SpdyStreamId fourth_id = GetId();
  const spdy::SpdyStreamId fifth_id = GetId();
  const spdy::SpdyStreamId sixth_id = GetId();
  const spdy::SpdyStreamId seventh_id = GetId();
  const spdy::SpdyStreamId eighth_id = GetId();
  const spdy::SpdyStreamId nineth_id = GetId();
  const spdy::SpdyStreamId tenth_id = GetId();

  TestStreamCreation(first_id, HIGHEST, 0u);
  TestStreamCreation(second_id, MEDIUM, first_id);
  TestStreamCreation(third_id, MEDIUM, second_id);
  OnStreamDestruction(first_id);
  TestStreamCreation(fourth_id, MEDIUM, third_id);
  TestStreamCreation(fifth_id, LOWEST, fourth_id);
  TestStreamCreation(sixth_id, MEDIUM, fourth_id);
  OnStreamDestruction(third_id);
  TestStreamCreation(seventh_id, MEDIUM, sixth_id);
  TestStreamCreation(eighth_id, LOW, seventh_id);
  OnStreamDestruction(second_id);
  OnStreamDestruction(fourth_id);
  OnStreamDestruction(fifth_id);
  OnStreamDestruction(sixth_id);
  OnStreamDestruction(seventh_id);
  TestStreamCreation(nineth_id, MEDIUM, 0u);
  TestStreamCreation(tenth_id, HIGHEST, 0u);
}