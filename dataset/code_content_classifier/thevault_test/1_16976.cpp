std::unique_ptr<android_dlextinfo> MakeAndroidDlextinfo(
    const ScopedAnonymousMmap& mapping) {
  auto info = std::make_unique<android_dlextinfo>();
  memset(info.get(), 0, sizeof(*info));
  info->flags = ANDROID_DLEXT_RESERVED_ADDRESS;
  info->reserved_addr = mapping.address();
  info->reserved_size = mapping.size();

  return info;
}