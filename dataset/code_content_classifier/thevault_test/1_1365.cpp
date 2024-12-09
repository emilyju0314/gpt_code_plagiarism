static PyObject *VectorStringToPyBytesList(
    const std::vector<std::string> &function_descriptor) {
  size_t size = function_descriptor.size();
  PyObject *return_list = PyList_New(static_cast<Py_ssize_t>(size));
  for (size_t i = 0; i < size; ++i) {
    auto py_bytes = PyBytes_FromStringAndSize(function_descriptor[i].data(),
                                              function_descriptor[i].size());
    PyList_SetItem(return_list, i, py_bytes);
  }
  return return_list;
}