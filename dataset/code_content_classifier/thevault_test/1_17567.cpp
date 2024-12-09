void SickScanCommonNw::closeTcpConnection()
{
  if (m_tcp.isOpen())
  {
    m_tcp.close();
  }
}