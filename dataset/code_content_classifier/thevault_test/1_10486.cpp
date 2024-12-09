static std::string ScrollViewCommand(const std::string &scrollview_path) {
  // The following ugly ifdef is to enable the output of the java runtime
  // to be sent down a black hole on non-windows to ignore all the
  // exceptions in piccolo. Ideally piccolo would be debugged to make
  // this unnecessary.
  // Also the path has to be separated by ; on windows and : otherwise.
#  ifdef _WIN32
  const char cmd_template[] =
      "-Djava.library.path=\"%s\" -jar \"%s/ScrollView.jar\"";

#  else
  const char cmd_template[] =
      "-c \"trap 'kill %%1' 0 1 2 ; java "
      "-Xms1024m -Xmx2048m -jar %s/ScrollView.jar"
      " & wait\"";
#  endif
  size_t cmdlen = sizeof(cmd_template) + 2 * scrollview_path.size() + 1;
  std::vector<char> cmd(cmdlen);
  const char *sv_path = scrollview_path.c_str();
#  ifdef _WIN32
  snprintf(&cmd[0], cmdlen, cmd_template, sv_path, sv_path);
#  else
  snprintf(&cmd[0], cmdlen, cmd_template, sv_path);
#  endif
  std::string command(&cmd[0]);
  return command;
}