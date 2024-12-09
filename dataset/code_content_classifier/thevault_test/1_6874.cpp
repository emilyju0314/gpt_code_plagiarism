void LmsSender::send_dmcast (hdr_lms* lh, int seqno, int fid)
{
	Packet		*p = allocpkt();
	hdr_rtp		*rh = HDR_RTP(p);
	hdr_ip		*piph = HDR_IP(p);
	hdr_cmn		*ch = HDR_CMN(p);
	hdr_lms		*plh = HDR_LMS(p);

	dmcasts_sent_++;
	rh->seqno() = seqno;
	piph->daddr() = lh->tp_addr_;
	piph->dport() = lh->tp_port_;
	ch->size_= packetSize_;
	piph->flowid() = fid;		// Green for repair; to color packets in NAM

	plh->type_ = LMS_DMCAST;
	plh->from_ = addr();
//	plh->from_ = port();
	plh->src_ = addr();
	plh->group_ = daddr();
	plh->tp_addr_ = lh->tp_addr_;
	plh->tp_port_ = lh->tp_port_;
	plh->tp_iface_ = lh->tp_iface_;
        //const char* nname = packet_info.name(t);
	
	target_->recv(p);
}