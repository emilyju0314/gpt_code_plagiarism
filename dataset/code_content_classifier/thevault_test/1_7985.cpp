size_t DeviceIntf::readTrace(xclTraceResultsVector& traceVector)
  {
    if (mVerbose) {
      std::cout << __func__ << ", " << std::this_thread::get_id()
                << ", " << &traceVector
                << ", Reading device trace stream..." << std::endl;
    }

    traceVector.mLength = 0;
    if (!mIsDeviceProfiling || !mFifoRead)
   	  return 0;

    size_t size = 0;
    size += mFifoRead->readTrace(traceVector, getTraceCount());

    return size;
  }