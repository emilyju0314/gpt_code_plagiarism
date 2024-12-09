ts::ProcessorPlugin::Status FooBarPlugin::processPacket(ts::TSPacket& pkt, ts::TSPacketMetadata& metadata)
{
    if (pkt.getPID() == _pid) {
        _count++;
    }
    return TSP_OK;
}