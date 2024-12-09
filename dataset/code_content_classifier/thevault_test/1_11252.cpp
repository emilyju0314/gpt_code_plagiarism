int read_int(const char * & iter) {
  const int result = *(reinterpret_cast<const int*>(iter));
  iter += sizeof(int);
  return result;
}