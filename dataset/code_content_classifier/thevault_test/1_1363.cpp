PyObject *PyTask_from_string(PyObject *self, PyObject *args) {
  const char *data;
  int size;
  if (!PyArg_ParseTuple(args, "s#", &data, &size)) {
    return NULL;
  }
  PyTask *result = PyObject_New(PyTask, &PyTaskType);
  result = (PyTask *)PyObject_Init((PyObject *)result, &PyTaskType);
  result->task_spec = new ray::raylet::TaskSpecification(std::string(data, size));
  /* The created task does not include any execution dependencies. */
  result->execution_dependencies = new std::vector<ObjectID>();
  /* TODO(pcm): Use flatbuffers validation here. */
  return (PyObject *)result;
}