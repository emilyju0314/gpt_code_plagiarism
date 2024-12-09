void ts::PESPlugin::handleNewAudioAttributes(PESDemux&, const PESPacket& pkt, const AudioAttributes& aa)
{
    if (!_audio_attributes) {
        return;
    }

    std::ostream& out(_outfile.is_open() ? _outfile : std::cout);

    out << UString::Format(u"* PID 0x%04X, stream_id %s, audio attributes:", {pkt.getSourcePID(), names::StreamId(pkt.getStreamId(), names::FIRST)})
        << std::endl
        << "  " << aa << std::endl;

    lastDump(out);
}