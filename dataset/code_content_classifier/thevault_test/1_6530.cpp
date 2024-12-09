void LmsReceiver::send_dmcast (hdr_lms* lh, int seqno, int fid)
{
	Packet	*p = allocpkt();
	hdr_cmn *ch = HDR_CMN(p);
	hdr_rtp	*rh = HDR_RTP(p);
	hdr_ip	*piph = HDR_IP(p);
#ifdef LMS_DEBUG
printf ("%s Sending DMCAST %d to %d:%d, size is %d\n",
  uname_, seqno, lh->tp_addr_>>8, lh->tp_addr_&0xff, ch->size_);
#endif

	hdr_lms *plh = HDR_LMS(p);
	ch->ptype_ = PT_CBR;
	ch->size() = dataSize_; 

	rh->seqno() = seqno;

	piph->daddr() = lh->tp_addr_;
	piph->dport() = lh->tp_port_;
	piph->flowid() = fid;		// to color packets in NAM

	plh->type_ = LMS_DMCAST;
	plh->from_ = addr();
	plh->src_ = lms_src_;
	plh->group_ = lms_group_;
	plh->tp_addr_ = lh->tp_addr_;
	plh->tp_port_ = lh->tp_port_;
	plh->tp_iface_ = lh->tp_iface_;

	target_->recv(p);
}