bool locClientGetSizeByRespIndId(uint32_t respIndId, size_t *pRespIndSize)
{
  size_t idx = 0, respIndTableSize = 0;

  // Validate input arguments
  if(pRespIndSize == NULL)
  {
    LOC_LOGE("%s:%d]: size argument NULL !", __func__, __LINE__);
    return false;
  }

  respIndTableSize = (sizeof(locClientRespIndTable)/sizeof(locClientRespIndTableStructT));
  for(idx=0; idx<respIndTableSize; idx++ )
  {
    if(respIndId == locClientRespIndTable[idx].respIndId)
    {
      // found
      *pRespIndSize = locClientRespIndTable[idx].respIndSize;

      LOC_LOGV("%s:%d]: resp ind Id %d size = %d\n", __func__, __LINE__,
                    respIndId, (uint32_t)*pRespIndSize);
      return true;
    }
  }

  //not found
  return false;
}