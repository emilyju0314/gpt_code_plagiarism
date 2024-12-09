void Cubic::onPersistentCongestion() {
  auto minCwnd = conn_.transportSettings.minCwndInMss * conn_.udpSendPacketLen;
  ssthresh_ = std::max(cwndBytes_ / 2, minCwnd);
  cwndBytes_ = minCwnd;
  if (steadyState_.tcpFriendly) {
    steadyState_.estRenoCwnd = 0;
  }
  steadyState_.lastReductionTime = folly::none;
  steadyState_.lastMaxCwndBytes = folly::none;
  quiescenceStart_ = folly::none;
  hystartState_.found = Cubic::HystartFound::No;
  hystartState_.inRttRound = false;

  state_ = CubicStates::Hystart;

  if (conn_.qLogger) {
    conn_.qLogger->addCongestionMetricUpdate(
        conn_.lossState.inflightBytes,
        getCongestionWindow(),
        kPersistentCongestion,
        cubicStateToString(state_).str());
  }
}