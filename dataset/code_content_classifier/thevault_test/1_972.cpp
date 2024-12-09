void UDPService::openNetworkPort_ ()
{
  //
  // Disable interrupts on socket
  //
  socketNotice_.disable();

  closeNetworkPort_();
  
  try {
    socketNotice_.clearDescriptors();
    int_4 try_port = port_;
    if (UDPSocketLib::UDP_openPort(&myServer_, try_port) == 0) {
      if (try_port != port_) {
        port_ = try_port;
        //Port.value(port_);
      }
      private_->socket_fd = UDPSocketLib::descriptorForServer(server_());

      //
      // Enable socket interrupts
      //
      socketNotice_.addDescriptor(UDPSocketLib::descriptorForServer(server_()));
      socketNotice_.enable();

      isOpen_ = true;

        log_.message("UDPService:: Opened UDP port: <" + Identifier() + ">;  "+
                     "Socket fd= <"+Stringize(UDPSocketLib::descriptorForServer(server_()))+">");
    }
  } catch (const SocketLowLevelEx& e) {
    log_.noteException(e);
    log_.warning("UDPService:: Unable to open UDP port: <" + Identifier() + ">");
    closeNetworkPort_();
  }
}