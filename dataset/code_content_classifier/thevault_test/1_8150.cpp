LanguageAndCodePage *GetTranslate(const void *data) {
  static constexpr wchar_t kTranslation[] = L"\\VarFileInfo\\Translation";
  LPVOID translate = nullptr;
  UINT dummy_size;
  if (::VerQueryValue(data, kTranslation, &translate, &dummy_size)) {
    return static_cast<LanguageAndCodePage *>(translate);
  }
  return nullptr;
}