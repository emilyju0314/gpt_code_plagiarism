uint8_t DeviceIntf::getAIETs2mmMemIndex(uint64_t index)
  {
    if(index >= mAieTraceDmaList.size())
      return 0;
    return mAieTraceDmaList[index]->getMemIndex();
  }