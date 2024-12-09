void UDPService::SetPort (int_4 n)
{
  port_ = n;
  Port.value(port_);
}