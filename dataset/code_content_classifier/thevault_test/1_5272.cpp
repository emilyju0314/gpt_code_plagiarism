bool ts::IPOutputPlugin::sendDatagram(const TSPacket* pkt, size_t packet_count)
{
    bool status = true;

    if (_use_rtp) {
        // RTP datagram are relatively trivial to build, except the time stamp.
        // We cannot use the wall clock time because the plugin is likely to burst its output.
        // So, we try to synchronize RTP timestamps with PCR's from one PID.
        // But this is not trivial since the PCR may not be accurate or may loop back.
        // As long as the first PCR is not seen, increment timestamps from zero, using TS bitrate as reference.
        // At the first PCR, compute the difference between the current RTP timestamp and this PCR.
        // Then keep this difference and resynchronize at each PCR.
        // But never jump back in RTP timestamps, only increase "more slowly" when adjusting.

        // Build an RTP datagram. Use a simple RTP header without options nor extensions.
        ByteBlock buffer(RTP_HEADER_SIZE + packet_count * PKT_SIZE);

        // Build the RTP header, except the timestamp.
        buffer[0] = 0x80;             // Version = 2, P = 0, X = 0, CC = 0
        buffer[1] = _rtp_pt & 0x7F;   // M = 0, payload type
        PutUInt16(&buffer[2], _rtp_sequence++);
        PutUInt32(&buffer[8], _rtp_ssrc);

        // Get current bitrate to compute timestamps.
        const BitRate bitrate = tsp->bitrate();

        // Look for a PCR in one of the packets to send.
        // If found, we adjust this PCR for the first packet in the datagram.
        uint64_t pcr = INVALID_PCR;
        for (size_t i = 0; i < packet_count; i++) {
            const bool hasPCR = pkt[i].hasPCR();
            const PID pid = pkt[i].getPID();

            // Detect PCR PID if not yet known.
            if (hasPCR && _pcr_pid == PID_NULL) {
                _pcr_pid = pid;
            }

            // Detect PCR presence.
            if (hasPCR && pid == _pcr_pid) {
                pcr = pkt[i].getPCR();
                // If the bitrate is known and the packet containing the PCR is not the first one,
                // compute the theoretical timestamp of the first packet in the datagram.
                if (i > 0 && bitrate > 0) {
                    pcr -= (i * 8 * PKT_SIZE * uint64_t(SYSTEM_CLOCK_FREQ)) / bitrate;
                }
                break;
            }
        }

        // Extrapolate the RTP timestamp from the previous one, using current bitrate.
        // This value may be replaced if a valid PCR is present in this datagram.
        uint64_t rtp_pcr = _last_rtp_pcr;
        if (bitrate > 0) {
            rtp_pcr += ((_pkt_count - _last_rtp_pcr_pkt) * 8 * PKT_SIZE * uint64_t(SYSTEM_CLOCK_FREQ)) / bitrate;
        }

        // If the current datagram contains a PCR, recompute the RTP timestamp more precisely.
        if (pcr != INVALID_PCR) {
            if (_last_pcr == INVALID_PCR || pcr < _last_pcr) {
                // This is the first PCR in the stream or the PCR has jumped back in the past.
                // For this time only, we keep the extrapolated PCR.
                // Compute the difference between PCR and RTP timestamps.
                _rtp_pcr_offset = pcr - rtp_pcr;
                tsp->verbose(u"RTP timestamps resynchronized with PCR PID 0x%X (%d)", {_pcr_pid, _pcr_pid});
                tsp->debug(u"new PCR-RTP offset: %d", {_rtp_pcr_offset});
            }
            else {
                // PCR are normally increasing, drop extrapolated value, resynchronize with PCR.
                uint64_t adjusted_rtp_pcr = pcr - _rtp_pcr_offset;
                if (adjusted_rtp_pcr <= _last_rtp_pcr) {
                    // The adjustment would make the RTP timestamp go backward. We do not want that.
                    // We increase the RTP timestamp "more slowly", by 25% of the extrapolated value.
                    tsp->debug(u"RTP adjustment from PCR would step backward by %d", {((_last_rtp_pcr - adjusted_rtp_pcr) * RTP_RATE_MP2T) / SYSTEM_CLOCK_FREQ});
                    adjusted_rtp_pcr = _last_rtp_pcr + (rtp_pcr - _last_rtp_pcr) / 4;
                }
                rtp_pcr = adjusted_rtp_pcr;
            }

            // Keep last PCR value.
            _last_pcr = pcr;
        }

        // Insert the RTP timestamp in RTP clock units.
        PutUInt32(&buffer[4], uint32_t((rtp_pcr * RTP_RATE_MP2T) / SYSTEM_CLOCK_FREQ));

        // Remember position and value of last datagram.
        _last_rtp_pcr = rtp_pcr;
        _last_rtp_pcr_pkt = _pkt_count;

        // Copy the TS packets after the RTP header and send the packets.
        ::memcpy(buffer.data() + RTP_HEADER_SIZE, pkt, packet_count * PKT_SIZE);
        status = _sock.send(buffer.data(), buffer.size(), *tsp);
    }
    else {
        // No RTP, send TS packets directly as datagram.
        status = _sock.send(pkt, packet_count * PKT_SIZE, *tsp);
    }

    // Count packets datagram per datagram.
    _pkt_count += packet_count;

    return status;
}