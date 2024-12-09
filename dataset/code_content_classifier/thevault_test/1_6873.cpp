void LmsSender::send_lms_pkt (int type, int cost)
{
	Packet* p = allocpkt();

	(HDR_CMN(p))->ptype_ = PT_LMS;
	(HDR_IP(p))->flowid() = 7; //Coloring in NAM

	if (type != LMS_SETUP)
		(HDR_CMN(p))->size_ = lmsPacketSize_; 
		//(HDR_CMN(p))->size_ = sizeof(hdr_lms); 
	else 
		(HDR_CMN(p))->size_ = packetSize_; 
		//(HDR_CMN(p))->size_ = sizeof(hdr_lms); 

	hdr_lms* lh = HDR_LMS(p);
	lh->type_ = type;
	lh->cost_ = cost;
	lh->from_ = addr();
//	lh->from_ = port();
	lh->src_ = addr();
	lh->group_ = daddr();
	lh->tp_addr_  = LMS_NOADDR;
	lh->tp_port_ = -1;
	lh->tp_iface_ = LMS_NOIFACE;
	lh->lo_ = lh->hi_ = -1;
	lh->ts_ = Scheduler::instance().clock();

#ifdef LMS_DEBUG
printf ("SNDR: %s send_lms_pkt from %d src %d dst %x type %d cost %d size %d at %f\n\n",
  uname_, lh->from_, lh->src_, lh->group_, lh->type_, lh->cost_,
  (HDR_CMN(p))->size_, lh->ts_);
#endif 
	target_->recv(p);
}