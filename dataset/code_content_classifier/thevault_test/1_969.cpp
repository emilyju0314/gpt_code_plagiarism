void UDPService::postamble_ ()
{
  socketNotice_.disable();
  closeNetworkPort_();
  Service::postamble_();
}