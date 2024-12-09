int DCCPAgent::setFeature(u_int8_t num, dccp_feature_location location,
	       u_char* data, u_int8_t size, bool testSet){
	u_int16_t ui16;
	
	switch(num){
	case DCCP_FEAT_CC:
		if (size == 1){
			if (ccid_ == data[0])
				return DCCP_FEAT_OK;
			else
				return DCCP_FEAT_NOT_PREFERED;
		} else
			return DCCP_FEAT_ERR_SIZE;
		break;
	case DCCP_FEAT_ECN:
		if (size == 1){
			if (location == DCCP_FEAT_LOC_LOCAL){
				if (use_ecn_local_ && data[0] ||
				    !(use_ecn_local_ || data[0]))
					return DCCP_FEAT_OK;
				else
					return DCCP_FEAT_NOT_PREFERED;
			
			} else {
				if (use_ecn_remote_ && data[0] ||
				    !(use_ecn_remote_ || data[0]))
					return DCCP_FEAT_OK;
				else
					return DCCP_FEAT_NOT_PREFERED;
			}	
		} else
			return DCCP_FEAT_ERR_SIZE;
		break;
	case DCCP_FEAT_ACK_RATIO:
		if (size == 2){
			((u_char*) &ui16)[0] = data[0];
			((u_char*) &ui16)[1] = data[1];
			if (testSet){
				if (location == DCCP_FEAT_LOC_LOCAL){
					return ((ack_ratio_local_ != (u_int16_t) ui16) ? DCCP_FEAT_ERR_TEST : DCCP_FEAT_OK);
				} else {
					return ((ack_ratio_remote_ != (u_int16_t) ui16) ? DCCP_FEAT_ERR_TEST : DCCP_FEAT_OK);
				}
			} else {
				if (location == DCCP_FEAT_LOC_LOCAL){
					ack_ratio_local_ = (u_int16_t) ui16;
					
				} else
					ack_ratio_remote_ = (u_int16_t) ui16;
			}
			return DCCP_FEAT_OK;
		} else
			return DCCP_FEAT_ERR_SIZE;
		break;
	case DCCP_FEAT_ACKV:
		if (size == 1){
			if (location == DCCP_FEAT_LOC_LOCAL){
				if (use_ackv_local_ && data[0] ||
				    !(use_ackv_local_ || data[0]))
					return DCCP_FEAT_OK;
				else
					return DCCP_FEAT_NOT_PREFERED;
			
			} else {
				if (use_ackv_remote_ == data[0]||
				    !(use_ackv_remote_ || data[0]))
					return DCCP_FEAT_OK;
				else
					return DCCP_FEAT_NOT_PREFERED;
			}
		} else
			return DCCP_FEAT_ERR_SIZE;
		break;
	case DCCP_FEAT_Q_SCHEME:
		if (size == 1){
			if (q_scheme_ == data[0])
				return DCCP_FEAT_OK;
			else
				return DCCP_FEAT_NOT_PREFERED;
		} else
			return DCCP_FEAT_ERR_SIZE;
		break;
	case DCCP_FEAT_Q:
		if (size == 1){
			if (location == DCCP_FEAT_LOC_LOCAL){
				q_local_ = (data[0] > 0 ? 1 : 0);
			} else {
				q_remote_ = (data[0] > 0 ? 1 : 0);
			}
			return DCCP_FEAT_OK;
		} else
			return DCCP_FEAT_ERR_SIZE;
		break;
	default:
		return DCCP_FEAT_UNKNOWN;
	}
}