void Cubic::onPacketAckedInSteady(const AckEvent& ack) {
  if (isAppLimited()) {
    if (conn_.qLogger) {
      conn_.qLogger->addCongestionMetricUpdate(
          conn_.lossState.inflightBytes,
          getCongestionWindow(),
          kAckInQuiescence,
          cubicStateToString(state_).str());
    }
    return;
  }
  // TODO: There is a tradeoff between getting an accurate Cwnd by frequently
  // calculating it, and the CPU usage cost. This is worth experimenting. E.g.,
  // Chromium has an option to skips the cwnd calculation if it's configured to
  // NOT to update cwnd after every ack, and cwnd hasn't changed since last ack,
  // and time elapsed is smaller than 30ms since last Ack.
  // TODO: It's worth experimenting to use the larger one between cwndBytes_ and
  // lastMaxCwndBytes as the W_max, i.e., always refresh Wmax = cwnd during max
  // probing
  if (!steadyState_.lastMaxCwndBytes) {
    // lastMaxCwndBytes won't be set when we transit from Hybrid to Steady. In
    // that case, we are at the "origin" already.
    if (conn_.qLogger) {
      conn_.qLogger->addCongestionMetricUpdate(
          conn_.lossState.inflightBytes,
          getCongestionWindow(),
          kResetTimeToOrigin,
          cubicStateToString(state_).str());
    }
    steadyState_.timeToOrigin = 0.0;
    steadyState_.lastMaxCwndBytes = cwndBytes_;
    steadyState_.originPoint = cwndBytes_;
    if (steadyState_.tcpFriendly) {
      steadyState_.estRenoCwnd = cwndBytes_;
    }
  } else if (
      !steadyState_.originPoint ||
      *steadyState_.originPoint != *steadyState_.lastMaxCwndBytes) {
    updateTimeToOrigin();
  }
  if (!steadyState_.lastReductionTime) {
    steadyState_.lastReductionTime = ack.ackTime;
    if (conn_.qLogger) {
      conn_.qLogger->addCongestionMetricUpdate(
          conn_.lossState.inflightBytes,
          getCongestionWindow(),
          kResetLastReductionTime,
          cubicStateToString(state_).str());
    }
  }
  uint64_t newCwnd = calculateCubicCwnd(calculateCubicCwndDelta(ack.ackTime));

  if (newCwnd < cwndBytes_) {
    VLOG(10) << "Cubic steady state calculates a smaller cwnd than last round"
             << ", new cnwd = " << newCwnd << ", current cwnd = " << cwndBytes_;
  } else {
    cwndBytes_ = newCwnd;
  }
  // Reno cwnd estimation for TCP friendly.
  if (steadyState_.tcpFriendly && ack.ackedBytes) {
    /* If tcpFriendly is false, we don't keep track of estRenoCwnd. Right now we
       don't provide an API to change tcpFriendly in the middle of a connection.
       If you change that and start to provide an API to mutate tcpFriendly, you
       should calculate estRenoCwnd even when tcpFriendly is false. */
    steadyState_.estRenoCwnd += steadyState_.tcpEstimationIncreaseFactor *
        ack.ackedBytes * conn_.udpSendPacketLen / steadyState_.estRenoCwnd;
    steadyState_.estRenoCwnd = boundedCwnd(
        steadyState_.estRenoCwnd,
        conn_.udpSendPacketLen,
        conn_.transportSettings.maxCwndInMss,
        conn_.transportSettings.minCwndInMss);
    cwndBytes_ = std::max(cwndBytes_, steadyState_.estRenoCwnd);
    if (conn_.qLogger) {
      conn_.qLogger->addCongestionMetricUpdate(
          conn_.lossState.inflightBytes,
          getCongestionWindow(),
          kRenoCwndEstimation,
          cubicStateToString(state_).str());
    }
  }
}