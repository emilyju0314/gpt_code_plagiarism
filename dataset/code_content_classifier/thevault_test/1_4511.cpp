inline PyObject * pythonImport(const std::string & name)
{
  PyObject * py_name = stringToPython(name);
  if (!py_name) {
    return nullptr;
  }
  PyObject * module = PyImport_Import(py_name);
  Py_XDECREF(py_name);
  return module;
}