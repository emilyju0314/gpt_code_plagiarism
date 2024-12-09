bool
launch_command(const std::string& cmd) {
    int status = system(cmd.c_str());
    if (status < 0) {
        LOG_ERR_("Error: " + std::string(strerror(errno)) + "", "dispatcher");
        return false;
    } else {
        if (WIFEXITED(status)) {
            LOG_DEBUG_("Program returned normally, exit code " +
                           std::to_string(WEXITSTATUS(status)),
                       "dispatcher");
            return true;
        } else
            LOG_WARN_("Program exited abnormaly.", "dispatcher");
    }
    return false;
}