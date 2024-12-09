UAbstractClient::error_type
  UAbstractClient::startPack()
  {
    sendBufferLock.lock();
    return 0;
  }