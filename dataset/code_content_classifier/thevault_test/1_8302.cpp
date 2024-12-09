PyObject * WRAP_hwrite(PyObject *self, PyObject *args) {
    int item_hdl, offset, iostat;
    char *type;
    PyObject *val;
    int in; short sh; long lg; float fl; double db; float cx[2]; char *st;
    if (!PyArg_ParseTuple(args, "iiOs", &item_hdl, &offset, &val, &type))
        return NULL;
    try {
        switch (type[0]) {
            case 'a':
                CHK_STRING(val);
                st = const_cast<char*>(PyString_AsString(val));
                in = PyString_Size(val); // # bytes to write
                hwriteb_c(item_hdl, st, offset, in, &iostat);
                CHK_IO(iostat);
                offset = H_BYTE_SIZE * in;
                break;
            case 'i':
                CHK_INT(val);
                in = (int) PyInt_AsLong(val);
                hwritei_c(item_hdl, &in, offset, H_INT_SIZE, &iostat);
                CHK_IO(iostat);
                offset = H_INT_SIZE;
                break;
            case 'j':
                CHK_INT(val);
                sh = (short) PyInt_AsLong(val);
                hwritej_c(item_hdl, &sh, offset, H_INT2_SIZE, &iostat);
                CHK_IO(iostat);
                offset = H_INT2_SIZE;
                break;
            case 'l':
                CHK_LONG(val);
                lg = PyLong_AsLong(val);
                hwritel_c(item_hdl, &lg, offset, H_INT8_SIZE, &iostat);
                CHK_IO(iostat);
                offset = H_INT8_SIZE;
                break;
            case 'r':
                CHK_FLOAT(val);
                fl = (float) PyFloat_AsDouble(val);
                hwriter_c(item_hdl, &fl, offset, H_REAL_SIZE, &iostat);
                CHK_IO(iostat);
                offset = H_REAL_SIZE;
                break;
            case 'd':
                CHK_FLOAT(val);
                db = PyFloat_AsDouble(val);
                hwrited_c(item_hdl, &db, offset, H_DBLE_SIZE, &iostat);
                CHK_IO(iostat);
                offset = H_DBLE_SIZE;
                break;
            case 'c':
                CHK_COMPLEX(val);
                cx[0] = (float) PyComplex_RealAsDouble(val);
                cx[1] = (float) PyComplex_ImagAsDouble(val);
                hwritec_c(item_hdl, cx, offset, H_CMPLX_SIZE, &iostat);
                CHK_IO(iostat);
                offset = H_CMPLX_SIZE;
                break;
            default:
                PyErr_Format(PyExc_ValueError, "unknown item type: %c", type[0]);
                return NULL;
        }
        return PyInt_FromLong(offset);
    } catch (MiriadError &e) {
        PyErr_Format(PyExc_RuntimeError, "%s", e.get_message());
        return NULL;
    }
}