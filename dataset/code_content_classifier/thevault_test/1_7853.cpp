bool VVDecImpl::isFrameConverted( vvdecFrame* frame )
{
  frameStorageMap::iterator storageIter =  m_cFrameStorageMap.find( frame->sequenceNumber );
  if( storageIter != m_cFrameStorageMap.end() )
  {
    if( storageIter->second.isAllocated() )
    {
      return true;;
    }
  }

  return false;
}