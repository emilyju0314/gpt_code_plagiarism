bool PacketManager::ProcessPacket(InputPacket *pkt, const size_t thread_id) {
  LOG_TRACE("Message type: %c", static_cast<unsigned char>(pkt->msg_type));
  // We don't set force_flush to true for `PBDE` messages because they're
  // part of the extended protocol. Buffer responses and don't flush until
  // we see a SYNC
  switch (pkt->msg_type) {
    case NetworkMessageType::SIMPLE_QUERY_COMMAND: {
      LOG_TRACE("SIMPLE_QUERY_COMMAND");
      ExecQueryMessage(pkt, thread_id);
      force_flush = true;
    } break;
    case NetworkMessageType::PARSE_COMMAND: {
      LOG_TRACE("PARSE_COMMAND");
      ExecParseMessage(pkt);
    } break;
    case NetworkMessageType::BIND_COMMAND: {
      LOG_TRACE("BIND_COMMAND");
      ExecBindMessage(pkt);
    } break;
    case NetworkMessageType::DESCRIBE_COMMAND: {
      LOG_TRACE("DESCRIBE_COMMAND");
      return ExecDescribeMessage(pkt);
    } break;
    case NetworkMessageType::EXECUTE_COMMAND: {
      LOG_TRACE("EXECUTE_COMMAND");
      ExecExecuteMessage(pkt, thread_id);
    } break;
    case NetworkMessageType::SYNC_COMMAND: {
      LOG_TRACE("SYNC_COMMAND");
      SendReadyForQuery(txn_state_);
      force_flush = true;
    } break;
    case NetworkMessageType::CLOSE_COMMAND: {
      LOG_TRACE("CLOSE_COMMAND");
      ExecCloseMessage(pkt);
    } break;
    case NetworkMessageType::TERMINATE_COMMAND: {
      LOG_TRACE("TERMINATE_COMMAND");
      force_flush = true;
      return false;
    } break;
    case NetworkMessageType::NULL_COMMAND: {
      LOG_TRACE("NULL");
      force_flush = true;
      return false;
    } break;
    default: {
      LOG_ERROR("Packet type not supported yet: %d (%c)",
                static_cast<int>(pkt->msg_type),
                static_cast<unsigned char>(pkt->msg_type));
    }
  }
  return true;
}