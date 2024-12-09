void DeviceIntf::parseTraceData(void* traceData, uint64_t bytes, xclTraceResultsVector& traceVector)
  {
    if(mPlTraceDma) {
      mPlTraceDma->parseTraceBuf(traceData, bytes, traceVector);
    }
  }