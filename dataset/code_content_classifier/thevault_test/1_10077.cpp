TEST_F(VideoSendStreamTest, MinTransmitBitrateRespectsRemb) {
  static const int kMinTransmitBitrateBps = 400000;
  static const int kHighBitrateBps = 150000;
  static const int kRembBitrateBps = 80000;
  static const int kRembRespectedBitrateBps = 100000;
  class BitrateObserver : public test::SendTest {
   public:
    BitrateObserver()
        : SendTest(kDefaultTimeoutMs),
          bitrate_capped_(false) {
    }

   private:
    virtual Action OnSendRtp(const uint8_t* packet, size_t length) {
      if (RtpHeaderParser::IsRtcp(packet, length))
        return DROP_PACKET;

      RTPHeader header;
      if (!parser_->Parse(packet, length, &header))
        return DROP_PACKET;
      RTC_DCHECK(stream_ != nullptr);
      VideoSendStream::Stats stats = stream_->GetStats();
      if (!stats.substreams.empty()) {
        EXPECT_EQ(1u, stats.substreams.size());
        int total_bitrate_bps =
            stats.substreams.begin()->second.total_bitrate_bps;
        test::PrintResult("bitrate_stats_",
                          "min_transmit_bitrate_low_remb",
                          "bitrate_bps",
                          static_cast<size_t>(total_bitrate_bps),
                          "bps",
                          false);
        if (total_bitrate_bps > kHighBitrateBps) {
          rtp_rtcp_->SetREMBData(kRembBitrateBps,
                                 std::vector<uint32_t>(1, header.ssrc));
          rtp_rtcp_->Process();
          bitrate_capped_ = true;
        } else if (bitrate_capped_ &&
                   total_bitrate_bps < kRembRespectedBitrateBps) {
          observation_complete_.Set();
        }
      }
      // Packets don't have to be delivered since the test is the receiver.
      return DROP_PACKET;
    }

    void OnVideoStreamsCreated(
        VideoSendStream* send_stream,
        const std::vector<VideoReceiveStream*>& receive_streams) override {
      stream_ = send_stream;
      RtpRtcp::Configuration config;
      config.outgoing_transport = feedback_transport_.get();
      rtp_rtcp_.reset(RtpRtcp::CreateRtpRtcp(config));
      rtp_rtcp_->SetREMBStatus(true);
      rtp_rtcp_->SetRTCPStatus(RtcpMode::kReducedSize);
    }

    void ModifyVideoConfigs(
        VideoSendStream::Config* send_config,
        std::vector<VideoReceiveStream::Config>* receive_configs,
        VideoEncoderConfig* encoder_config) override {
      feedback_transport_.reset(
          new internal::TransportAdapter(send_config->send_transport));
      feedback_transport_->Enable();
      encoder_config->min_transmit_bitrate_bps = kMinTransmitBitrateBps;
    }

    void PerformTest() override {
      EXPECT_TRUE(Wait())
          << "Timeout while waiting for low bitrate stats after REMB.";
    }

    rtc::scoped_ptr<RtpRtcp> rtp_rtcp_;
    rtc::scoped_ptr<internal::TransportAdapter> feedback_transport_;
    VideoSendStream* stream_;
    bool bitrate_capped_;
  } test;

  RunBaseTest(&test, FakeNetworkPipe::Config());
}