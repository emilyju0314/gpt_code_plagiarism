void ServerMsgSender::Send_StatusInfo( const gogocStatusInfo* aStatusInfo )
{
  Message* pMsg;
  uint8_t pData[MSG_MAX_USERDATA];
  unsigned int nDataLen = 0;


  assert( aStatusInfo != NULL );


  // Write client status to data buffer.
  memcpy( pData, (void*)&(aStatusInfo->eStatus), sizeof(gogocCliStatus) );
  nDataLen += sizeof(gogocCliStatus);

  // Append status code to nStatus.
  memcpy( pData + nDataLen, (void*)&(aStatusInfo->nStatus), sizeof(aStatusInfo->nStatus) );
  nDataLen += sizeof(aStatusInfo->nStatus);


  assert( nDataLen <= MSG_MAX_USERDATA );       // Buffer overflow has occured.


  // Create Message
  pMsg = Message::CreateMessage( MESSAGEID_STATUSINFO, nDataLen, pData );
  assert( pMsg != NULL );


  // Post the message.
  PostMessage( pMsg );
}