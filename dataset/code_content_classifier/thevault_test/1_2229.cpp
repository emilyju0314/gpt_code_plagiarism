TEST_F(
    L2CAP_BrEdrDynamicChannelTest,
    DisconnectWhenInboundConfigReqReceivedBeforeOutboundConfigReqSentModeInInboundUnacceptableParamsConfigRspDoesNotMatchPeerConfigReq) {
  EXPECT_OUTBOUND_REQ(*sig(), kConnectionRequest, kConnReq.view(),
                      {SignalingChannel::Status::kSuccess, kOkConnRsp.view()});
  EXPECT_OUTBOUND_REQ(
      *sig(), kConfigurationRequest, kOutboundConfigReqWithErtm.view(),
      {SignalingChannel::Status::kSuccess, kInboundUnacceptableParamsWithRFCBasicConfigRsp.view()});
  EXPECT_OUTBOUND_REQ(*sig(), kDisconnectionRequest, kDisconReq.view(),
                      {SignalingChannel::Status::kSuccess, kDisconRsp.view()});

  int open_cb_count = 0;
  auto open_cb = [&open_cb_count](const DynamicChannel* chan) {
    if (open_cb_count == 0) {
      EXPECT_FALSE(chan);
    }
    open_cb_count++;
  };

  registry()->OpenOutbound(kPsm, std::move(open_cb), kERTMChannelParams);

  RETURN_IF_FATAL(RunLoopUntilIdle());

  // Receive inbound config request.
  RETURN_IF_FATAL(
      sig()->ReceiveExpect(kConfigurationRequest, kInboundConfigReqWithERTM, kOutboundOkConfigRsp));

  sig()->ReceiveResponses(ext_info_transaction_id(), {{SignalingChannel::Status::kSuccess,
                                                       kExtendedFeaturesInfoRspWithERTM.view()}});
  // Send outbound config request.
  RunLoopUntilIdle();
  EXPECT_EQ(1, open_cb_count);
}