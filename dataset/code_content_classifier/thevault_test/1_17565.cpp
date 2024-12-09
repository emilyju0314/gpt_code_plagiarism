bool SickScanCommonNw::init(std::string ipAddress,
                            unsigned short portNumber,
                            Tcp::DisconnectFunction disconnectFunction,
                            void *obj)
{
  m_ipAddress = ipAddress;
  m_portNumber = portNumber;
  m_tcp.setDisconnectCallbackFunction(disconnectFunction, obj);
  return true;
}