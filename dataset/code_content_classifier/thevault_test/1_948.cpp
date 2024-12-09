inline void OCPyMarkProxy (PyObject *po, OCPyLoadContext_& lc)
{
  // If the last marker isn't set, then this isn't for proxying
  int_u4 marker = lc.last_marker;
  if (marker!=int_u4(-1)) {
    PyObjectInfo pyinfo;
    pyinfo.object = po;
    pyinfo.times = 1;
    pyinfo.marker = marker;
    lc.objectLookup[po] = pyinfo;

    PyObject* there = lc.markerLookup[marker];
    if (there != NULL) {
      throw runtime_error("Broke invariant about markers up by 1");
    }
    lc.markerLookup[marker] = po;
    // make sure we don't mark things unwarrantedly
    lc.last_marker = int_u4(-1);
  }
}