void HIRBuilder::addLoadArgs(TranslationContext& tc, int num_args) {
  if (code_->co_flags & CO_STATICALLY_COMPILED) {
    _Py_CODEUNIT* rawcode = code_->co_rawcode;
    JIT_CHECK(
        _Py_OPCODE(rawcode[0]) == CHECK_ARGS, "expected CHECK_ARGS as 1st arg");
    PyObject* checks =
        PyTuple_GET_ITEM(code_->co_consts, _Py_OPARG(rawcode[0]));

    for (int i = 0; i < num_args; i++) {
      Register* dst = tc.frame.locals[i];
      Type type = TObject;
      // Arguments in CPython are the first N locals
      for (Py_ssize_t cur_check = 0; cur_check < PyTuple_GET_SIZE(checks) / 2;
           cur_check++) {
        long local = PyLong_AsLong(PyTuple_GET_ITEM(checks, cur_check * 2));
        if (local == i) {
          PyObject* type_descr = PyTuple_GET_ITEM(checks, cur_check * 2 + 1);
          int prim_type = _PyClassLoader_ResolvePrimitiveType(type_descr);
          JIT_CHECK(prim_type != -1, "unknown type");
          if (prim_type != TYPED_OBJECT) {
            type = prim_type_to_type(prim_type);
          }
          break;
        }
      }
      JIT_CHECK(dst != nullptr, "No register for argument %d", i);
      tc.emit<LoadArg>(dst, i, type);
    }
  } else {
    for (int i = 0; i < num_args; i++) {
      // Arguments in CPython are the first N locals
      Register* dst = tc.frame.locals[i];
      JIT_CHECK(dst != nullptr, "No register for argument %d", i);
      tc.emit<LoadArg>(dst, i);
    }
  }
}