OpalValue MakeVector (const string& typecode, size_t elements,
		       const char* mem, size_t bytes)
{
  // Error checking
  if (typecode.length()>1 || typecode.length()==0) {
    MakeException("Only expect 1 letter types for Depickling Numeric "
		  "arrays.  Saw:"+typecode);
  }
  
  // Lookup the m2k typecode from the python typecode
  char python_typecode[]   = "dlFD";
  char* where = strchr(python_typecode, typecode[0]);
  if (!where) {
    MakeException("Unknown depickling typecode"+typecode);
  }
  Numeric_e m2k_typecode[] = { DOUBLE, LONG, CX_FLOAT, CX_DOUBLE };
  Numeric_e m2k_type = m2k_typecode[where-python_typecode];
  
  // Create an m2k vector of the proper type and length: and populate.
  Vector final_result(m2k_type, elements);
  char* result_buff = (char*)final_result.writeData();
  size_t result_bytes  = elements*ByteLength(m2k_type);
  
  CopyPrintableBufferToVector(mem, bytes, result_buff, result_bytes);
  
  // If this machine is big-endian, we need to normalized to little endian
  if (!IsLittleEndian()) {
    InPlaceReEndianize(result_buff, elements, 
		       ByteLength(m2k_type), isComplex(m2k_type));
  }
  return OpalValue(final_result);
}