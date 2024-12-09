void ts::PESDemux::immediateReset()
{
    SuperClass::immediateReset();
    _pids.clear();
    _stream_types.clear();

    // Reset the section demux back to initial state (intercepting the PAT).
    _section_demux.reset();
    _section_demux.addPID(PID_PAT);
}