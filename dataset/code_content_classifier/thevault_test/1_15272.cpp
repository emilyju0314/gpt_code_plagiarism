CapturedStream(int fd) : fd_(fd), uncaptured_fd_(dup(fd)) {
#if GTEST_OS_WINDOWS
    char temp_dir_path[MAX_PATH + 1] = { '\0' };  // NOLINT
    char temp_file_path[MAX_PATH + 1] = { '\0' };  // NOLINT

    ::GetTempPathA(sizeof(temp_dir_path), temp_dir_path);
    const UINT success = ::GetTempFileNameA(temp_dir_path,
                                            "gtest_redir",
                                            0,  // Generate unique file name.
                                            temp_file_path);
    GTEST_CHECK_(success != 0)
        << "Unable to create a temporary file in " << temp_dir_path;
    const int captured_fd = creat(temp_file_path, _S_IREAD | _S_IWRITE);
    GTEST_CHECK_(captured_fd != -1) << "Unable to open temporary file "
                                    << temp_file_path;
    filename_ = temp_file_path;
#else
    // There's no guarantee that a test has write access to the
    // current directory, so we create the temporary file in the /tmp
    // directory instead.
    char name_template[] = "/tmp/captured_stream.XXXXXX";
    const int captured_fd = mkstemp(name_template);
    filename_ = name_template;
#endif  // GTEST_OS_WINDOWS
    fflush(NULL);
    dup2(captured_fd, fd_);
    close(captured_fd);
  }