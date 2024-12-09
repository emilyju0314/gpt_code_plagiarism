int DCCPAgent::headerSize(dccp_packet_type type){
	if (type < DCCP_NUM_PTYPES && type >= 0)
		return hdr_size_[type];
	else
		return 0;
}