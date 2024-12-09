inline std::string stringFromPython(PyObject * input)
{
  Py_ssize_t size;
  const char * data;
  data = PyUnicode_AsUTF8AndSize(input, &size);
  return std::string(data, size);
}