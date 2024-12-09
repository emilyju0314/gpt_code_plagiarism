int ChunkPolicy::chunkCacheSize(const hdf5pp::Type& dsType) const
{
  const size_t obj_size = dsType.size();
  return chunkCacheSize(obj_size);
}