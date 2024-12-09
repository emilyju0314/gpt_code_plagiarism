PyObject * WRAP_hwrite_init(PyObject *self, PyObject *args) {
    int item_hdl, offset, iostat;
    char *type;
    if (!PyArg_ParseTuple(args, "is", &item_hdl, &type)) return NULL;
    try {
        switch(type[0]) {
            case 'a': INIT(char_item,H_BYTE_SIZE); break;
            case 'b': INIT(binary_item,ITEM_HDR_SIZE); break;
            case 'i': INIT(int_item,H_INT_SIZE); break;
            case 'j': INIT(int2_item,H_INT2_SIZE); break;
            case 'l': INIT(int8_item,H_INT8_SIZE); break;
            case 'r': INIT(real_item,H_REAL_SIZE); break;
            case 'd': INIT(dble_item,H_DBLE_SIZE); break;
            case 'c': INIT(cmplx_item,H_CMPLX_SIZE); break;
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