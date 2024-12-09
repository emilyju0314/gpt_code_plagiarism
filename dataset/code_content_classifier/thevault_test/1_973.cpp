bool UDPService::takeWakeUpCall_ (WakeCondition& waker)
{
  string reason = waker.groupID();

  //
  // Not sure if i want it here...
  //
  //acknowledge_();

  //
  // Port attribute change
  //
  if (reason == "PortChange") {
    int_4 NewPort = Port.value();
    closeNetworkPort_();
    port_ = NewPort;
    log_.message("UDPService:: Changed Port attribute = <" + 
		 Stringize(port_) + ">");
    openNetworkPort_();
    if (port_ != Port.value()) {
      Port.value(port_);
    }
    acknowledge_();
    return true;
  }

  //
  // process socket wake condition
  //   assume UDP datagram received...
  //
  else if (reason == "socket") {          // some socket condition
    incomingData_();
    acknowledge_();
    return true;
  }				

  //
  // process RemoteHost attribute change
  //
  else if (reason == "RemoteHostChange") {
    remoteHost_         = RemoteHost.value();
    log_.message ("UDPService:: Changed RemoteHost attribute = <"+remoteHost_+">");
    char  hname[64];
    int_4 stat = UDPSocketLib::UDP_findHostByName(remoteHost_.c_str(), 
                                                hname, 
                                                sizeof(hname), 
                                                &remoteAddr_);
    if (stat < 0) {
        log_.error("UDPService:: Hostname lookup FAILED; RemoteHost= <" +
                   remoteHost_ + ">");
      validRemoteHost_ = false;
    } else
      validRemoteHost_ = true;

    acknowledge_();

    return true;
  }

  //
  // process RemotePort attribute change
  //
  else if (reason == "RemotePortChange") {
    remotePort_         = RemotePort.value();
    remoteAddr_.sin_port = htons((u_short) remotePort_);
    log_.message("UDPService:: Changed RemotePort attribute = <" + 
		 Stringize(remotePort_) + ">");
    acknowledge_();
    return true;
  } else {

    log_.warning("UDPService:: Unknown WakeCondition \"" + reason + "\"");
  }


  return true;
}