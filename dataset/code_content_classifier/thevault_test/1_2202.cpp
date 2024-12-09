JSValue LoadLibrary(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
  if (argc != 1) {
    return JS_ThrowSyntaxError(ctx,
                               "Wrong number of arguments to fidl.loadLibrary(), "
                               "was %d, expected 1",
                               argc);
  }
  auto loader =
      reinterpret_cast<fidl_codec::LibraryLoader*>(JS_GetOpaque(this_val, fidl_class_id_));
  if (loader == nullptr) {
    return JS_EXCEPTION;
  }

  CStringHolder val(ctx, argv[0]);
  const char* path = val.get();
  if (!path) {
    return JS_EXCEPTION;
  }
  fidl_codec::LibraryReadError loader_err;
  std::unique_ptr<std::istream> path_ptr(new std::ifstream(path));
  loader->Add(&path_ptr, &loader_err);

  return JS_NewBool(ctx, loader_err.value == fidl_codec::LibraryReadError::kOk);
}