void DCCPAgent::timeout(int tno){
	debug("%f, DCCP(%s)::timeout() - Timeout %d occured!\n",
		      now(), name(), tno);
	switch (tno){
	case DCCP_TIMER_RTX:
		switch(state_){
		case DCCP_STATE_RESPOND:
			sendReset(DCCP_RST_CLOSED,0,0,0);
			reset();
			break;
		case DCCP_STATE_REQUEST:
			if (timer_rtx_->backOffFailed()){
				sendReset(DCCP_RST_CLOSED,0,0,0);
				reset(); 
			} else
				output();
			break;
		case DCCP_STATE_CLOSING:
			if (timer_rtx_->backOffFailed()){
				reset();
			} else
				output();
			break;
		case DCCP_STATE_CLOSEREQ:
			if (timer_rtx_->backOffFailed()){
				sendReset(DCCP_RST_CLOSED,0,0,0);
				reset();
			} else
				output();
			break;
		default:
			fprintf(stderr,"%f, DCCP(%s)::timeout() - Timer (%d) should not be running in state %s!\n",
		      now(), name(), tno,stateAsStr(state_));
			fflush(stdout);
			abort();
		}
		break;
	case DCCP_TIMER_SND:
		switch(state_){
		case DCCP_STATE_OPEN:
			output();
			break;
		default:
			fprintf(stderr,"%f, DCCP(%s)::timeout() - Timer (%d) should not be running in state %s!\n",
				now(), name(), tno,stateAsStr(state_));
			fflush(stdout);
			abort();
		}
		break;
	default:
		fprintf(stdout,"%f, DCCP(%s)::timeout() - Unknown timeout occured (%d)!\n",
		      now(), name(), tno);
	}
}