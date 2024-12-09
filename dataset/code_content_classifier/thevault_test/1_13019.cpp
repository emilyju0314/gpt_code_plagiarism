hsize_t 
CvtOptions::chunkSize(const hdf5pp::Type& type) const
{
  return chunkSize(m_chunkSizeBytes, type, ::g_chunkSize);
}