int32_t RTCPReceiver::StatisticsReceived(
    std::vector<RTCPReportBlock>* receiveBlocks) const {
  assert(receiveBlocks);
  CriticalSectionScoped lock(_criticalSectionRTCPReceiver);
  ReportBlockMap::const_iterator it = _receivedReportBlockMap.begin();
  for (; it != _receivedReportBlockMap.end(); ++it) {
    const ReportBlockInfoMap* info_map = &(it->second);
    ReportBlockInfoMap::const_iterator it_info = info_map->begin();
    for (; it_info != info_map->end(); ++it_info) {
      receiveBlocks->push_back(it_info->second->remoteReceiveBlock);
    }
  }
  return 0;
}