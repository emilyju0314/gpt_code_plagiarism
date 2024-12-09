static uint64_t ConstructTimeoutId(ConnectionId connectionId, PacketId packetId, ReliabilityType reliability)
    {
        const uint64_t intConnectionId = aznumeric_cast<uint64_t>(connectionId);
        const uint64_t intPacketId = aznumeric_cast<uint64_t>(packetId);
        const uint64_t intReliability = (reliability == ReliabilityType::Reliable) ? 1 : 0;
        const uint64_t baseTimeoutId = ((intConnectionId << 32) | intPacketId) & 0x7FFFFFFFFFFFFFFF;
        return (intReliability << 63) | baseTimeoutId;
    }