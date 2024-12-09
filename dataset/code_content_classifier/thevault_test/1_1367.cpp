bool is_simple_value(PyObject *value, int *num_elements_contained) {
  *num_elements_contained += 1;
  if (*num_elements_contained >= RayConfig::instance().num_elements_limit()) {
    return false;
  }
  if (PyInt_Check(value) || PyLong_Check(value) || value == Py_False ||
      value == Py_True || PyFloat_Check(value) || value == Py_None) {
    return true;
  }
  if (PyBytes_CheckExact(value)) {
    *num_elements_contained += PyBytes_Size(value);
    return (*num_elements_contained < RayConfig::instance().num_elements_limit());
  }
  if (PyUnicode_CheckExact(value)) {
    *num_elements_contained += PyUnicode_GET_SIZE(value);
    return (*num_elements_contained < RayConfig::instance().num_elements_limit());
  }
  if (PyList_CheckExact(value) &&
      PyList_Size(value) < RayConfig::instance().size_limit()) {
    for (Py_ssize_t i = 0; i < PyList_Size(value); ++i) {
      if (!is_simple_value(PyList_GetItem(value, i), num_elements_contained)) {
        return false;
      }
    }
    return (*num_elements_contained < RayConfig::instance().num_elements_limit());
  }
  if (PyDict_CheckExact(value) &&
      PyDict_Size(value) < RayConfig::instance().size_limit()) {
    PyObject *key, *val;
    Py_ssize_t pos = 0;
    while (PyDict_Next(value, &pos, &key, &val)) {
      if (!is_simple_value(key, num_elements_contained) ||
          !is_simple_value(val, num_elements_contained)) {
        return false;
      }
    }
    return (*num_elements_contained < RayConfig::instance().num_elements_limit());
  }
  if (PyTuple_CheckExact(value) &&
      PyTuple_Size(value) < RayConfig::instance().size_limit()) {
    for (Py_ssize_t i = 0; i < PyTuple_Size(value); ++i) {
      if (!is_simple_value(PyTuple_GetItem(value, i), num_elements_contained)) {
        return false;
      }
    }
    return (*num_elements_contained < RayConfig::instance().num_elements_limit());
  }
  if (PyArray_CheckExact(value)) {
    PyArrayObject *array = reinterpret_cast<PyArrayObject *>(value);
    if (PyArray_TYPE(array) == NPY_OBJECT) {
      return false;
    }
    *num_elements_contained += PyArray_NBYTES(array);
    return (*num_elements_contained < RayConfig::instance().num_elements_limit());
  }
  return false;
}