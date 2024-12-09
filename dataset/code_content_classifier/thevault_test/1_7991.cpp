uint64_t DeviceIntf::getWordCountAIETs2mm(uint64_t index)
  {
    if(index >= mAieTraceDmaList.size())
      return 0;
    return mAieTraceDmaList[index]->getWordCount();
  }