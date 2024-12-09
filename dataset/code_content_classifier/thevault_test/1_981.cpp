void dumpOpalNumericArray_ (const OpalValue& ov, DumpContext_& dc)
{
  Vector v = UnOpalize(ov, Vector);
  
  // THIS IS A POD Array!  can bit blit
  const char* c;
  
  // If already memoized, just dump the memo for faster serialization
  if (dc.numeric_preamble_dumped) {
    P2DumpCodeAndInt_(dc.numeric_handle, PY_BINGET, PY_LONG_BINGET, dc);
  } else {
    // Get new handle
    dc.numeric_handle = dc.current_handle++;
    dc.numeric_preamble_dumped = true;

    // Dump the original data
    memcpy(dc.mem, NumericPreamble, sizeof(NumericPreamble)-1);
    dc.mem += sizeof(NumericPreamble)-1;
    P2DumpCodeAndInt_(dc.numeric_handle, PY_BINPUT, PY_LONG_BINPUT, dc);
  }
  
  // Same layout, regardless of type.
  // TODO:  Will we have to reendiaze this?

  // Dump (, then length of array, then tuple
  *(dc.mem)++ = '(';
  if (dc.pickling_issues==AS_PYTHON_2_2) {
    *(dc.mem)++ = '(';
  }
  int elements = v.elements();
  dump4ByteInteger(elements, dc); 
  *(dc.mem)++ = (dc.pickling_issues==AS_PYTHON_2_2) ? 't' : PY_TUPLE1;
    
  // Dump string with typecode, then dump as data
  switch (v.type()) {
  case M2_BYTE:    c="1"; dumpNumericHelp_((int_1*)0, (int_1*)0, c,dc,v);break;
  case M2_UBYTE:   c="b"; dumpNumericHelp_((int_u1*)0,(int_u1*)0,c,dc,v);break;
  case M2_INTEGER: c="s"; dumpNumericHelp_((int_2*)0, (int_2*)0, c,dc,v);break;
  case M2_UINTEGER:c="w"; dumpNumericHelp_((int_u2*)0,(int_u2*)0,c,dc,v);break;
  case M2_LONG:    c="i"; dumpNumericHelp_((int_4*)0, (int_4*)0, c,dc,v);break;
  case M2_ULONG:   c="u"; dumpNumericHelp_((int_u4*)0,(int_u4*)0, c,dc,v);break;

  // These two may or may not be supported???  If the version of Python
  // supports long as 8 bytes, then this is the best we can do.  It's
  // unfortunate that Numeric is "restricted" in its int types.  As long as
  // we are talking to implementations that support the 'l' as int_u8 
  // typecode, we don't lose any information.

  //case M2_XLONG: c="l";dumpNumericHelp_((int_8*)0,(int_8*)0,c,dc,v);break;
  //case M2_UXLONG:c="x";dumpNumericHelp_((int_u8*)0,(int_u8*)0,c,dc,v);break;
  case M2_XLONG:  c="l"; dumpNumericHelp_((long*)0, (int_8*)0,c,dc,v);break;
  case M2_UXLONG: c="l"; dumpNumericHelp_((long*)0, (int_u8*)0,c,dc,v);break;

  case M2_FLOAT: c="f"; dumpNumericHelp_((real_4*)0, (real_4*)0, c,dc,v);break;
  case M2_DOUBLE:c="d"; dumpNumericHelp_((real_8*)0, (real_8*)0, c,dc,v);break;
  case M2_CX_FLOAT:c="F"; dumpNumericHelp_((complex_8*)0, (complex_8*)0, c,dc,v);break;  
  case M2_CX_DOUBLE: c="D"; dumpNumericHelp_((complex_16*)0, (complex_16*)0, c, dc, v); break;
    // The M2Time has the same limitations as M2_XLONG and M2_UXLONG above
  case M2_TIME: c="l"; dumpNumericHelp_((long*)0, (int_u8*)0, c,dc,v);break;
  case M2_DURATION:c="d";dumpNumericHelp_((real_8*)0, (real_8*)0,c,dc,v);break;
  default: p2error_("Can't use type in dumpOpalNumericArray_");
  }

  if (dc.pickling_issues==AS_PYTHON_2_2) {
    dump4ByteInteger(1, dc);
  } else { 
    *(dc.mem)++ = PY_NEWTRUE;
  }
  *(dc.mem)++ = 't';
  *(dc.mem)++ = PY_REDUCE;
}