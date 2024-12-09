int
DefaultChunkPolicy::chunkCacheSize(const hdf5pp::Type& dsType) const
{
  const int chunk_size = chunkSize(dsType);

  hsize_t chunk_size_bytes = chunk_size * dsType.size();
  hsize_t chunk_cache_size = 1;
  if (chunk_size_bytes <= m_minChunkCacheSize/2) {
    chunk_cache_size = m_minChunkCacheSize/chunk_size_bytes;
  } else if (chunk_size_bytes <= m_maxChunkCacheSize/2) {
    chunk_cache_size *= 2;
  }
  return chunk_cache_size;
}