TEST_F(BufferedSpdyFramerTest, OnAltSvcOnNonzeroStream) {
  const spdy::SpdyStreamId altsvc_stream_id(1);
  spdy::SpdyAltSvcIR altsvc_ir(altsvc_stream_id);
  spdy::SpdyAltSvcWireFormat::AlternativeService alternative_service(
      "quic", "alternative.example.org", 443, 86400,
      spdy::SpdyAltSvcWireFormat::VersionVector());
  altsvc_ir.add_altsvc(alternative_service);
  NetLogWithSource net_log;
  BufferedSpdyFramer framer(kMaxHeaderListSizeForTest, net_log);
  spdy::SpdySerializedFrame altsvc_frame(framer.SerializeFrame(altsvc_ir));

  TestBufferedSpdyVisitor visitor;
  visitor.SimulateInFramer(altsvc_frame);
  EXPECT_EQ(0, visitor.error_count_);
  EXPECT_EQ(1, visitor.altsvc_count_);
  EXPECT_EQ(altsvc_stream_id, visitor.altsvc_stream_id_);
  EXPECT_TRUE(visitor.altsvc_origin_.empty());
  ASSERT_EQ(1u, visitor.altsvc_vector_.size());
  EXPECT_EQ(alternative_service, visitor.altsvc_vector_[0]);
}