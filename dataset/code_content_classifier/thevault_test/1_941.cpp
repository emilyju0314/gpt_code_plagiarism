size_t OCPyBytesToSerializeLong (PyObject *po, OCPyDumpContext_& dc)
{
  // Convert PyLong to string, THEN we reparse it
  PyObject *str = PyObject_Str(po); /* new ref */
  char* data = PyString_AS_STRING(str);
  int_n bigint = StringToBigInt(data);
  Py_DECREF(str);
  string repr = MakeBinaryFromBigInt(bigint);
  
  const size_t len = repr.length();
  size_t bytes = 1 + ((len<=0xFFFFFFFF) ? sizeof(int_u4) : sizeof(int_u8));

  return bytes + len;
}