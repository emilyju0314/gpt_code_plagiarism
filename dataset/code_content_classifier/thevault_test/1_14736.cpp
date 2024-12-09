rtp_error_t uvgrtp::rtcp::recv_packet_handler(void *arg, int flags, frame::rtp_frame **out)
{
    (void)flags;

    uvgrtp::frame::rtp_frame *frame = *out;
    uvgrtp::rtcp *rtcp              = (uvgrtp::rtcp *)arg;

    /* If this is the first packet from remote, move the participant from initial_participants_
     * to participants_, initialize its state and put it on probation until enough valid
     * packets from them have been received
     *
     * Otherwise update and monitor the received sequence numbers to determine whether something
     * has gone awry with the sender's sequence number calculations/delivery of packets */
    if (!rtcp->is_participant(frame->header.ssrc))
    {
        if ((rtcp->init_new_participant(frame)) != RTP_OK)
        {
            return RTP_GENERIC_ERROR;
        }
    } else if (rtcp->update_participant_seq(frame->header.ssrc, frame->header.seq) != RTP_OK) {
        return RTP_GENERIC_ERROR;
    }

    /* Finally update the jitter/transit/received/dropped bytes/pkts statistics */
    rtcp->update_session_statistics(frame);

    /* Even though RTCP collects information from the packet, this is not the packet's final destination.
     * Thus return RTP_PKT_NOT_HANDLED to indicate that the packet should be passed on to other handlers */
    return RTP_PKT_NOT_HANDLED;
}