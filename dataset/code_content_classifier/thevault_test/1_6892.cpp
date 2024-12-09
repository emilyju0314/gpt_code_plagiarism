dccp_feature_type DCCPAgent::getFeatureType(u_int8_t num){
	switch(num){
	case DCCP_FEAT_CC:
	case DCCP_FEAT_ECN:
	case DCCP_FEAT_ACKV:
	case DCCP_FEAT_Q_SCHEME:
		return DCCP_FEAT_TYPE_SP;
		break;
	case DCCP_FEAT_ACK_RATIO:
	case DCCP_FEAT_Q:
		return DCCP_FEAT_TYPE_NN;
	default:
		return DCCP_FEAT_TYPE_UNKNOWN;
	}
}