int SctpAgent::GenMultipleDataChunks(u_char *ucpOutData, int iTotalOutDataSize)
{
  DBG_I(GenMultipleDataChunks);
  
  int iChunkSize = 0;
  int iStartingTotalSize = iTotalOutDataSize;

  while((iTotalOutDataSize + GetNextDataChunkSize()  <= uiMaxDataSize) &&
	(GetNextDataChunkSize()                      <= uiPeerRwnd) &&
	(eDataSource == DATA_SOURCE_INFINITE || sAppLayerBuffer.uiLength != 0))
    {
      iChunkSize = GenOneDataChunk(ucpOutData);
      ucpOutData += iChunkSize;
      iTotalOutDataSize += iChunkSize;
    }
  
  DBG_X(GenMultipleDataChunks);
  return iTotalOutDataSize - iStartingTotalSize;
}