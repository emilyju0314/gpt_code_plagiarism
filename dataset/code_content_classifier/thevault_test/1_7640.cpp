SchedulingResult D6DProbeScheduler::scheduleFramesForPacket(
    PacketBuilderInterface&& builder,
    uint32_t /* writableBytes */) {
  builder.encodePacketHeader();
  int res = writeFrame(PingFrame(), builder);
  CHECK_GT(res, 0) << __func__ << " "
                   << "failed to write ping frame"
                   << "remainingBytes: " << builder.remainingSpaceInPkt();
  CHECK(builder.canBuildPacket()) << __func__ << " "
                                  << "inner builder cannot build packet";

  auto pingOnlyPacket = std::move(builder).buildPacket();

  std::unique_ptr<WrapperPacketBuilderInterface> sizeEnforcedBuilder;
  if (conn_.transportSettings.dataPathType == DataPathType::ChainedMemory) {
    sizeEnforcedBuilder = std::make_unique<RegularSizeEnforcedPacketBuilder>(
        std::move(pingOnlyPacket), probeSize_, cipherOverhead_);
  } else {
    CHECK(conn_.bufAccessor && conn_.bufAccessor->ownsBuffer());
    sizeEnforcedBuilder = std::make_unique<InplaceSizeEnforcedPacketBuilder>(
        *conn_.bufAccessor,
        std::move(pingOnlyPacket),
        probeSize_,
        cipherOverhead_);
  }
  CHECK(sizeEnforcedBuilder->canBuildPacket())
      << __func__ << " "
      << "sizeEnforcedBuilder cannot build packet";

  auto resultPacket = std::move(*sizeEnforcedBuilder).buildPacket();

  auto resultPacketSize = resultPacket.header->computeChainDataLength() +
      resultPacket.body->computeChainDataLength() + cipherOverhead_;
  CHECK_EQ(resultPacketSize, probeSize_)
      << __func__ << " "
      << "result packet does not have enforced size,"
      << " expecting: " << probeSize_ << " getting: " << resultPacketSize;

  VLOG_IF(4, conn_.d6d.lastProbe.has_value())
      << __func__ << " "
      << "invalidating old non-acked d6d probe,"
      << " seq: " << conn_.d6d.lastProbe->packetNum
      << " packet size: " << conn_.d6d.lastProbe->packetSize;

  conn_.d6d.lastProbe = D6DProbePacket(
      resultPacket.packet.header.getPacketSequenceNum(), probeSize_);

  probeSent_ = true;
  return SchedulingResult(folly::none, std::move(resultPacket));
}