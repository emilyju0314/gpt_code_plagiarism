bool OCPyBytesToSerializeProxy (PyObject *po, OCPyDumpContext_& dc,
				  size_t* bytes)
{
  *bytes = 1 + 4; // 'P' and int_u4 marker always there!

  // Check to see if already been serialized and get the marker,
  // otherwise we'll just be appending new marker
  PyObjectInfo& pyinfo = dc.objectLookup[po];
  pyinfo.object = po;
  if (pyinfo.times++ == 0) {  // 1 more user
    // First time! Fill in marker
    pyinfo.object = po;
    pyinfo.marker = dc.objectLookup.entries()-1;
    *bytes += 3;   // for adopt, lock, allocator
    return false; // Force check of all bytes
  } else {
    // Already seen, no more bytes needed other than 'P'+ marker
    return true;
  }
}