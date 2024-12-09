int_4 UDPService::write (const void*        buf, 
                         const int_4        bytes)
{ 
  int_u4               flags (0);   
  int_4                addrlen = sizeof(remoteAddr_);
  int_4                NumBytes = -1;

  if (validRemoteHost_) {
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
                                           &remoteAddr_, 
                                           addrlen);

    } catch (const SocketLowLevelEx& e) {
        log_.error ("UDPService::[write]- Failed UDP write to <"+ RemoteIdentifier() + ">");
        log_.error ("UDPService::[write]- " + e.problem());
      }

  } else {
    log_.warning("UDPService::[write]- Invalid RemoteHost; Unable to write to <" + 
                 RemoteIdentifier() + ">");
  }

  return NumBytes;

}