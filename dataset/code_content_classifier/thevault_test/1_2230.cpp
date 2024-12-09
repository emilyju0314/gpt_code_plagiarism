TEST_F(
    L2CAP_BrEdrDynamicChannelTest,
    DisconnectWhenInboundConfigReqReceivedAfterOutboundConfigReqSentAndModeInInboundUnacceptableParamsConfigRspDoesNotMatchPeerConfigReq) {
  EXPECT_OUTBOUND_REQ(*sig(), kConnectionRequest, kConnReq.view(),
                      {SignalingChannel::Status::kSuccess, kOkConnRsp.view()});
  const auto outbound_config_req_id =
      EXPECT_OUTBOUND_REQ(*sig(), kConfigurationRequest, kOutboundConfigReqWithErtm.view());
  EXPECT_OUTBOUND_REQ(*sig(), kDisconnectionRequest, kDisconReq.view(),
                      {SignalingChannel::Status::kSuccess, kDisconRsp.view()});

  int open_cb_count = 0;
  auto open_cb = [&open_cb_count](const DynamicChannel* chan) {
    if (open_cb_count == 0) {
      EXPECT_FALSE(chan);
    }
    open_cb_count++;
  };

  ChannelParameters params;
  params.mode = ChannelMode::kEnhancedRetransmission;
  registry()->OpenOutbound(kPsm, std::move(open_cb), params);

  RETURN_IF_FATAL(RunLoopUntilIdle());

  sig()->ReceiveResponses(ext_info_transaction_id(), {{SignalingChannel::Status::kSuccess,
                                                       kExtendedFeaturesInfoRspWithERTM.view()}});
  // Send outbound config request.
  RunLoopUntilIdle();

  // Receive inbound config request.
  RETURN_IF_FATAL(
      sig()->ReceiveExpect(kConfigurationRequest, kInboundConfigReqWithERTM, kOutboundOkConfigRsp));

  sig()->ReceiveResponses(outbound_config_req_id,
                          {{SignalingChannel::Status::kSuccess,
                            kInboundUnacceptableParamsWithRFCBasicConfigRsp.view()}});
  RunLoopUntilIdle();
  EXPECT_EQ(1, open_cb_count);
}