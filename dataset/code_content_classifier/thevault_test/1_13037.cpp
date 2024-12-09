int
DefaultChunkPolicy::chunkSize(const hdf5pp::Type& dsType) const
{
  const size_t obj_size = dsType.size();
  int chunk = m_chunkSizeTarget > 0 ? m_chunkSizeTarget : m_chunkSizeTargetBytes / obj_size;

  // chunk_size is a target size, make sure that number of objects is not
  // too large or too small
  if (chunk > m_maxObjectsPerChunk) {
    chunk = m_maxObjectsPerChunk;
  } else if (chunk < m_minObjectsPerChunk) {
    chunk = m_minObjectsPerChunk;
  }
  if (chunk*obj_size > m_maxChunkSizeBytes) {
    chunk = m_maxChunkSizeBytes / obj_size;
    if (chunk == 0) chunk = 1;
  }
  return chunk;
}