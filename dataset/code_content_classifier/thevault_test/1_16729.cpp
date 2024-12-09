v8::Local<v8::ObjectTemplate> Utils::GetTemplate(v8::Isolate* isolate) {
  static v8::Persistent<v8::ObjectTemplate> icu_template;

  if (icu_template.IsEmpty()) {
    v8::Local<v8::ObjectTemplate> raw_template(v8::ObjectTemplate::New());

    // Set aside internal field for ICU class.
    raw_template->SetInternalFieldCount(1);

    icu_template.Reset(isolate, raw_template);
  }

  return v8::Local<v8::ObjectTemplate>::New(isolate, icu_template);
}