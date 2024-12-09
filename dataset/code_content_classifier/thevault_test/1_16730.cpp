v8::Local<v8::ObjectTemplate> Utils::GetTemplate2(v8::Isolate* isolate) {
  static v8::Persistent<v8::ObjectTemplate> icu_template_2;

  if (icu_template_2.IsEmpty()) {
    v8::Local<v8::ObjectTemplate> raw_template(v8::ObjectTemplate::New());

    // Set aside internal field for ICU class and additional data.
    raw_template->SetInternalFieldCount(2);

    icu_template_2.Reset(isolate, raw_template);
  }

  return v8::Local<v8::ObjectTemplate>::New(isolate, icu_template_2);
}