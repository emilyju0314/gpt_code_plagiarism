int DCCPAckVector::sendAckVector(u_int32_t seqnum, u_int32_t acknum, DCCPOptions *options){
	if (acknum != seq_head_){
		fprintf(stdout, "DCCPAckVector::sendAckVector acknum %d != seq_head %d\n",acknum,seq_head_);
		fflush(stdout);
		abort();
	} else if (size_ == 0){
		fprintf(stdout, "DCCPAckVector::sendAckVector size_ == 0\n");
		fflush(stdout);
		abort();
	}
	u_char vect[size_];
	u_int16_t size;
	size = size_;
        int result = getAckVector(vect,&size);
	if (result > 0){
		//for now, assume that the ackvector can be contained in one option
		if (ene_ == 0)
			result = options->addOption(DCCP_OPT_ACK_VECTOR_N0, vect, size);
		else
			result = options->addOption(DCCP_OPT_ACK_VECTOR_N1, vect, size);
		if (result == DCCP_OPT_NO_ERR){
			addToAckHistory(seqnum);
		} else {
			fprintf(stderr, "DCCPAckVector::sendAckVector - Failed to add ack vector to option: err %d, size %d\n",result, size);
			fflush(stdout);
			abort();
		}

	} else {
		fprintf(stderr, "DCCPAckVector::sendAckVector - Get vector returned %d\n",result);
		fflush(stdout);
		abort();
	}
       
	return result;
}