void ts::EITGenerator::reset()
{
    _ts_id = 0;
    _ts_id_set = false;
    _demux.reset();
    _demux.addPID(PID_PAT);
    _packetizer.reset();
    _sections.clear();
}