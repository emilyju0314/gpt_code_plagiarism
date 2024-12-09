size_t OCPyBytesToSerializeSeq (PyObject *po, OCPyDumpContext_& dc)
{
  size_t bytes = 0;
  if (OCPyBytesToSerializeProxy(po, dc, &bytes)) return bytes;

  // A 'n'/'N' marker, 'Z' starts, plus len
  const size_t len = PySequence_Size(po);
  bytes += 1+1+((len<=0xFFFFFFFF) ? sizeof(int_u4) : sizeof(int_u8));

  for (size_t ii=0; ii<len; ii++) {
    PyObject *pyitem = PySequence_GetItem(po, ii);
    bytes += OCPyBytesToSerialize(pyitem, dc);
  }

  return bytes;
}