inline void dumpOpalArray_ (const OpalValue& ov, DumpContext_& dc)
{
  Vector vec = UnOpalize(ov, Vector);

  // Assume v is an Array
  int sz = -1;
  const char* c;
  switch (vec.type()) { //array.array typecodes
  case M2_BYTE:      sz=sizeof(int_1);  c="c"; break;
  case M2_UBYTE:     sz=sizeof(int_u1); c="B"; break;
  case M2_INTEGER:   sz=sizeof(int_2);  c="h"; break;
  case M2_UINTEGER:  sz=sizeof(int_u2); c="H"; break;
  case M2_LONG:      sz=sizeof(int_4);  c="i"; break;
  case M2_ULONG:     sz=sizeof(int_u4); c="I"; break;
  case M2_XLONG:     sz=sizeof(int_8);  c="l"; break;
  case M2_UXLONG:    sz=sizeof(int_u8); c="L"; break;
  case M2_FLOAT:     sz=sizeof(real_4); c="f"; break;
  case M2_DOUBLE:    sz=sizeof(real_8); c="d"; break;
  case M2_CX_FLOAT:  sz=sizeof(complex_8);  c="F"; break;
  case M2_CX_DOUBLE: sz=sizeof(complex_16); c="D"; break;
  case M2_TIME:      sz=sizeof(int_u8); c="L"; break; 
  case M2_DURATION:  sz=sizeof(M2Duration); c="d"; break; 
  default: p2error_("Can't dumpOpalArray");
  }
  
  // THIS IS A POD Array!  can bit blit
  
  // Dump the memoize to make it faster
  if (dc.array_preamble_dumped) {
    P2DumpCodeAndInt_(dc.array_handle, PY_BINGET, PY_LONG_BINGET, dc);
  } else {
    // Not dumped, figure out what handle should be
    dc.array_handle = dc.current_handle++;
    dc.array_preamble_dumped = true;
    
    // Then dump it (with memo to annotate it)
    memcpy(dc.mem, ArrayPreamble, sizeof(ArrayPreamble)-1);
    dc.mem += sizeof(ArrayPreamble)-1;
    P2DumpCodeAndInt_(dc.array_handle, PY_BINPUT, PY_LONG_BINPUT, dc);
  }
  
  // Same layout, regardless of type.
  // TODO:  Will we have to reendiaze this?
  char* dat = (char*)vec.readData();
  
  // Dump the format before the data
  dumpCString(c, 1, dc);
  dumpCString(dat, vec.elements()*sz, dc);
  *(dc.mem)++ = PY_TUPLE2;
  *(dc.mem)++ = PY_REDUCE;
}