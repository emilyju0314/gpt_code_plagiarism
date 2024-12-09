void ts::EITGenerator::setOptions(int options)
{
    _options = options;
    if (_options & EIT_INPUT) {
        _demux.addPID(_eit_pid);
    }
    else {
        _demux.removePID(_eit_pid);
    }
}