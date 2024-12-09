hsize_t
CvtOptions::chunkSize(hsize_t chunkSizeBytes, const hdf5pp::Type& type, hsize_t chunkSize)
{
  size_t obj_size = type.size();
  hsize_t chunk = chunkSize > 0 ? chunkSize : chunkSizeBytes / obj_size;

  // chunk_size is a desirable size, make sure that number of objects is not
  // too large or too small
  if (chunk > ::max_objects_per_chunk) {
    chunk = ::max_objects_per_chunk;
  } else if (chunk < ::min_objects_per_chunk) {
    chunk = ::min_objects_per_chunk;
    if (chunk*obj_size > ::abs_max_chunk_size) {
      chunk = ::abs_max_chunk_size / obj_size;
      if (chunk == 0) chunk = 1;
    }
  }
  return chunk;
}