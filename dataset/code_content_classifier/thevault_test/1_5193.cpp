void ts::PESPlugin::handleNewAC3Attributes(PESDemux&, const PESPacket& pkt, const AC3Attributes& aa)
{
    if (!_audio_attributes) {
        return;
    }

    std::ostream& out(_outfile.is_open() ? _outfile : std::cout);

    out << UString::Format(u"* PID 0x%X, stream_id %s, AC-3 audio attributes:", {pkt.getSourcePID(), names::StreamId(pkt.getStreamId(), names::FIRST)})
        << std::endl
        << "  " << aa << std::endl;

    lastDump(out);
}