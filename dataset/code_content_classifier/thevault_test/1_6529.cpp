void LmsReceiver::send_refresh ()
{
	Packet* p = allocpkt (sizeof (struct lms_ctl));
	struct lms_ctl	*ctl = (struct lms_ctl*)p->accessdata ();

	hdr_ip* iph = HDR_IP(p);
	hdr_cmn *ch = HDR_CMN(p);  

	ch->size_ = sizeof(struct lms_ctl) + sizeof(hdr_lms); 
	iph->daddr() = upstream_lms_;
	iph->flowid() = 7;		// mark refresh packets black for nam
#ifdef LMS_DEBUG
printf("%s send refresh packet, size is %d\n\n",
  uname_, (HDR_CMN(p))->size_);
#endif
	hdr_lms* lh = HDR_LMS(p);
	lh->type_   = LMS_REFRESH;
	lh->from_   = addr();
	lh->src_    = lms_src_;
	lh->group_  = lms_group_;

	ctl->cost_ = lms_cost_;
	ctl->hop_cnt_ = 0;
        ctl->downstream_lms_.addr_ = addr();
        ctl->downstream_lms_.port_ = port();
        
	target_->recv(p);
}