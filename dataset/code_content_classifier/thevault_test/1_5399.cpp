ts::ProcessorPlugin::Status ts::MergePlugin::processMergePacket(TSPacket& pkt, TSPacketMetadata& pkt_data)
{
    BitRate merge_bitrate = 0;

    // Replace current null packet in main stream with next packet from merged stream.
    if (!_queue.getPacket(pkt, merge_bitrate)) {
        // No packet available, keep original null packet.
        if (!_got_eof && _queue.eof()) {
            // Report end of input stream once.
            _got_eof = true;
            tsp->verbose(u"end of merged stream");
            // If processing terminated, either exit or transparently pass packets
            if (tsp->useJointTermination()) {
                tsp->jointTerminate();
                return TSP_OK;
            }
            else if (_terminate) {
                return TSP_END;
            }
        }
        return TSP_OK;
    }

    // Merge PSI/SI.
    if (_merge_psi) {
        _psi_merger.feedMergedPacket(pkt);
    }

    // Drop selected PID's from merged stream. Replace them with a null packet.
    const PID pid = pkt.getPID();
    if (!_allowed_pids.test(pid)) {
        return TSP_NULL;
    }

    // Check PID conflicts.
    if (!_ignore_conflicts) {
        if (pid != PID_NULL && !_merge_pids.test(pid)) {
            // First time we see that PID on the merged stream.
            _merge_pids.set(pid);
            if (_main_pids.test(pid)){
                tsp->error(u"PID conflict: PID 0x%X (%d) exists in the two streams, dropping from merged stream", {pid, pid});
            }
        }
        if (pid != PID_NULL && _main_pids.test(pid)) {
            // The same PID already exists in the main PID, drop from merged stream.
            // Error message already reported.
            return TSP_NULL;
        }
    }

    // Adjust PCR's in packets from the merge streams.
    if (_pcr_restamp && pkt.hasPCR()) {

        // In each PID with PCR's in the merge stream, we keep the first PCR
        // value unchanged. Then, we need to adjust all subsequent PCR's.
        // PCR's are system clock values. They must be synchronized with the
        // transport stream rate. So, the difference between two PCR's shall
        // be the transmission time in PCR units.
        //
        // We can compute new precise PCR values when the bitrate is fixed.
        // However, with a variable bitrate, our computed values will be inaccurate.
        //
        // Also note that we do not modify DTS and PTS. First, we can't access
        // PTS and DTS in scrambled streams (unlike PCR's). Second, we MUST NOT
        // change them because they indicate at which time the frame shall be
        // _processed_, not _transmitted_.

        const uint64_t pcr = pkt.getPCR();
        const BitRate main_bitrate = tsp->bitrate();

        // Check if we know this PID.
        PIDContextMap::iterator ctx(_pcr_pids.find(pid));
        if (ctx == _pcr_pids.end()) {
            // First time we see a PCR in this PID, create the context.
            // Save the initial PCR value bu do not modify it.
            _pcr_pids.insert(std::make_pair(pid, PIDContext(pcr, _pkt_count)));
        }
        else if (main_bitrate > 0) {
            // We have seen PCR's in this PID.
            // Compute the transmission time since last PCR in PCR units.
            // We base the result on the main stream bitrate and the number of packets.
            assert(_pkt_count > ctx->second.pcr_pkt);
            ctx->second.last_pcr += ((_pkt_count - ctx->second.pcr_pkt) * 8 * PKT_SIZE * SYSTEM_CLOCK_FREQ) / uint64_t(main_bitrate);
            ctx->second.pcr_pkt = _pkt_count;
            // Update the PCR in the packet.
            pkt.setPCR(ctx->second.last_pcr);
            // In debug mode, report the displacement of the PCR.
            // This may go back and forth around zero but should never diverge.
            const SubSecond moved = ctx->second.last_pcr - pcr;
            tsp->debug(u"adjusted PCR by %'d (%'d ms) in PID 0x%X (%d)", {moved, (moved * MilliSecPerSec) / SYSTEM_CLOCK_FREQ, pid, pid});
        }
    }

    // Apply labels on muxed packets.
    pkt_data.setLabels(_setLabels);
    pkt_data.clearLabels(_resetLabels);

    return TSP_OK;
}