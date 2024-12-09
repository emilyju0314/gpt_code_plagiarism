void CpuemShim::constructQueryTable() {
  if (xclemulation::config::getInstance()->getIsPlatformEnabled()) {
    mQueryTable[key_type::m2m] = mPlatformData.get<std::string>("plp.m2m");
    std::string dmaVal = mPlatformData.get<std::string>("plp.dma");
    mQueryTable[key_type::nodma] = (dmaVal == "none" ? "enabled" : "disabled");
  }
}