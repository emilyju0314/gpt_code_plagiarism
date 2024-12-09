void DCCPAgent::buildInitialFeatureList(){
	debug("%f, DCCP(%s)::buildInitialFeatureList() - values cc %d, ecnl %d, ecnr %d, ackrl %d, ackrr %d, ackvl %d, ackvr %d\n",
			      now(), name(), ccid_, use_ecn_local_,use_ecn_remote_, ack_ratio_local_,ack_ratio_remote_,use_ackv_local_,use_ackv_remote_);
	changeFeature(DCCP_FEAT_CC, DCCP_FEAT_LOC_LOCAL);
	changeFeature(DCCP_FEAT_CC, DCCP_FEAT_LOC_REMOTE);
	changeFeature(DCCP_FEAT_ECN, DCCP_FEAT_LOC_LOCAL);
	changeFeature(DCCP_FEAT_ECN, DCCP_FEAT_LOC_REMOTE);
	changeFeature(DCCP_FEAT_ACK_RATIO, DCCP_FEAT_LOC_LOCAL);
	changeFeature(DCCP_FEAT_ACK_RATIO, DCCP_FEAT_LOC_REMOTE);
	changeFeature(DCCP_FEAT_ACKV, DCCP_FEAT_LOC_LOCAL);
	changeFeature(DCCP_FEAT_ACKV, DCCP_FEAT_LOC_REMOTE);
	changeFeature(DCCP_FEAT_Q_SCHEME, DCCP_FEAT_LOC_LOCAL);
	changeFeature(DCCP_FEAT_Q_SCHEME, DCCP_FEAT_LOC_REMOTE);
	changeFeature(DCCP_FEAT_Q, DCCP_FEAT_LOC_LOCAL);
	changeFeature(DCCP_FEAT_Q, DCCP_FEAT_LOC_REMOTE);
}