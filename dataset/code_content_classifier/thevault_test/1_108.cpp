std::vector<float> StuckCheck::collectStationVariableData(
    std::vector<size_t>::const_iterator stationObsIndicesBegin,
    std::vector<size_t>::const_iterator stationObsIndicesEnd,
    const std::vector<size_t> &validObsIds,
    const std::vector<float> &globalData) const {
  std::vector<float> stationData;
  stationData.reserve(stationObsIndicesEnd - stationObsIndicesBegin);
  size_t observationNumber = 0;
  for (std::vector<size_t>::const_iterator it = stationObsIndicesBegin;
       it != stationObsIndicesEnd; ++it) {
    const size_t obsId = validObsIds.at(*it);
    stationData.push_back(globalData[obsId]);
    observationNumber++;
  }
  return stationData;
}