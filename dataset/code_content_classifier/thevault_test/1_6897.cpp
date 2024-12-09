void DCCPAgent::advanceby(int delta){
	if (delta <= 0)
		return;
	
	if (!infinite_send_){
		
		switch (state_){
		case DCCP_STATE_CLOSED:
		case DCCP_STATE_RESPOND:
		case DCCP_STATE_REQUEST:
		case DCCP_STATE_OPEN:
			
			while (!sb_->full() && delta > 0){
				sb_->add(size_);
				delta--;
			}
			if (sb_->full()){
				fprintf(stdout,"%f, DCCP(%s)::advanceby() - Sendbuffer is full (%d packets dropped)\n",
					now(), name(), delta);
			}
			if (state_ == DCCP_STATE_CLOSED) {
				//initiate a connection
				buildInitialFeatureList();
				changeState(DCCP_STATE_REQUEST);
				output();
			} else if (state_ == DCCP_STATE_OPEN)
				output();
		case DCCP_STATE_LISTEN:
		case DCCP_STATE_CLOSEREQ:
		case DCCP_STATE_CLOSING:
			break;
		default:
			fprintf(stderr, "%f, DCCP(%s)::advanceby() - Illegal state (%d)!\n",
				now(), name(),state_);
			fflush(stdout);
			abort();
			
		}
	}
}