dccp_ecn_codepoint DCCPAgent::getECNCodePoint(Packet* pkt){
	hdr_flags* flagsh = hdr_flags::access(pkt);
	if (flagsh->ect() == 1 && flagsh->ce() == 1)
		return ECN_CE;
	else if (flagsh->ect() == 0 && flagsh->ce() == 1)
		return ECN_ECT1;
	else if (flagsh->ect() == 1 && flagsh->ce() == 0)
		return ECN_ECT0;
	else
		return ECN_NOT_ECT;
}