TEST_F(UDPTransportTest, ConstructorDoesNotCreateSocket) {
  int32_t id = 0;
  UdpTransportImpl::SocketFactoryInterface* null_maker = NULL;
  UdpSocketManager* null_manager = NULL;
  UdpTransport* transport = new UdpTransportImpl(id,
                                                 null_maker,
                                                 null_manager);
  delete transport;
}