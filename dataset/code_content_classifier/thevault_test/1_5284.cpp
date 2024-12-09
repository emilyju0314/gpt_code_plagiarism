bool ts::AbstractHTTPInputPlugin::pushPackets(const TSPacket* buffer, size_t count)
{
    // If an intermediate save file was specified, save the packets.
    // Display errors but do not fail, this is just auto save.
    if (_outSave.isOpen() && !_outSave.write(buffer, count, *tsp)) {
        _outSave.close(*tsp);
    }

    // Invoke superclass to actually push the packets.
    return PushInputPlugin::pushPackets(buffer, count);
}