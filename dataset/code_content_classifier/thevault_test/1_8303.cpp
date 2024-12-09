PyObject * WRAP_hread(PyObject *self, PyObject *args) {
    int item_hdl, offset, iostat;
    char *type;
    PyObject *val, *rv;
    int in; short sh; long lg; float fl; double db; float cx[2]; char st[2];
    if (!PyArg_ParseTuple(args, "iis", &item_hdl, &offset, &type))
        return NULL;
    try {
        switch (type[0]) {
            case 'a':
                hreadb_c(item_hdl, st, offset, H_BYTE_SIZE, &iostat);
                CHK_IO(iostat);
#if PY_MAJOR_VERSION >= 3
                return Py_BuildValue("yi", st, H_BYTE_SIZE);
#else
                return Py_BuildValue("si", st, H_BYTE_SIZE);
#endif
            case 'i':
                hreadi_c(item_hdl, &in, offset, H_INT_SIZE, &iostat);
                CHK_IO(iostat);
                return Py_BuildValue("ii", in, H_INT_SIZE);
            case 'j':
                hreadj_c(item_hdl, &sh, offset, H_INT2_SIZE, &iostat);
                CHK_IO(iostat);
                return Py_BuildValue("ii", sh, H_INT2_SIZE);
            case 'l':
                hreadl_c(item_hdl, &lg, offset, H_INT8_SIZE, &iostat);
                CHK_IO(iostat);
                return Py_BuildValue("li", lg, H_INT8_SIZE);
            case 'r':
                hreadr_c(item_hdl, &fl, offset, H_REAL_SIZE, &iostat);
                CHK_IO(iostat);
                return Py_BuildValue("fi", fl, H_REAL_SIZE);
            case 'd':
                hreadd_c(item_hdl, &db, offset, H_DBLE_SIZE, &iostat);
                CHK_IO(iostat);
                return Py_BuildValue("fi", db, H_DBLE_SIZE);
            case 'c':
                hreadc_c(item_hdl, cx, offset, H_CMPLX_SIZE, &iostat);
                CHK_IO(iostat);
                val = PyComplex_FromDoubles((double) cx[0], (double) cx[1]);
                rv = Py_BuildValue("Oi", val, H_CMPLX_SIZE);
                Py_DECREF(val);
                return rv;
            default:
                PyErr_Format(PyExc_ValueError, "unknown item type: %c", type[0]);
                return NULL;
        }
    } catch (MiriadError &e) {
        PyErr_Format(PyExc_RuntimeError, "%s", e.get_message());
        return NULL;
    }
}