bool locClientGetSizeByEventIndId(uint32_t eventIndId, size_t *pEventIndSize)
{
  size_t idx = 0, eventIndTableSize = 0;

  // Validate input arguments
  if(pEventIndSize == NULL)
  {
    LOC_LOGE("%s:%d]: size argument NULL !", __func__, __LINE__);
    return false;
  }

  // look in the event table
  eventIndTableSize =
    (sizeof(locClientEventIndTable)/sizeof(locClientEventIndTableStructT));

  for(idx=0; idx<eventIndTableSize; idx++ )
  {
    if(eventIndId == locClientEventIndTable[idx].eventId)
    {
      // found
      *pEventIndSize = locClientEventIndTable[idx].eventSize;

      LOC_LOGV("%s:%d]: event ind Id %d size = %d\n", __func__, __LINE__,
                    eventIndId, (uint32_t)*pEventIndSize);
      return true;
    }
  }
  // not found
  return false;
}