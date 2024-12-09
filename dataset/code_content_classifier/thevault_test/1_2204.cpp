JSValue Close(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* /*argv*/) {
  if (argc != 0) {
    return JS_ThrowSyntaxError(ctx,
                               "Wrong number of arguments to fidl.decodeResponse(), "
                               "was %d, expected 0",
                               argc);
  }
  auto loader =
      reinterpret_cast<fidl_codec::LibraryLoader*>(JS_GetOpaque(this_val, fidl_class_id_));
  if (loader == nullptr) {
    return JS_EXCEPTION;
  }
  delete loader;
  JS_SetOpaque(this_val, nullptr);
  return JS_UNDEFINED;
}