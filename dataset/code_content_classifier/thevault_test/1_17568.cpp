void SickScanCommonNw::readCallbackFunction(UINT8 *buffer, UINT32 &numOfBytes)
{
  bool beVerboseHere = false;
  printInfoMessage(
      "SickScanCommonNw::readCallbackFunction(): Called with " + toString(numOfBytes) + " available bytes.",
      beVerboseHere);

  ScopedLock lock(&m_receiveDataMutex); // Mutex for access to the input buffer
  UINT32 remainingSpace = sizeof(m_receiveBuffer) - m_numberOfBytesInReceiveBuffer;
  UINT32 bytesToBeTransferred = numOfBytes;
  if (remainingSpace < numOfBytes)
  {
    bytesToBeTransferred = remainingSpace;
    // printWarning("SickScanCommonNw::readCallbackFunction(): Input buffer space is to small, transferring only " +
    //              ::toString(bytesToBeTransferred) + " of " + ::toString(numOfBytes) + " bytes.");
  }
  else
  {
    // printInfoMessage("SickScanCommonNw::readCallbackFunction(): Transferring " + ::toString(bytesToBeTransferred) +
    //                   " bytes from TCP to input buffer.", beVerboseHere);
  }

  if (bytesToBeTransferred > 0)
  {
    // Data can be transferred into our input buffer
    memcpy(&(m_receiveBuffer[m_numberOfBytesInReceiveBuffer]), buffer, bytesToBeTransferred);
    m_numberOfBytesInReceiveBuffer += bytesToBeTransferred;

    UINT32 size = 0;

    while (1)
    {
      // Now work on the input buffer until all received datasets are processed
      SopasEventMessage frame = findFrameInReceiveBuffer();

      size = frame.size();
      if (size == 0)
      {
        // Framesize = 0: There is no valid frame in the buffer. The buffer is either empty or the frame
        // is incomplete, so leave the loop
        printInfoMessage("SickScanCommonNw::readCallbackFunction(): No complete frame in input buffer, we are done.",
                         beVerboseHere);

        // Leave the loop
        break;
      }
      else
      {
        // A frame was found in the buffer, so process it now.
        printInfoMessage(
            "SickScanCommonNw::readCallbackFunction(): Processing a frame of length " + ::toString(frame.size()) +
            " bytes.", beVerboseHere);
        processFrame(frame);
      }
    }
  }
  else
  {
    // There was input data from the TCP interface, but our input buffer was unable to hold a single byte.
    // Either we have not read data from our buffer for a long time, or something has gone wrong. To re-sync,
    // we clear the input buffer here.
    m_numberOfBytesInReceiveBuffer = 0;
  }

}