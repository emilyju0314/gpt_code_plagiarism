void UDPService::incomingData_ ()
{ 
  int_u1               buffer[8192];
  int_4                length = sizeof(buffer);
  int_u4               flags (0);   
  struct  sockaddr_in  client_addr;
  int_4                addrlen = sizeof(client_addr);
  int_4                NumBytes;


  try {
    //
    // recv()
    // recvfrom() returns;  n > 0:  # bytes read
    //                      n = 0:  no msg/datagram avail (UNBLOCKED);
    //                              we do NOT use UNBLOCKED reads though..
    //                              or peer has done orderly shutdown (TCP only)
    //                      n < 0:  "something wicked this way comes..."
    //                              sets errno; throws exception
    //
        NumBytes = UDPSocketLib::UDP_recvFrom   (private_->socket_fd,
                                                 (unsigned char *)buffer, 
                                                 length, 
                                                 flags, 
                                                 &client_addr, 
                                                 addrlen);
        if (NumBytes > 0) {
          char  clientHost[64];
          int_4 len = sizeof(clientHost);
          UDPSocketLib::UDP_getHostByAddr (clientHost, len, &client_addr);
          string name (clientHost);
          log_.message("incomingData_::[UDP_recvFrom <clientAddr>]  NumBytes= " + 
                       Stringize(NumBytes) + ";  from <" + name + "(" + 
                       inet_ntoa(client_addr.sin_addr) + ")" + ":"+
                       Stringize(ntohs(client_addr.sin_port)) + ">");
        }

  } catch (const SocketLowLevelEx& e) {
      log_.error ("UDPService::[incomingData_]- Read error; "+e.problem());
    }

  //
  // No data...
  //
  if (NumBytes == 0) {
    log_.message("UDPService::[incomingData_]- No Data");
    //closeNetworkPort_();
  }
  //
  // ERROR- UDP socket read error
  //
  else if (NumBytes < 0) {
    log_.error("UDPService::[incomingData_]- UDP socket read error; closing port...");
    closeNetworkPort_();
  }
  
  debugUDPOutput_ ((unsigned char *)buffer, NumBytes);

}