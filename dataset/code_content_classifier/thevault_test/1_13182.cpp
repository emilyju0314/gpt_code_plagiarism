char * newCString(const Napi::Value& src) {
    if (src.IsString()) {
      Napi::String strSrc = src.As<Napi::String>();
      return newCString((std::string)strSrc);
    } else {
      return nullptr;
    }
}