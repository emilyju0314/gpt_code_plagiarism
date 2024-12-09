PyObject *PyObjectID_make(ObjectID object_id) {
  PyObjectID *result = PyObject_New(PyObjectID, &PyObjectIDType);
  result = (PyObjectID *)PyObject_Init((PyObject *)result, &PyObjectIDType);
  result->object_id = object_id;
  return (PyObject *)result;
}