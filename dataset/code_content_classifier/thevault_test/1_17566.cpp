bool SickScanCommonNw::openTcpConnection()
{
  //  printInfoMessage("SickScanCommonNw::openTcpConnection: Connecting TCP/IP connection to " + m_ipAddress + ":" + toString(m_portNumber) + " ...", m_beVerbose);

  bool success = m_tcp.open(m_ipAddress, m_portNumber, m_beVerbose);
  if (success == false)
  {
    // printError("SickScanCommonNw::openTcpConnection: ERROR: Failed to establish TCP connection, aborting!");
    return false;
  }

  return true;
}