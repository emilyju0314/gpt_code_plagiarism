inline void BinReadExact (BStream& bin, char* buff, size_t bytes)
{
  size_t bytes_to_read = bytes;
  size_t current = 0;
  while (bytes_to_read) {
    int_4 chunk_size = (1) << 30;  // 
    if (bytes_to_read < size_t(chunk_size)) {
      chunk_size = bytes_to_read;
    }
    bin.readExact(buff+current, chunk_size);
    current += chunk_size;
    bytes_to_read -= size_t(chunk_size);
  }
  // cerr << "READ ALL " << bytes << endl;
}