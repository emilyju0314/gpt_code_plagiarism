uint64 PZGHeartbeatThreadState :: GetEstimatedLatencyToPeer(const ZGPeerID & peerID) const
{
   MutexGuard mg(_mainThreadLatenciesLock);
   return _mainThreadLatencies.GetWithDefault(peerID, MUSCLE_TIME_NEVER);
}