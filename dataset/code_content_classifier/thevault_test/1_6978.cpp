void SctpAgent::NextChunk(u_char **ucpChunk, int *ipRemainingDataLen)
{
  DBG_I(NextChunk);
  unsigned long ulSize = ((SctpChunkHdr_S *) *ucpChunk)->usLength;

  /* the chunk length field does not include the padded bytes, so we need to
   * account for these extra bytes.
   */
  if( (ulSize % 4) != 0 ) 
    ulSize += 4 - (ulSize % 4);

  *ipRemainingDataLen -= ulSize;

  if(*ipRemainingDataLen > 0)
    *ucpChunk += ulSize;
  else
    *ucpChunk = NULL;

  DBG_X(NextChunk);
}