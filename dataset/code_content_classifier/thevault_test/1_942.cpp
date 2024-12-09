inline void OCPyTypeArrayToSerialize (void* data, size_t len, char oc_type,
				      OCPyDumpContext_& dc)
{
  char *&mem = dc.mem;

  size_t byte_len = ByteLength(oc_type);
  if (len <= 0xFFFFFFFF) {
    *mem++ = 'n';
    *mem++ = oc_type;
    int_u4 l = len;
    VALCOPY(int_u4, l);
  } else {
    *mem++ = 'N'; 
    *mem++ = oc_type;
    int_u8 l = len;
    VALCOPY(int_u8, l);
  }
  memcpy(mem, data, byte_len*len);
  mem += len*byte_len;
}