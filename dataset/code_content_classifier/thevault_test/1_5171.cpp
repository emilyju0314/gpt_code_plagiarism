void ts::EITProcessor::addInputPID(ts::PID pid)
{
    _demux.addPID(pid);
    _input_pids.set(pid);
}