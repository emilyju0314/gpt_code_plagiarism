void P2DumpTuple (const OpalValue& ov, DumpContext_& dc)
{
  OpalTable ot = UnOpalize(ov, OpalTable);
  if (ot.implementation().type() != OpalTableImpl_GRAPHARRAY) {
    throw MidasException("Not a tuple");
  }

  // longer tuples require a mark
  int len = ot.length();
  if (len>3) {  
    *(dc.mem)++ = PY_MARK;
  }

  // Dump each element
  for (int ii=0; ii<len; ii++) {
    OpalValue t = ot.get(ii);
    P2DumpValue(t, dc);
  }
  
  // Small tuples have special opcode
  const int opcodes[] = {PY_EMPTY_TUPLE, PY_TUPLE1, PY_TUPLE2, PY_TUPLE3 };
  if (len>3) {
    *(dc.mem)++ = PY_TUPLE;
  } else {
    *(dc.mem)++ = opcodes[len];
  }
			
}