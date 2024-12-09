PyObject * WRAP_hread_init(PyObject *self, PyObject *args) {
    int item_hdl, offset, iostat, code;
    char s[ITEM_HDR_SIZE];
    if (!PyArg_ParseTuple(args, "i", &item_hdl)) return NULL;
    try {
        hreadb_c(item_hdl,s,0,ITEM_HDR_SIZE,&iostat);
        CHK_IO(iostat);
        code = FIRSTINT(s);
        if (code == FIRSTINT(char_item)) {
            offset = mroundup(ITEM_HDR_SIZE,H_BYTE_SIZE);
            return Py_BuildValue("si", "a", offset);
        } else if (code == FIRSTINT(binary_item)) {
            return Py_BuildValue("si", "b", ITEM_HDR_SIZE);
        } else if (code == FIRSTINT(int_item)) {
            offset = mroundup(ITEM_HDR_SIZE,H_INT_SIZE);
            return Py_BuildValue("si", "i", offset);
        } else if (code == FIRSTINT(int2_item)) {
            offset = mroundup(ITEM_HDR_SIZE,H_INT2_SIZE);
            return Py_BuildValue("si", "j", offset);
        } else if (code == FIRSTINT(int8_item)) {
            offset = mroundup(ITEM_HDR_SIZE,H_INT8_SIZE);
            return Py_BuildValue("si", "l", offset);
        } else if (code == FIRSTINT(real_item)) {
            offset = mroundup(ITEM_HDR_SIZE,H_REAL_SIZE);
            return Py_BuildValue("si", "r", offset);
        } else if (code == FIRSTINT(dble_item)) {
            offset = mroundup(ITEM_HDR_SIZE,H_DBLE_SIZE);
            return Py_BuildValue("si", "d", offset);
        } else if (code == FIRSTINT(cmplx_item)) {
            offset = mroundup(ITEM_HDR_SIZE,H_CMPLX_SIZE);
            return Py_BuildValue("si", "c", offset);
        }
        PyErr_Format(PyExc_RuntimeError, "unknown item type");
        return NULL;
    } catch (MiriadError &e) {
        PyErr_Format(PyExc_RuntimeError, "%s", e.get_message());
        return NULL;
    }
}