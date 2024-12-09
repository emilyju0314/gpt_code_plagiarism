bool DCCPAgent::parseOptions(Packet *pkt){
	int result = 0;
	u_int8_t *type = new u_int8_t;
	u_char *data = new u_char[DCCP_OPT_MAX_LENGTH];
	hdr_dccp *dccph = hdr_dccp::access(pkt);
	DCCPOptions* options = dccph->options_;

	if(options == NULL){
		delete type;
		delete [] data;
		return false;
	}
	
	feat_first_in_pkt_ = true;

	options->startOptionWalk();
	result = options->nextOption(type, data, DCCP_OPT_MAX_LENGTH);

	while (result >= 0){  //walk through and process opt until done or fail
		if(!processOption(*type, data, result, pkt)){
			delete type;
			delete [] data;
			return false;
		}
			
		result = options->nextOption(type, data, DCCP_OPT_MAX_LENGTH);	
	}
	
	delete type;
	delete [] data;
	return true;
}