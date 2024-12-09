PyObject *PyTask_make(ray::raylet::TaskSpecification *task_spec) {
  PyTask *result = PyObject_New(PyTask, &PyTaskType);
  result = (PyTask *)PyObject_Init((PyObject *)result, &PyTaskType);
  result->task_spec = task_spec;
  // The created task does not include any execution dependencies.
  result->execution_dependencies = new std::vector<ObjectID>();
  return (PyObject *)result;
}