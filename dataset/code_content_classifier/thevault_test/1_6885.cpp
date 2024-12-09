void DCCPAgent::sendReset(dccp_reset_reason reason, u_int8_t data1,
	       u_int8_t data2, u_int8_t data3){
	Packet *pkt = newPacket();
	hdr_dccp *dccph = hdr_dccp::access(pkt);
	hdr_dccpack *dccpah = hdr_dccpack::access(pkt);
	hdr_dccpreset *dccpresh = hdr_dccpreset::access(pkt);
	hdr_cmn *cmnh = hdr_cmn::access(pkt);

	//fill in header info
	dccph->type_ = DCCP_RESET;
	cmnh->ptype() = PT_DCCP_RESET;
	dccpresh->rst_reason_ = reason;
	dccpresh->rst_data1_ = data1;
	dccpresh->rst_data2_ = data2;
	dccpresh->rst_data3_ = data3;
	cmnh->size() = headerSize(dccph->type_);
	dccph->data_offset_ = cmnh->size() / 4;
	assert(cmnh->size() % 4 != 0);
	dccph->options_ = new DCCPOptions(opt_size_);
	if (state_ != DCCP_STATE_CLOSED && state_ != DCCP_STATE_LISTEN){
		//we have valid sequence number
		ndp_ = (ndp_ + 1) % ndp_limit_;
		dccph->ndp_ = ndp_;
		seq_num_++;
	} else {
		dccph->ndp_ = 1;
		dccph->seq_num_ = 0;
	}
	dccpah->ack_num_ = seq_num_recv_;

	debug("%f, DCCP(%s)::sendReset() - Sent a RESET packet (Reason %s (%d), data (%d,%d,%d), seq: %d, ack: %d, size: %d, data_offset_ %d, ndp: %d)\n",
	      now(), name(), resetReasonAsStr(dccpresh->rst_reason_), dccpresh->rst_reason_, dccpresh->rst_data1_, dccpresh->rst_data2_, dccpresh->rst_data3_, dccph->seq_num_, dccpah->ack_num_, cmnh->size(), dccph->data_offset_,dccph->ndp_);
	send(pkt,0);
}