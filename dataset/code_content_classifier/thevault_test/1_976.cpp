int_4 UDPService::writeTo (const void*         buf, 
                           const int_4         bytes,
                           struct sockaddr_in* clientAddr, 
                           const int_4         clientAddrLength)
{ 
  int_u4               flags (0);   
  int_4                NumBytes = -1;

    try {
      //
      // sendTo()   returns;  n > 0:  # bytes read
      //                      n = 0:  no data written; EWOULDBLOCK or EAGAIN
      //                              from NONBLOCK socket setting, maybe..
      //                      n < 0:  "something wicked this way comes..."
      //                              sets errno
      //
      NumBytes = UDPSocketLib::UDP_sendTo (private_->socket_fd,
                                           (unsigned char *)buf, 
                                           bytes, 
                                           flags, 
                                           clientAddr, 
                                           clientAddrLength);

    } catch (const SocketLowLevelEx& e) {
        char  clientHost[64];
        int_4 len = sizeof(clientHost);
        UDPSocketLib::UDP_getHostByAddr (clientHost, len, clientAddr);
        string name (clientHost);
        log_.error ("UDPService::[writeTo]- Failed UDP write to <" + 
                    name + " (" +
                    inet_ntoa(clientAddr->sin_addr) + "):"+
                    Stringize(ntohs(clientAddr->sin_port)) + ">");
        log_.error ("UDPService::[writeTo]- " + e.problem());
      }

    return NumBytes;

}