inline void dumpOpalArrayAsList_ (const OpalValue& ov, DumpContext_& dc)
{
  Vector vec = UnOpalize(ov, Vector);
  int length = vec.elements();

  // Other arrays ...
  *(dc.mem)++ = PY_EMPTY_LIST;
  if (length==0) return;
  if (length!=1) *(dc.mem)++ = '(';
  
  switch (vec.type()) {
  case M2_BYTE:     P2_PLAINARRAYDUMP(int_1,     dump4ByteInteger);  break;
  case M2_UBYTE:    P2_PLAINARRAYDUMP(int_u1,    dump4ByteInteger);  break;
  case M2_INTEGER:  P2_PLAINARRAYDUMP(int_2,     dump4ByteInteger);  break;
  case M2_UINTEGER: P2_PLAINARRAYDUMP(int_u2,    dump4ByteInteger);  break;
  case M2_LONG    : P2_PLAINARRAYDUMP(int_4,     dump4ByteInteger);  break;
  case M2_ULONG:    P2_PLAINARRAYDUMP(int_u4,    dump4ByteInteger);  break;
  case M2_XLONG:    P2_PLAINARRAYDUMP(int_8,     dump8ByteInteger);  break;
  case M2_UXLONG:   P2_PLAINARRAYDUMP(int_u8,    dump8ByteUnsignedInteger);  break;
  case M2_FLOAT:    P2_PLAINARRAYDUMP(real_4,    dump8ByteFloat);    break;
  case M2_DOUBLE:   P2_PLAINARRAYDUMP(real_8,    dump8ByteFloat);    break;
  case M2_CX_FLOAT: P2_PLAINARRAYDUMPWITHHELP(complex_8, dump16ByteComplex, complex_16); break;
  case M2_CX_DOUBLE:P2_PLAINARRAYDUMP(complex_16,dump16ByteComplex); break;
  case M2_TIME:     P2_PLAINARRAYDUMPWITHHELP(M2Time,    dumpString, Stringize); break;
  case M2_DURATION: P2_PLAINARRAYDUMPWITHHELP(M2Duration,dumpString, Stringize); break;
  default: p2error_("unknown Vector type in dumpOpalArrayAsList_");
  }
  *(dc.mem)++ = (length==1) ? PY_APPEND : PY_APPENDS;
}