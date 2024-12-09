VOID ProcessWin32::ProcessExitCallback(PVOID processPtr, [[maybe_unused]] BOOLEAN EventSignalled)
    {
        // Lock the process destructor from being entered from the client thread
        AZStd::lock_guard lifeLock(m_lifeCycleMutex);

        ProcessId id = reinterpret_cast<ProcessId>(processPtr);
        auto process = m_masterProcessList[id];

        // Check that the process hasn't already been destructed from the client thread
        if (process && process->m_isRunning)
        {
            // Lock state access and/or mutation from the client thread
            AZStd::lock_guard stateLock(process->m_stateMutex);
            process->RetrieveOSReturnCodeAndCleanUpProcess();
        }
    }