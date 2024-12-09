static PyObject* /* new ref */
dynamic_check (const char* module, const char* type)
{
  // Try to import  to get the type object therein
  PyObject *mood = PyImport_ImportModule((char*)module);
  if (mood==NULL) { // Not there!
    PyErr_Clear();
    return NULL;
  }
  // Okay, we can get the module, can we get the type object?
  PyObject *callable = PyObject_GetAttrString(mood, (char*)type); // new ref
  if (callable==NULL) {
    PyErr_Clear();
    return NULL;
  }
  int check = PyCallable_Check(callable);
  if (!check) {
    Py_DECREF(callable);
    return NULL;
  }
  PyObject *args     = NULL; 
  if (string(type)=="array") {
    args     = Py_BuildValue((char*)"([i],s)", 1,"i");          // new ref
  } else  {
    args     = Py_BuildValue((char*)"()");          // new ref
  }

  PyObject *res      = PyEval_CallObject(callable, args);        // new ref
  
  Py_DECREF(callable);
  Py_DECREF(args);
  
  return res;
}