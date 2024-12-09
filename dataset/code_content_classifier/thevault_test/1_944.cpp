void* OCPyGetNumericArrayInfo (PyObject *po,
			       char& oc_typecode, size_t& len)
{
  len = PyObject_Length(po);  // get length in neutral way
  NUMERIC_PyArrayObject *hope_this_works = (NUMERIC_PyArrayObject*)po;
  char* data = hope_this_works->data;
  
  // Get the typecode in a string-based wway
  PyObject *res = PyObject_CallMethod(po, (char*)"typecode", (char*)"()"); /* new ref */
  if (res==NULL) {
    throw runtime_error("Not a Numeric object? Expected typecode to return str");
  }
  if (!PyString_Check(res)) {
    Py_DECREF(res);
    throw runtime_error("Not a Numeric object? Expected typecode to return str");
  }
  char *typecode_data = PyString_AS_STRING(res);
  size_t typecode_len = PyString_GET_SIZE(res);
  if (typecode_len!=1) {
    Py_DECREF(res);
    throw runtime_error("typecode isn't single letter?");
  }
  oc_typecode = NumericTagToOC(typecode_data[0]);
  
  // Clean up
  Py_DECREF(res);
  
  // Return the data
  return data;
}