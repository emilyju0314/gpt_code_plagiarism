void* OCPyGetNumPyArrayInfo (PyObject *po,
			     char& oc_typecode, size_t& len)
{
  len = PyObject_Length(po); // get length in a neutral way
  NUMERIC_PyArrayObject *hope_this_works = (NUMERIC_PyArrayObject*)po;
  char *data = hope_this_works->data;

  // Get the typecode in a string-based way
  PyObject *res = PyObject_GetAttrString(po, (char*)"dtype"); /* new ref */
  if (res==NULL) {
    throw runtime_error("Not a numpy object? Expected dtype");
  }
  PyObject *type_str = PyObject_Str(res); /* new ref */
  char *dtype_data = PyString_AS_STRING(type_str);

  // cerr << "dtypde_data:" << dtype_data << ":" << endl;

  // Convert typecode to OC and let below handle creating array
  oc_typecode = '?';
  try {
    oc_typecode = NumPyStringToOC(dtype_data);
    // cerr << "AFTER TYPECODE" << oc_typecode << int(oc_typecode) << endl;
  } catch (...) { }
  Py_DECREF(type_str);

  return data;
}