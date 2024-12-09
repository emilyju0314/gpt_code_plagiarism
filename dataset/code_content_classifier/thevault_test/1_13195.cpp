PBXAttributes ProjectAttributesFromBuildSettings(
    const BuildSettings* build_settings) {
  const TargetOsType target_os = GetTargetOs(build_settings->build_args());

  PBXAttributes attributes;
  switch (target_os) {
    case WRITER_TARGET_OS_IOS:
      attributes["SDKROOT"] = "iphoneos";
      attributes["TARGETED_DEVICE_FAMILY"] = "1,2";
      break;
    case WRITER_TARGET_OS_MACOS:
      attributes["SDKROOT"] = "macosx";
      break;
  }

  return attributes;
}