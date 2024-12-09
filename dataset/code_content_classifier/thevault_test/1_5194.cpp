void ts::PESPlugin::handleNewVideoAttributes(PESDemux&, const PESPacket& pkt, const VideoAttributes& va)
{
    if (!_video_attributes) {
        return;
    }

    std::ostream& out(_outfile.is_open() ? _outfile : std::cout);

    out << UString::Format(u"* PID 0x%X, stream_id %s, video attributes:", {pkt.getSourcePID(), names::StreamId(pkt.getStreamId(), names::FIRST)})
        << std::endl
        << "  " << va << std::endl
        << UString::Format(u"  Maximum bitrate: %'d b/s, VBV buffer size: %'d bits", {va.maximumBitRate(), va.vbvSize()})
        << std::endl;

    lastDump(out);
}