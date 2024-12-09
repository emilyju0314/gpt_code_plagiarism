TEST_F(L2CAP_BrEdrDynamicChannelTest, PreferredModeIsERTMButERTMIsNotInPeerFeatureMask) {
  EXPECT_OUTBOUND_REQ(*sig(), kConnectionRequest, kConnReq.view(),
                      {SignalingChannel::Status::kSuccess, kOkConnRsp.view()});
  EXPECT_OUTBOUND_REQ(*sig(), kConfigurationRequest, kOutboundConfigReq.view(),
                      {SignalingChannel::Status::kSuccess, kInboundEmptyConfigRsp.view()});
  EXPECT_OUTBOUND_REQ(*sig(), kDisconnectionRequest, kDisconReq.view(),
                      {SignalingChannel::Status::kSuccess, kDisconRsp.view()});

  registry()->OpenOutbound(
      kPsm, [](auto chan) {}, kERTMChannelParams);

  RETURN_IF_FATAL(RunLoopUntilIdle());

  // Receive features mask without ERTM bit set.
  sig()->ReceiveResponses(ext_info_transaction_id(),
                          {{SignalingChannel::Status::kSuccess, kExtendedFeaturesInfoRsp.view()}});
}