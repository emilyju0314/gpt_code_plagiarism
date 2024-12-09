int_4 UDPService::writeTo (const void*         buf, 
                           const int_4         bytes,
                           const string        destHost,
                           const int_4         destPort)
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
                                           destHost, 
                                           destPort);

    } catch (const SocketLowLevelEx& e) {
        log_.error ("UDPService::[writeTo]- Failed UDP write to <" + 
                    destHost + ":" + Stringize(destPort) + ">");
        log_.error ("UDPService::[writeTo]- " + e.problem());
      }

    return NumBytes;

}