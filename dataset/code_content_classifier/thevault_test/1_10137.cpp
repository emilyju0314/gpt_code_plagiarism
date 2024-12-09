int32_t RTCPReceiver::TMMBRReceived(uint32_t size,
                                    uint32_t accNumCandidates,
                                    TMMBRSet* candidateSet) const {
  CriticalSectionScoped lock(_criticalSectionRTCPReceiver);

  std::map<uint32_t, RTCPReceiveInformation*>::const_iterator
      receiveInfoIt = _receivedInfoMap.begin();
  if (receiveInfoIt == _receivedInfoMap.end()) {
    return -1;
  }
  uint32_t num = accNumCandidates;
  if (candidateSet) {
    while( num < size && receiveInfoIt != _receivedInfoMap.end()) {
      RTCPReceiveInformation* receiveInfo = receiveInfoIt->second;
      if (receiveInfo == NULL) {
        return 0;
      }
      for (uint32_t i = 0;
           (num < size) && (i < receiveInfo->TmmbrSet.lengthOfSet()); i++) {
        if (receiveInfo->GetTMMBRSet(i, num, candidateSet,
                                     _clock->TimeInMilliseconds()) == 0) {
          num++;
        }
      }
      receiveInfoIt++;
    }
  } else {
    while (receiveInfoIt != _receivedInfoMap.end()) {
      RTCPReceiveInformation* receiveInfo = receiveInfoIt->second;
      if(receiveInfo == NULL) {
        return -1;
      }
      num += receiveInfo->TmmbrSet.lengthOfSet();
      receiveInfoIt++;
    }
  }
  return num;
}