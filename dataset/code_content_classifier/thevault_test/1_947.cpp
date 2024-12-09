size_t OCPyBytesToSerialize (PyObject *po, OCPyDumpContext_& dc)
{
  // Use a table to have types and their proper type lookups for dispatch
  typedef size_t (*PYSERIALIZER_BYTES)(PyObject *po, OCPyDumpContext_& dc);
  typedef AVLHashT<PyTypeObject*, PYSERIALIZER_BYTES, 16> BytesTypeDispatchLookup;

  static BytesTypeDispatchLookup* lookup = 0;
  if (lookup == 0) {
    BytesTypeDispatchLookup *lp = new BytesTypeDispatchLookup;
    BytesTypeDispatchLookup& l=  *lp;

    l[&PyDict_Type]    = &OCPyBytesToSerializeDict;
    // l[&PyList_Type]    = &OCPyBytesToSerializeList; // Sequence
    l[&PyTuple_Type]   = &OCPyBytesToSerializeTuple;    
    l[&PyInt_Type]     = &OCPyBytesToSerializeInt;
    l[&PyLong_Type]    = &OCPyBytesToSerializeLong;
    l[&PyFloat_Type]   = &OCPyBytesToSerializeFloat;
    l[&PyComplex_Type] = &OCPyBytesToSerializeComplex;
    l[&PyString_Type]  = &OCPyBytesToSerializeString;
    l[&PyBool_Type]    = &OCPyBytesToSerializeBool;
    
    dynamic_lookup_check(l, "numpy",       "array", 
			 &OCPyBytesToSerializeNumPyArray);
    dynamic_lookup_check(l, "Numeric",     "array", 
			 &OCPyBytesToSerializeNumericArray);
    dynamic_lookup_check(l, "collections", "OrderedDict", 
			 &OCPyBytesToSerializeODict);
    
    lookup = lp; // install
  }

  PyTypeObject *type_object = po->ob_type; // Py_TYPE(o);
  PYSERIALIZER_BYTES routine;
  if (lookup->findValue(type_object, routine)) {
    return routine(po, dc);
  } else if (PySequence_Check(po)) {
    return OCPyBytesToSerializeSeq(po, dc);
  } else if (po == Py_None) {
    return OCPyBytesToSerializeNone(po, dc);
  } else {
    throw runtime_error("Can't OC serialize this object");
  }
  
}