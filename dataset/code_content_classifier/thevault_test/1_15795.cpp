std::set<EGLextension> extensions(std::set<std::string> * const unknown)
{
    std::set<EGLextension> extensions;

    const auto egl_display = eglGetDisplay( (EGLNativeDisplayType) EGL_DEFAULT_DISPLAY );
    const auto extensionString = eglQueryString(egl_display, (EGLint)EGL_EXTENSIONS);

    if (!extensionString)
    {
        return extensions;
    }

    std::istringstream stream{ reinterpret_cast<const char *>(extensionString) };
    auto extensionName = std::string{ };

    while (std::getline(stream, extensionName, ' '))
    {
        insertExtension(extensionName, &extensions, unknown);
    }

    return extensions;
}