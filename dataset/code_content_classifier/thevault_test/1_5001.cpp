EMSCRIPTEN_BINDINGS(google_smart_card) {
  emscripten::class_<GoogleSmartCardModule>("GoogleSmartCardModule")
      .constructor<emscripten::val>()
      .function("postMessage", &GoogleSmartCardModule::OnMessageReceivedFromJs);
}