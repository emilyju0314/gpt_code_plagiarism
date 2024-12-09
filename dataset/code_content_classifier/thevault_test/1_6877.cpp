Packet* DCCPAgent::newPacket(){
	Packet* pkt = allocpkt();
	hdr_dccp* dccph = hdr_dccp::access(pkt);
	hdr_dccpack* dccpah = hdr_dccpack::access(pkt);
	hdr_flags* flagsh = hdr_flags::access(pkt);

	//fill in seq number and (possibly) ack number
	dccph->seq_num_ = seq_num_;
	dccpah->ack_num_ = seq_num_recv_;

	dccph->options_ = NULL;
	dccph->ccval_ = 0;
	dccph->cscov_ = cscov_;
	
	if (use_ecn_local_){  //mark packet as ecn capable
		if (nonces_->uniform(-0.5,0.5) > 0){
			//set ect(1)
			flagsh->ect() = 0;
			flagsh->ce() = 1;
		} else {
			//set ect(0)
			flagsh->ect() = 1;
			flagsh->ce() = 0;
		}
	} else {
		flagsh->ect() = 0;
		flagsh->ce() = 0;
	}

	return pkt;
}