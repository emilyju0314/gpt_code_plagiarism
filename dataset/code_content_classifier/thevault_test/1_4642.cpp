void RocketServerConnection::notifyPendingShutdown() {
  if (state_ != ConnectionState::ALIVE) {
    return;
  }

  state_ = ConnectionState::DRAINING;
  sendError(StreamId{0}, RocketException(ErrorCode::CONNECTION_CLOSE));
  closeIfNeeded();
}