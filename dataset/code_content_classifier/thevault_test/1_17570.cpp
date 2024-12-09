void SickScanCommonNw::copyFrameToResposeBuffer(UINT32 frameLength)
{
  printInfoMessage("SickScanCommonNw::copyFrameToResposeBuffer: Copying a frame of " + ::toString(frameLength) +
                   " bytes to response buffer.", m_beVerbose);

  if (frameLength <= sizeof(m_responseBuffer))
  {
    // Wir duerfen kopieren
    memcpy(m_responseBuffer, m_receiveBuffer, frameLength);
    m_numberOfBytesInResponseBuffer = frameLength;
  }
  else
  {
    // Der respose-Buffer ist zu klein
    printError("SickScanCommonNw::copyFrameToResposeBuffer: Failed to copy frame (Length=" + ::toString(frameLength) +
               " bytes) to response buffer because the response buffer is too small (buffer size=" +
               ::toString(sizeof(m_responseBuffer)) + " bytes).");
    m_numberOfBytesInResponseBuffer = 0;
  }
}