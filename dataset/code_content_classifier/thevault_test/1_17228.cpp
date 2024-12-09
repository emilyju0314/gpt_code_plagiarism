void PacketManager::SendEmptyQueryResponse() {
  std::unique_ptr<OutputPacket> response(new OutputPacket());
  response->msg_type = NetworkMessageType::EMPTY_QUERY_RESPONSE;
  responses.push_back(std::move(response));
}