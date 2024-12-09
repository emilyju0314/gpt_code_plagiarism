void ts::PESDemux::handlePESPacket(const PESPacket& packet)
{
    if (_pes_handler != nullptr) {
        _pes_handler->handlePESPacket(*this, packet);
    }
}