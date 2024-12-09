void ts::EITProcessor::setOutputPID(ts::PID pid)
{
    if (pid != _output_pid) {
        _packetizer.reset();
        _packetizer.setPID(pid);
        _output_pid = pid;
    }
}