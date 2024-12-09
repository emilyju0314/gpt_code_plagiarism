PyObject* OCPyDeserialize (char *mem, bool compat, 
			   ArrayDisposition_e arrdisp)
{
  OCPyLoadContext_ dc(mem, compat, arrdisp);
  return OCPyDeserialize(dc);
}