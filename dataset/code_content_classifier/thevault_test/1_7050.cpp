v8::Handle<v8::Value> Read(const v8::Arguments& args) {
  if (args.Length() != 1) {
    return StringException("Usage: read(filename)");
  }
  v8::String::Utf8Value file(args[0]);
  if (*file == NULL) {
    return StringException("read(): Missing filename");
  }
  v8::Handle<v8::Value> source = ReadFile(*file);
  if (source.IsEmpty() || !source->IsString()) {
    return StringException("read(): Error loading file");
  }
  return source;
}