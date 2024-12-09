int DCCPAgent::getFeature(u_int8_t num, dccp_feature_location location,
	       u_char* data, u_int8_t maxSize){
	u_int16_t ui16;
	
	switch(num){
	case DCCP_FEAT_CC:
		if (maxSize > 0){
			data[0] = (u_int8_t) ccid_;
			return 1;
		} else
			return DCCP_FEAT_ERR_SIZE;
		break;
	case DCCP_FEAT_ECN:
		if (maxSize > 0){
			if (location == DCCP_FEAT_LOC_LOCAL)
				data[0] = (u_int8_t) use_ecn_local_;
			else
				data[0] = (u_int8_t) use_ecn_remote_;
				
			return 1;
		} else
			return DCCP_FEAT_ERR_SIZE;
		break;
	case DCCP_FEAT_ACK_RATIO:
		if (maxSize > 1){
			if (location == DCCP_FEAT_LOC_LOCAL)
				ui16 = (u_int16_t) ack_ratio_local_;
			else
				ui16 = (u_int16_t) ack_ratio_remote_;
			data[0] = ((u_char*) &ui16)[0];
			data[1] = ((u_char*) &ui16)[1];
			
			return 2;
		} else
			return DCCP_FEAT_ERR_SIZE;
		break;
	case DCCP_FEAT_ACKV:
		if (maxSize > 0){
			if (location == DCCP_FEAT_LOC_LOCAL)
				data[0] = (u_int8_t) use_ackv_local_;
			else
				data[0] = (u_int8_t) use_ackv_remote_;
				
			return 1;
		} else
			return DCCP_FEAT_ERR_SIZE;
		break;
	case DCCP_FEAT_Q_SCHEME:
		if (maxSize > 0){
			data[0] = (u_int8_t) q_scheme_;
			return 1;
		} else
			return DCCP_FEAT_ERR_SIZE;
		break;
	case DCCP_FEAT_Q:
		if (maxSize > 0){
			if (location == DCCP_FEAT_LOC_LOCAL)
				data[0] = (u_int8_t) q_local_;
			else
				data[0] = (u_int8_t) q_remote_;
				
			return 1;
		} else
			return DCCP_FEAT_ERR_SIZE;
		break;
	default:
		return DCCP_FEAT_UNKNOWN;
	}
}