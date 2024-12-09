void ts::EITProcessor::processPacket(TSPacket& pkt)
{
    if (_input_pids.test(pkt.getPID())) {
        _demux.feedPacket(pkt);
        _packetizer.getNextPacket(pkt);
    }
}