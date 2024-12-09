void CSSHSession::initialise()
    {
        static bool intialised{false};
        if (!intialised)
        {
            ssh_threads_set_callbacks(ssh_threads_get_pthread());
            ssh_init();
            intialised = true;
        }
    }