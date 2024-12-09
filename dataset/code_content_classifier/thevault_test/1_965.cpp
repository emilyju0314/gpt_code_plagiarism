void UDPService::SetRemoteHost (const string& s)
{
  remoteHost_ = s;
  RemoteHost.value(remoteHost_);
}