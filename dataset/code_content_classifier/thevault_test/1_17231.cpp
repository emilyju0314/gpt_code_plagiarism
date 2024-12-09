void PacketManager::SendErrorResponse(
    std::vector<std::pair<NetworkMessageType, std::string>> error_status) {
  std::unique_ptr<OutputPacket> pkt(new OutputPacket());
  pkt->msg_type = NetworkMessageType::ERROR_RESPONSE;

  for (auto entry : error_status) {
    PacketPutByte(pkt.get(), static_cast<unsigned char>(entry.first));
    PacketPutString(pkt.get(), entry.second);
  }

  // put null terminator
  PacketPutByte(pkt.get(), 0);

  // don't care if write finished or not, we are closing anyway
  responses.push_back(std::move(pkt));
}