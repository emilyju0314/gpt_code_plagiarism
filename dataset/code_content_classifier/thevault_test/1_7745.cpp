static bool locClientGetSizeAndTypeByIndId (uint32_t indId, size_t *pIndSize,
                                         locClientIndEnumT *pIndType)
{
  // look in the event table
  if(true == locClientGetSizeByEventIndId(indId, pIndSize))
  {
    *pIndType = eventIndType;

    LOC_LOGV("%s:%d]: indId %d is an event size = %d\n", __func__, __LINE__,
                  indId, (uint32_t)*pIndSize);
    return true;
  }

  //else look in response table
  if(true == locClientGetSizeByRespIndId(indId, pIndSize))
  {
    *pIndType = respIndType;

    LOC_LOGV("%s:%d]: indId %d is a resp size = %d\n", __func__, __LINE__,
                  indId, (uint32_t)*pIndSize);
    return true;
  }

  // Id not found
  LOC_LOGW("%s:%d]: indId %d not found\n", __func__, __LINE__, indId);
  return false;
}