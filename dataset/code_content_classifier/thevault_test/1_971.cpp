void UDPService::stopMyself_ ()
{
  closeNetworkPort_();
  Service::stopMyself_();
}