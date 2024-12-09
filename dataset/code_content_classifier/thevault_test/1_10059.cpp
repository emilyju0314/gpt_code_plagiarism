void ConferenceTransport::SendPacket(const Packet& packet) {
  int destination = -1;

  switch (packet.type_) {
    case Packet::Rtp: {
      webrtc::RTPHeader rtp_header;
      rtp_header_parser_->Parse(packet.data_, packet.len_, &rtp_header);
      if (rtp_header.ssrc == kLocalSsrc) {
        remote_network_->ReceivedRTPPacket(reflector_, packet.data_,
                                           packet.len_, webrtc::PacketTime());
      } else {
        if (loudest_filter_.ForwardThisPacket(rtp_header)) {
          destination = GetReceiverChannelForSsrc(rtp_header.ssrc);
          if (destination != -1) {
            local_network_->ReceivedRTPPacket(destination, packet.data_,
                                              packet.len_,
                                              webrtc::PacketTime());
          }
        }
      }
      break;
    }
    case Packet::Rtcp: {
      unsigned int sender_ssrc = ParseRtcpSsrc(packet.data_, packet.len_);
      if (sender_ssrc == kLocalSsrc) {
        remote_network_->ReceivedRTCPPacket(reflector_, packet.data_,
                                            packet.len_);
      } else if (sender_ssrc == kReflectorSsrc) {
        local_network_->ReceivedRTCPPacket(local_sender_, packet.data_,
                                           packet.len_);
      } else {
        destination = GetReceiverChannelForSsrc(sender_ssrc);
        if (destination != -1) {
          local_network_->ReceivedRTCPPacket(destination, packet.data_,
                                             packet.len_);
        }
      }
      break;
    }
  }
}