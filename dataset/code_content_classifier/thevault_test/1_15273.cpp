static String FlagToEnvVar(const char* flag) {
  const String full_flag =
      (Message() << GTEST_FLAG_PREFIX_ << flag).GetString();

  Message env_var;
  for (size_t i = 0; i != full_flag.length(); i++) {
    env_var << static_cast<char>(toupper(full_flag.c_str()[i]));
  }

  return env_var.GetString();
}