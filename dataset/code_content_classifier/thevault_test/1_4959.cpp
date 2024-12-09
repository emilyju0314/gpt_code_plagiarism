TEST_P(HQUpstreamSessionTestH1qv2HQ, ExtraSettings) {
  auto handler = openTransaction();
  handler->txn_->sendHeaders(getGetRequest());
  handler->txn_->sendEOM();
  handler->expectError();
  handler->expectDetachTransaction();

  // Need to use a new codec. Since generating settings twice is
  // forbidden
  HQControlCodec auxControlCodec_{nextUnidirectionalStreamId_,
                                  TransportDirection::DOWNSTREAM,
                                  StreamDirection::EGRESS,
                                  egressSettings_,
                                  UnidirectionalStreamType::H1Q_CONTROL};
  folly::IOBufQueue writeBuf{folly::IOBufQueue::cacheChainLength()};
  auxControlCodec_.generateSettings(writeBuf);
  socketDriver_->addReadEvent(
      connControlStreamId_, writeBuf.move(), milliseconds(0));

  flushAndLoop();

  EXPECT_EQ(*socketDriver_->streams_[kConnectionStreamId].error,
            HTTP3::ErrorCode::HTTP_UNEXPECTED_FRAME);
}