string M2kToNumPyCode (Numeric_e type)
{
  switch (type) {
  case M2_BYTE: return "i1";
  case M2_UBYTE: return "u1";
  case M2_INTEGER: return "i2";
  case M2_UINTEGER: return "u2";
  case M2_LONG: return "i4";
  case M2_ULONG: return "u4";
  case M2_XLONG: return "i8";
  case M2_UXLONG: return "u8";
  case M2_FLOAT: return "f4";
  case M2_DOUBLE: return "f8";
  case M2_CX_FLOAT: return "c8";
  case M2_CX_DOUBLE: return "c16";
  case M2_BIT: return "b1";

  case M2_TIME: return "u8";
  case M2_DURATION: return "f8";

  case M2_UNDEFINED: return "f8"; 

  default: {
    string ty=Stringize(type); throw MidasException("Cannot handle arrays of "+ty);
  }
  }
}