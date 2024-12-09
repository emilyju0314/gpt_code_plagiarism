void SickScanCommonNw::removeFrameFromReceiveBuffer(UINT32 frameLength)
{
  // Remove frame from receive buffer
  if (frameLength < m_numberOfBytesInReceiveBuffer)
  {
    // More data in buffer, move them to the buffer start
    UINT32 newLen = m_numberOfBytesInReceiveBuffer - frameLength;
    printInfoMessage("SickScanCommonNw::removeFrameFromReceiveBuffer: Removing " + ::toString(frameLength) +
                     " bytes from the input buffer. New length is " + ::toString(newLen) + " bytes.", m_beVerbose);
    memmove(m_receiveBuffer, &(m_receiveBuffer[frameLength]), newLen);
    m_numberOfBytesInReceiveBuffer = newLen;
  }
  else
  {
    // No other data in buffer, just mark as empty
    printInfoMessage("SickScanCommonNw::removeFrameFromReceiveBuffer: Done, no more data in input buffer.",
                     m_beVerbose);
    m_numberOfBytesInReceiveBuffer = 0;
  }
}