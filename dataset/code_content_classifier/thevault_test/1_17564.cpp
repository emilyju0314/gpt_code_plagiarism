bool SickScanCommonNw::disconnect()
{
  closeTcpConnection();

  // Change back to CONSTRUCTED
  m_state = CONSTRUCTED;
  return true;
}