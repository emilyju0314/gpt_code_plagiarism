bool TestService::isStarted(const std::string& id)
{
    // FIXME!!! A lot of code dublicate with Utils::runScript

    std::string real_path = dir::INST + "/bin/klktestservice.sh";
    if (base::Utils::fileExist(real_path) == false)
    {
        throw Exception(__FILE__, __LINE__,
                             "Path '" + real_path + "' does not exist");
    }

    std::string prg = "/bin/sh", prg_name = "sh";
    if (base::Utils::fileExist(prg) == false)
    {
        throw Exception(__FILE__, __LINE__,
                             "Path '" + std::string(prg) +
                             "' does not exist");
    }

    pid_t pid = 0;
    int status = 0;

    switch (pid = fork())
    {
    case -1:
        throw Exception(__FILE__, __LINE__, "Error %d in fork(): %s\n",
                             errno, strerror(errno));
    case 0:
        execl(prg.c_str(), prg_name.c_str(), real_path.c_str(),
              id.c_str(), NULL);
        exit(errno);
    }

    // wait for child end
    if ((waitpid(pid, &status, 0) == pid) < 0)
    {
        throw Exception(__FILE__, __LINE__, "Error %d in waitpid(): %s",
                        errno, strerror(errno));
    }

    if (WIFEXITED(status))
    {
        if (WEXITSTATUS(status) == 0)
            return true;
    }

    return false;
}