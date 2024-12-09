void ts::AbstractTablePlugin::setPID(PID pid)
{
    // Reset demux and packetizer if we change PID.
    if (pid != _pid) {
        _pid = pid;
        _found_pid = false;
        _demux.reset();
        _demux.addPID(_pid);
        _pzer.reset();
        _pzer.setPID(_pid);
    }
}