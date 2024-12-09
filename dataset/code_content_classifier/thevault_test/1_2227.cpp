TEST_F(L2CAP_BrEdrDynamicChannelTest,
       RenegotiateChannelModeAfterPeerRequestsBasicModeAndRejectsERTM) {
  EXPECT_OUTBOUND_REQ(*sig(), kConnectionRequest, kConnReq.view(),
                      {SignalingChannel::Status::kSuccess, kOkConnRsp.view()});
  auto config_req_id =
      EXPECT_OUTBOUND_REQ(*sig(), kConfigurationRequest, kOutboundConfigReqWithErtm.view());

  int open_cb_count = 0;

  auto open_cb = [&open_cb_count](const DynamicChannel* chan) {
    if (open_cb_count == 0) {
      ASSERT_TRUE(chan);
      EXPECT_TRUE(chan->IsOpen());
    }
    open_cb_count++;
  };

  registry()->OpenOutbound(kPsm, std::move(open_cb), kERTMChannelParams);

  RunLoopUntilIdle();

  sig()->ReceiveResponses(ext_info_transaction_id(), {{SignalingChannel::Status::kSuccess,
                                                       kExtendedFeaturesInfoRspWithERTM.view()}});
  RunLoopUntilIdle();

  // Peer requests basic mode.
  RETURN_IF_FATAL(
      sig()->ReceiveExpect(kConfigurationRequest, kInboundConfigReq, kOutboundOkConfigRsp));
  RunLoopUntilIdle();

  // New config request requesting basic mode should be sent in response to unacceptable params
  // response.
  EXPECT_OUTBOUND_REQ(*sig(), kConfigurationRequest, kOutboundConfigReq.view(),
                      {SignalingChannel::Status::kSuccess, kInboundEmptyConfigRsp.view()});
  sig()->ReceiveResponses(config_req_id,
                          {{SignalingChannel::Status::kSuccess,
                            kInboundUnacceptableParamsWithRFCBasicConfigRsp.view()}});

  RunLoopUntilIdle();
  EXPECT_EQ(1, open_cb_count);

  EXPECT_OUTBOUND_REQ(*sig(), kDisconnectionRequest, kDisconReq.view(),
                      {SignalingChannel::Status::kSuccess, kDisconRsp.view()});
}