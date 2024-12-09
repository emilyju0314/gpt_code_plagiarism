v8::Handle<v8::Value> Load(const v8::Arguments& args) {
  for (int i = 0; i < args.Length(); i++) {
    v8::HandleScope handle_scope;
    v8::String::Utf8Value filename(args[i]);
    if (*filename == NULL) {
      return StringException("load(): Missing filename");
    }
    v8::Handle<v8::String> source = v8::Handle<v8::String>::Cast(
        ReadFile(*filename));
    if (source.IsEmpty() || !source->IsString()) {
      return StringException("load(): Error loading file");
    }
    if (!ExecuteString(source, v8::String::New(*filename), false, false)) {
      return StringException("load(): Error executing file");
    }
  }
  return v8::Undefined();
}