TEST_F(L2CAP_BrEdrDynamicChannelTest, PeerRejectsERTM) {
  EXPECT_OUTBOUND_REQ(*sig(), kConnectionRequest, kConnReq.view(),
                      {SignalingChannel::Status::kSuccess, kOkConnRsp.view()});
  EXPECT_OUTBOUND_REQ(
      *sig(), kConfigurationRequest, kOutboundConfigReqWithErtm.view(),
      {SignalingChannel::Status::kSuccess, kInboundUnacceptableParamsWithRFCBasicConfigRsp.view()});
  EXPECT_OUTBOUND_REQ(*sig(), kConfigurationRequest, kOutboundConfigReq.view(),
                      {SignalingChannel::Status::kSuccess, kInboundEmptyConfigRsp.view()});
  EXPECT_OUTBOUND_REQ(*sig(), kDisconnectionRequest, kDisconReq.view(),
                      {SignalingChannel::Status::kSuccess, kDisconRsp.view()});

  int open_cb_count = 0;

  auto open_cb = [&open_cb_count](const DynamicChannel* chan) {
    if (open_cb_count == 0) {
      ASSERT_TRUE(chan);
      EXPECT_TRUE(chan->IsOpen());
    }
    open_cb_count++;
  };

  registry()->OpenOutbound(kPsm, std::move(open_cb), kERTMChannelParams);

  RETURN_IF_FATAL(RunLoopUntilIdle());

  sig()->ReceiveResponses(ext_info_transaction_id(), {{SignalingChannel::Status::kSuccess,
                                                       kExtendedFeaturesInfoRspWithERTM.view()}});

  RETURN_IF_FATAL(
      sig()->ReceiveExpect(kConfigurationRequest, kInboundConfigReq, kOutboundOkConfigRsp));

  RunLoopUntilIdle();
  EXPECT_EQ(1, open_cb_count);
}