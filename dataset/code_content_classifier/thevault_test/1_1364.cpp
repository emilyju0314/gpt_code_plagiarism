PyObject *PyTask_to_string(PyObject *self, PyObject *args) {
  PyObject *arg;
  if (!PyArg_ParseTuple(args, "O", &arg)) {
    return NULL;
  }
  PyTask *task = (PyTask *)arg;
  flatbuffers::FlatBufferBuilder fbb;
  auto task_spec_string = task->task_spec->ToFlatbuffer(fbb);
  fbb.Finish(task_spec_string);
  return PyBytes_FromStringAndSize((char *)fbb.GetBufferPointer(), fbb.GetSize());
}