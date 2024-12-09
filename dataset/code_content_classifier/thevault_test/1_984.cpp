void dumpOpalNumPyArray_ (const OpalValue& ov, DumpContext_& dc)
{
  Vector v = UnOpalize(ov, Vector);
  Numeric_e subtype=v.type();

  // THIS IS A POD Array!  can bit blit
  char* c;
  int shape = v.elements();
  
  // PY_GLOBAL reconstruct
  PreambleDumperNumPyReconstruct(dc);
  
  // Initial arguments to a "prototype" NDArray
  PreambleDumperNumPyNDArray(dc);   // 1: GLOBAL
  OpalTable unused_shape; unused_shape.append(OpalValue(Number(int_4(0)))); // Tup(Val(0))
  P2DumpTuple(unused_shape, dc);    // 2: initial unused shape
  dumpCString("b",1,dc);            // 3: initial unused type
  *(dc.mem)++ = PY_TUPLE3;          // (1,2,3)
  *(dc.mem)++ = PY_REDUCE;

  // Starting argumements for "prototype" multiarray BUILD
  {
    *(dc.mem)++ = PY_MARK;
    
    P2DumpValue(OpalValue(Number(int_4(1))), dc);
    // Shape in a tuple
    OpalTable shape_tuple; shape_tuple.append(OpalValue(Number(int_4(shape))));
    P2DumpTuple(shape_tuple, dc);
    
    // Starting DTYPE
    {
      // Initial args to a "prototype" dtype
      PreambleDumperNumPyDtype(dc);
      string numpy_code = M2kToNumPyCode(subtype);

      OpalTable dtype_initial;       // Tup dtype_initial(numpy_code, 0, 1);
      dtype_initial.append(numpy_code);
      dtype_initial.append(OpalValue(Number(int_4(0))));
      dtype_initial.append(OpalValue(Number(int_4(1))));
      P2DumpTuple(dtype_initial, dc);
      *(dc.mem)++ = PY_REDUCE;

      // Tuple of arguments that get applied to "prototype" dtype BUILD
      string endian = ByteLength(subtype)==1 ? "|" : IsLittleEndian() ? "<" : ">";
      //Tup dtype_args(3, endian, None, None, None, -1, -1, 0);
      OpalValue none("None", OpalValueA_TEXT); 
      OpalTable dtype_args;
      dtype_args.append(OpalValue(Number(int_4(3))));
      dtype_args.append(endian);
      dtype_args.append(none);
      dtype_args.append(none);
      dtype_args.append(none);
      dtype_args.append(OpalValue(Number(int_4(-1))));
      dtype_args.append(OpalValue(Number(int_4(-1))));
      dtype_args.append(OpalValue(Number(int_4(0))));

      P2DumpTuple(dtype_args, dc);
      *(dc.mem)++ = PY_BUILD;
    }
    // Assertion: Dtype top thing on values stack
    
    *(dc.mem)++ = PY_NEWFALSE;

    // Dump the actual data
    const char* raw_data = (const char*)v.readData(); 
    dumpCString(raw_data, ByteLength(subtype)*shape, dc);
    
    *(dc.mem)++ = PY_TUPLE;
  }
  *(dc.mem)++ = PY_BUILD;
  //if (memoize_self) { MemoizeSelf_(memoize_self, dc); }
}