bool ts::ForkPipe::close(Report& report)
{
    // Silent error is already closed
    if (!_is_open) {
        return false;
    }

    // Flush the output buffer, if any.
    if (_in_pipe) {
        flush(); // from std::basic_ostream
    }

    bool result = true;

#if defined(TS_WINDOWS)

    // Close the pipe handle
    if (_use_pipe) {
        report.debug(u"closing pipe handle");
        ::CloseHandle(_handle);
    }

    // Wait for termination of child process
    if (_wait_mode == SYNCHRONOUS && ::WaitForSingleObject(_process, INFINITE) != WAIT_OBJECT_0) {
        report.error(u"error waiting for process termination: %s", {ErrorCodeMessage()});
        result = false;
    }

    if (_process != INVALID_HANDLE_VALUE) {
        report.debug(u"closing process handle");
        ::CloseHandle(_process);
    }

#else // UNIX

    // Close the pipe file descriptor
    if (_use_pipe) {
        ::close(_fd);
    }

    // Wait for termination of forked process
    assert(_fpid != 0);
    if (_wait_mode == SYNCHRONOUS && ::waitpid(_fpid, nullptr, 0) < 0) {
        report.error(u"error waiting for process termination: %s", {ErrorCodeMessage()});
        result = false;
    }

#endif

    _is_open = false;
    return result;
}