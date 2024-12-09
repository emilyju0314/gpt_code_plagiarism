void UDPService::startup_ () 
{

  Service::startup_();

  port_               = Port.value();
  remotePort_         = RemotePort.value();
  remoteHost_         = RemoteHost.value();

  Host.post(ThisHostName());
  host_               = Host.value();
  //Port.value(port_);
  //RemoteHost.value(remoteHost_);
  //RemotePort.value(remotePort_);

  char  hname[64];
  int_4 stat = UDPSocketLib::UDP_findHostByName(remoteHost_.c_str(), 
                                                hname, 
                                                sizeof(hname), 
                                                &remoteAddr_);
  if (stat < 0) {
      log_.error("UDPService:: Hostname lookup FAILED; remoteHost_= <" +
                 remoteHost_ + ">");
    validRemoteHost_ = false;
  } else
    validRemoteHost_ = true;

  remoteAddr_.sin_port = htons((u_short) remotePort_);


  stat = UDPSocketLib::UDP_findHostByName(host_.c_str(), 
                                          hname, 
                                          sizeof(hname), 
                                          &localAddr_);
  if (stat < 0) {
      log_.error("UDPService:: Lookup FAILED for local host; host_= <" +
                 host_ + ">");
    validLocalHost_ = false;
  } else
    validLocalHost_ = true;

  localAddr_.sin_port = htons((u_short) port_);

  openNetworkPort_();

}