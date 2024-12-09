void ts::PESPlugin::handleNewAVCAttributes(PESDemux&, const PESPacket& pkt, const AVCAttributes& va)
{
    if (!_video_attributes) {
        return;
    }

    std::ostream& out(_outfile.is_open() ? _outfile : std::cout);

    out << UString::Format(u"* PID 0x%X, stream_id %s, AVC video attributes:", {pkt.getSourcePID(), names::StreamId(pkt.getStreamId(), names::FIRST)})
        << std::endl
        << "  " << va << std::endl;

    lastDump(out);
}