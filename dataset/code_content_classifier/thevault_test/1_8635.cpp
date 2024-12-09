bool Client::setSocketOpt( const QSocketDevice * MUReceiveSocket, const QString address ) {
  int s = MUReceiveSocket->socket();  

  struct ip_mreq mreq;
  if( inet_aton( address.data(), &mreq.imr_multiaddr ) == 0 ) {
    QMessageBox::warning( pcv, "Error", "can't construct a multicast address" );
    return false;
  }
  mreq.imr_interface.s_addr = htonl( INADDR_ANY );
  if( setsockopt( s, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof( mreq ) ) < 0 ) {
    QMessageBox::warning( pcv, "Error", "can't add to the group" + address );
    return false;
  }

  return true;
}