auto ProcWatch::update() noexcept -> void
{
        // keep track of (previously) focused window pid/name
        auto static previous_active_window_pid = pid_t{0};

        while (!terminate)
        {
                // only update state / apply rules if we are active
                if(active)
                {
                        // query currently focused window PID
                        auto focused_window_pid = XDisplay::queryFocusedWindowPID();
                        if(focused_window_pid)
                        {
                                // if focus has changed
                                if(focused_window_pid != previous_active_window_pid)
                                {
                                        // update comm this has changed since the last update
                                        active_window_comm = pid_to_comm(focused_window_pid);

                                        dirty = true;
                                        previous_active_window_pid = focused_window_pid;
                                }

                                if(dirty)
                                        applyRule(active_window_comm);
                        }
                }
                // go back to sleep for sleep_ms
                sleep_for(ms(sleep_ms));
        }
}