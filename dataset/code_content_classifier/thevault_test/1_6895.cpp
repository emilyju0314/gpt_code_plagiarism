void DCCPAgent::listen(){
	if (state_ == DCCP_STATE_CLOSED){
		server_ = true;
		changeState(DCCP_STATE_LISTEN);
	} else
		debug("%f, DCCP(%s)::listen() - Listen called while in state %s (%d)\n",
		      now(), name(), stateAsStr(state_),state_);
		
}