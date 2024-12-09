void DeviceIntf::initAIETs2mm(uint64_t bufSz, uint64_t bufAddr, uint64_t index)
  {
    if(index >= mAieTraceDmaList.size())
      return;
    mAieTraceDmaList[index]->init(bufSz, bufAddr, false);
  }