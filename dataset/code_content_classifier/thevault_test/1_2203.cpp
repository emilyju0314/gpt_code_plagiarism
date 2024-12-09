JSValue NewLibrary(JSContext* ctx, JSValueConst /*this_val*/, int argc, JSValueConst* /*argv*/) {
  if (argc != 0) {
    return JS_ThrowSyntaxError(ctx,
                               "Wrong number of arguments to fidl.decodeResponse(), "
                               "was %d, expected 0",
                               argc);
  }
  JSValue new_library = JS_NewObjectClass(ctx, fidl_class_id_);
  if (JS_IsException(new_library)) {
    return JS_EXCEPTION;
  }
  JS_SetOpaque(new_library, new fidl_codec::LibraryLoader());
  return new_library;
}