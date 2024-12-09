void ts::EITProcessor::setInputPID(ts::PID pid)
{
    // Don't break the state if there is exactly the same uniqeu input PID.
    if (_input_pids.count() != 1 || !_input_pids.test(pid)) {
        clearInputPIDs();
        addInputPID(pid);
    }
}