int_4 UDPService::readFrom (void*               buf, 
                            const int_4         bytes,
                            const int_u4        flags,   
                            struct sockaddr_in* clientAddr, 
                            const int_4         clientAddrLength)
{ 
  int_4                NumBytes = -1;

  try {
    //
    // recvfrom() returns;  n > 0:  # bytes read
    //                      n = 0:  no msg avail or peer has done 
    //                              orderly shutdown (TCP only)
    //                      n < 0:  "something wicked this way comes..."
    //                              sets errno
    //
    NumBytes = UDPSocketLib::UDP_recvFrom   (private_->socket_fd,
                                             (unsigned char *)buf, 
                                             bytes, 
                                             flags, 
                                             clientAddr, 
                                             clientAddrLength);

  } catch (const SocketLowLevelEx& e) {
      log_.error ("UDPService::[readFrom]- Read error; "+e.problem());
    }

  // ERROR- UDP socket read error
  if (NumBytes < 0) {
    log_.error("UDPService::[readFrom] - Read error on UDP socket; Close port= <"+Stringize(port_)+"");
    closeNetworkPort_();
    //throw SocketLowLevelEx(identifier(), bytes);
  }


  return NumBytes;

}