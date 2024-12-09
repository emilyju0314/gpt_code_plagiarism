void ServerMsgSender::Send_TunnelInfo( const gogocTunnelInfo* aTunnelInfo )
{
  Message* pMsg;
  uint8_t pData[MSG_MAX_USERDATA];
  uint16_t nDataLen = 0;


  assert( aTunnelInfo != NULL );


  // Append broker name to data buffer.
  if( aTunnelInfo->szBrokerName ) {
    memcpy( pData + nDataLen, aTunnelInfo->szBrokerName, strlen(aTunnelInfo->szBrokerName) + 1 );
    nDataLen += (uint16_t)strlen(aTunnelInfo->szBrokerName) + 1;
  }
  else {
    memset( pData + nDataLen, 0x00, 1 );
    ++nDataLen;
  }

  // Append tunnel type to data buffer.
  memcpy( pData + nDataLen, (void*)&(aTunnelInfo->eTunnelType), sizeof(gogocTunnelType) );
  nDataLen += sizeof(gogocTunnelType);

  // Append Local tunnel endpoint IPv4 address to data buffer.
  if( aTunnelInfo->szIPV4AddrLocalEndpoint ) {
    memcpy( pData + nDataLen, aTunnelInfo->szIPV4AddrLocalEndpoint, strlen(aTunnelInfo->szIPV4AddrLocalEndpoint) + 1 );
    nDataLen += (uint16_t)strlen(aTunnelInfo->szIPV4AddrLocalEndpoint) + 1;
  }
  else {
    memset( pData + nDataLen, 0x00, 1 );
    ++nDataLen;
  }

  // Append Local tunnel endpoint IPv6 address to data buffer.
  if( aTunnelInfo->szIPV6AddrLocalEndpoint ) {
    memcpy( pData + nDataLen, aTunnelInfo->szIPV6AddrLocalEndpoint, strlen(aTunnelInfo->szIPV6AddrLocalEndpoint) + 1 );
    nDataLen += (uint16_t)strlen(aTunnelInfo->szIPV6AddrLocalEndpoint) + 1;
  }
  else {
    memset( pData + nDataLen, 0x00, 1 );
    ++nDataLen;
  }

  // Append Remote tunnel endpoint IPv4 address to data buffer.
  if( aTunnelInfo->szIPV4AddrRemoteEndpoint ) {
    memcpy( pData + nDataLen, aTunnelInfo->szIPV4AddrRemoteEndpoint, strlen(aTunnelInfo->szIPV4AddrRemoteEndpoint) + 1 );
    nDataLen += (uint16_t)strlen(aTunnelInfo->szIPV4AddrRemoteEndpoint) + 1;
  }
  else {
    memset( pData + nDataLen, 0x00, 1 );
    ++nDataLen;
  }

  // Append Remote tunnel endpoint IPv6 address to data buffer.
  if( aTunnelInfo->szIPV6AddrRemoteEndpoint ) {
    memcpy( pData + nDataLen, aTunnelInfo->szIPV6AddrRemoteEndpoint, strlen(aTunnelInfo->szIPV6AddrRemoteEndpoint) + 1 );
    nDataLen += (uint16_t)strlen(aTunnelInfo->szIPV6AddrRemoteEndpoint) + 1;
  }
  else {
    memset( pData + nDataLen, 0x00, 1 );
    ++nDataLen;
  }

  // Append The delegated prefix to data buffer.
  if( aTunnelInfo->szDelegatedPrefix ) {
    memcpy( pData + nDataLen, aTunnelInfo->szDelegatedPrefix, strlen(aTunnelInfo->szDelegatedPrefix) + 1 );
    nDataLen += (uint16_t)strlen(aTunnelInfo->szDelegatedPrefix) + 1;
  }
  else {
    memset( pData + nDataLen, 0x00, 1 );
    ++nDataLen;
  }

  // Append The delegated user domain to data buffer.
  if( aTunnelInfo->szUserDomain ) {
    memcpy( pData + nDataLen, aTunnelInfo->szUserDomain, strlen(aTunnelInfo->szUserDomain) + 1 );
    nDataLen += (uint16_t)strlen(aTunnelInfo->szUserDomain) + 1;
  }
  else {
    memset( pData + nDataLen, 0x00, 1 );
    ++nDataLen;
  }

  // Append tunnel uptime to data buffer.
  memcpy( pData + nDataLen, (void*)&(aTunnelInfo->tunnelUpTime), sizeof(time_t) );
  nDataLen += sizeof(time_t);

  assert( nDataLen <= MSG_MAX_USERDATA );       // Buffer overflow has occured.


  // Create Message.
  pMsg = Message::CreateMessage( MESSAGEID_TUNNELINFO, nDataLen, pData );
  assert( pMsg != NULL );


  // Post the message.
  PostMessage( pMsg );
}