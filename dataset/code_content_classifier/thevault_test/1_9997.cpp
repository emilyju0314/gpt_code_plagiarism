void Logger_PrintString(Dart_NativeArguments args) {
  std::stringstream stream;
  const auto& logger_prefix = UIDartState::Current()->logger_prefix();

#if !OS_ANDROID
  // Prepend all logs with the isolate debug name except on Android where that
  // prefix is specified in the log tag.
  if (logger_prefix.size() > 0) {
    stream << logger_prefix << ": ";
  }
#endif  // !OS_ANDROID

  // Append the log buffer obtained from Dart code.
  {
    Dart_Handle str = Dart_GetNativeArgument(args, 0);
    uint8_t* chars = nullptr;
    intptr_t length = 0;
    Dart_Handle result = Dart_StringToUTF8(str, &chars, &length);
    if (Dart_IsError(result)) {
      Dart_PropagateError(result);
      return;
    }
    if (length > 0) {
      stream << std::string{reinterpret_cast<const char*>(chars),
                            static_cast<size_t>(length)};
    }
  }

  const auto log_string = stream.str();
  const char* chars = log_string.c_str();
  const size_t length = log_string.size();

  // Log using platform specific mechanisms
  {
#if defined(OS_ANDROID)
    // Write to the logcat on Android.
    __android_log_print(ANDROID_LOG_INFO, logger_prefix.c_str(), "%.*s",
                        (int)length, chars);
#elif defined(OS_IOS)
    // Write to syslog on iOS.
    //
    // TODO(cbracken): replace with dedicated communication channel and bypass
    // iOS logging APIs altogether.
    syslog(1 /* LOG_ALERT */, "%.*s", (int)length, chars);
#else
    std::cout << log_string << std::endl;
#endif
  }

  if (dart::bin::ShouldCaptureStdout()) {
    // For now we report print output on the Stdout stream.
    uint8_t newline[] = {'\n'};
    Dart_ServiceSendDataEvent("Stdout", "WriteEvent",
                              reinterpret_cast<const uint8_t*>(chars), length);
    Dart_ServiceSendDataEvent("Stdout", "WriteEvent", newline, sizeof(newline));
  }
}