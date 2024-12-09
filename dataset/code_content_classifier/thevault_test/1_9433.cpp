void AppendDefaultVersion(ShaderProfile profile, std::string *result) {
  if (profile == kShaderProfileCore) {
    AppendVersion(kDefaultDesktopVersion, result);
  }
}