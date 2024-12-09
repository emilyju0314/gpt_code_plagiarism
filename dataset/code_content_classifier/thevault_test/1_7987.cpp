uint64_t DeviceIntf::getWordCountTs2mm()
  {
    if(!mPlTraceDma)
      return 0;
    return mPlTraceDma->getWordCount();
  }