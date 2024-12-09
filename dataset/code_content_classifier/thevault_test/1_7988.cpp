uint8_t DeviceIntf::getTS2MmMemIndex()
  {
    if(!mPlTraceDma)
      return 0;
    return mPlTraceDma->getMemIndex();
  }