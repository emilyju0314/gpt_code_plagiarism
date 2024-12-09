void UDPService::SetRemotePort (int_4 n)
{
  remotePort_ = n;
  RemotePort.value(remotePort_);
}