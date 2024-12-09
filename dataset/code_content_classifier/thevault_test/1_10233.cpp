impala::Status AttachStdoutStderrLocked() {
  // Redirect stdout to INFO log and stderr to ERROR log.
  // Needs to be done after InitGoogleLogging, to get the INFO/ERROR file paths.
  string info_log_symlink_path, error_log_symlink_path;
  impala::GetFullLogFilename(google::INFO, &info_log_symlink_path);
  impala::GetFullLogFilename(google::ERROR, &error_log_symlink_path);

  string info_log_path, error_log_path;
  RETURN_IF_ERROR(ResolveLogSymlink(info_log_symlink_path, info_log_path));
  RETURN_IF_ERROR(ResolveLogSymlink(error_log_symlink_path, error_log_path));

  bool info_log_rotated = last_info_log_path != info_log_path;
  bool error_log_rotated = last_error_log_path != error_log_path;

  if (info_log_rotated != error_log_rotated) {
    // Since we're not holding glog's log_mutex when resolving the symlinks, it is
    // possible that glog rotates the INFO and ERROR log independently in between our
    // symlink resolution. If this happens, log a warning and continue.
    // Next AttachStdoutStderrLocked call should redirect the stream to the newer file.
    LOG(WARNING) << "INFO and ERROR log is not rotated at the same time "
                 << "(info_log_rotated=" << info_log_rotated << ", "
                 << "error_log_rotated=" << error_log_rotated << "). "
                 << "STDOUT/STDERR might still write to an older log file.";
  }

  if (info_log_rotated) {
    // Print to stdout before redirecting so people looking for these logs in the standard
    // place know where to look.
    cout << "Redirecting stdout to " << info_log_symlink_path << endl;
    // TODO: how to handle these errors? Maybe abort the process?
    if (freopen(info_log_path.c_str(), "a", stdout) == NULL) {
      cout << "Could not redirect stdout: " << impala::GetStrErrMsg();
    }
    last_info_log_path = info_log_path;
  }

  if (error_log_rotated) {
    // Similar to stdout, do the same thing for stderr.
    cerr << "Redirecting stderr to " << error_log_symlink_path << endl;
    if (freopen(error_log_path.c_str(), "a", stderr) == NULL) {
      cerr << "Could not redirect stderr: " << impala::GetStrErrMsg();
    }
    last_error_log_path = error_log_path;
  }
  return impala::Status::OK();
}