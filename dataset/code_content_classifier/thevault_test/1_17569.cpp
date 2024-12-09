void SickScanCommonNw::processFrame(SopasEventMessage &frame)
{

  if (m_protocol == CoLa_A)
  {
    printInfoMessage(
        "SickScanCommonNw::processFrame: Calling processFrame_CoLa_A() with " + ::toString(frame.size()) + " bytes.",
        m_beVerbose);
    // processFrame_CoLa_A(frame);
  }
  else if (m_protocol == CoLa_B)
  {
    printInfoMessage(
        "SickScanCommonNw::processFrame: Calling processFrame_CoLa_B() with " + ::toString(frame.size()) + " bytes.",
        m_beVerbose);
    // processFrame_CoLa_B(frame);
  }
}