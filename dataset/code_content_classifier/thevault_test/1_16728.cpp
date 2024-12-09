icu::UnicodeString* ResetAdoptedText(
    v8::Handle<v8::Object> obj, v8::Handle<v8::Value> value) {
  // Get the previous value from the internal field.
  icu::UnicodeString* text = static_cast<icu::UnicodeString*>(
      obj->GetAlignedPointerFromInternalField(1));
  delete text;

  // Assign new value to the internal pointer.
  v8::String::Value text_value(value);
  text = new icu::UnicodeString(
      reinterpret_cast<const UChar*>(*text_value), text_value.length());
  obj->SetAlignedPointerInInternalField(1, text);

  // Return new unicode string pointer.
  return text;
}