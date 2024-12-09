static bool no_running_children()
{
#ifndef _WIN32
    pid_t wait_result;

    // Acknowledge and complain about any zombie children
    do
    {
	int status = 0;
        wait_result = waitpid(-1, &status, WNOHANG);

        if (wait_result > 0)
        {
            char buf[256];
            snprintf(buf, sizeof(buf) - 1, "%d", wait_result);
            buf[sizeof(buf)-1] = '\0';
            WVFAILEQ("Unclaimed dead child process", buf);
        }
    } while (wait_result > 0);

    // There should not be any running children, so waitpid should return -1
    WVPASSEQ(errno, ECHILD);
    WVPASSEQ(wait_result, -1);
    return (wait_result == -1 && errno == ECHILD);
#endif
    return true;
}