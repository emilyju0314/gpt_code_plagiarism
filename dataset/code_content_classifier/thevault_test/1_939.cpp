size_t OCPyBytesToSerialize (PyObject *po, bool compat)
{
  OCPyDumpContext_ dc(0, compat);
  return OCPyBytesToSerialize(po, dc);
}