bool Environment::Initialize(const vec2i& /*window_size*/,
                             const char* /*window_title*/,
                             WindowMode /*window_mode*/) {
#if defined(_WIN32) && !defined(FPLBASE_GLES)
#define GLEXT(type, name, required) \
  LOOKUP_GL_FUNCTION(type, name, required, wglGetProcAddress)
  GLBASEEXTS GLEXTS
#undef GLEXT
#endif  // defined(_WIN32)

#ifndef PLATFORM_MOBILE
#ifdef GL_MAJOR_VERSION
  GLint version = 0;
  glGetIntegerv(GL_MAJOR_VERSION, &version);
  if (glGetError() == 0) {
    if (version >= 3) {
      feature_level_ = kFeatureLevel30;
    }
  }
#endif  // defined(GL_MAJOR_VERSION)
#endif  // !defined(PLATFORM_MOBILE)

#ifdef __ANDROID__
  const int version = AndroidGetContextClientVersion();
  if (version >= 3) {
    feature_level_ = kFeatureLevel30;
    AndroidInitGl3Functions();
  }

#ifdef FPLBASE_GLES
#define GLEXT(type, name, required) \
  LOOKUP_GL_FUNCTION(type, name, required, eglGetProcAddress)
  GLESEXTS
#undef GLEXT
#endif  // FPLBASE_GLES
#endif  // defined(__ANDROID__)

#if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
  const int version = IosGetContextClientVersion();
  assert(version >= 2);
  if (version >= 3) {
    feature_level_ = kFeatureLevel30;
  }
#endif  // TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
  return true;
}