TEST_F(L2CAP_BrEdrDynamicChannelTest,
       DisconnectOnInconsistentChannelModeNegotiationFailureWhenLocalConfigResponseIsLast) {
  EXPECT_OUTBOUND_REQ(*sig(), kConnectionRequest, kConnReq.view(),
                      {SignalingChannel::Status::kSuccess, kOkConnRsp.view()});
  EXPECT_OUTBOUND_REQ(*sig(), kConfigurationRequest, kOutboundConfigReqWithErtm.view(),
                      {SignalingChannel::Status::kSuccess, kInboundEmptyConfigRsp.view()});
  EXPECT_OUTBOUND_REQ(*sig(), kDisconnectionRequest, kDisconReq.view(),
                      {SignalingChannel::Status::kSuccess, kDisconRsp.view()});

  int open_cb_count = 0;

  auto open_cb = [&open_cb_count](const DynamicChannel* chan) {
    if (open_cb_count == 0) {
      ASSERT_FALSE(chan);
    }
    open_cb_count++;
  };

  registry()->OpenOutbound(kPsm, std::move(open_cb), kERTMChannelParams);

  RETURN_IF_FATAL(RunLoopUntilIdle());

  // Peer requests basic mode.
  RETURN_IF_FATAL(
      sig()->ReceiveExpect(kConfigurationRequest, kInboundConfigReq, kOutboundOkConfigRsp));

  // Local device will request ERTM.
  sig()->ReceiveResponses(ext_info_transaction_id(), {{SignalingChannel::Status::kSuccess,
                                                       kExtendedFeaturesInfoRspWithERTM.view()}});
  // Request ERTM & Disconnect
  RunLoopUntilIdle();
  EXPECT_EQ(1, open_cb_count);
}