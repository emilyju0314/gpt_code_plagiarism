void DCCPAgent::addFeatureOptions(){
	int result;
	u_int8_t type;
	u_char* data = new u_char[DCCP_OPT_MAX_LENGTH];
	int i;
	
	for(i = 0; i < feat_list_used_; i++){
		if (!packet_recv_ || feat_list_first_[i] || feat_list_seq_num_[i] <= ack_num_recv_){
			//this is the first time, or last change for this
			//feature should have been confirmed by now 

			if (feat_list_loc_[i] == DCCP_FEAT_LOC_LOCAL)
				type = DCCP_OPT_CHANGEL;
			else
				type = DCCP_OPT_CHANGER;

			result	= getFeature(feat_list_num_[i], feat_list_loc_[i], data, DCCP_OPT_MAX_LENGTH);
			if (result > 0){
				feat_list_seq_num_[i] = seq_num_;
				debug("%f, DCCP(%s)::addFeatureOptions() - Adding option type %d for feat %d, location %s, seq %d\n",
				      now(), name(), type, feat_list_num_[i], featureLocationAsStr(feat_list_loc_[i]),feat_list_seq_num_[i]);
				opt_->addFeatureOption(type,feat_list_num_[i], data, result);
				feat_list_first_[i] = false;
			} else
				debug("%f, DCCP(%s)::addFeatureOptions() - getFeature() failed for feature %d, location %s. Error: %d \n",
					now(), name(), feat_list_num_[i], featureLocationAsStr(feat_list_loc_[i]),result);
			
		} else
			debug("%f, DCCP(%s)::addFeatureOptions() - Old change still pending for feat %d, location %s (seq_sent: %d ack_recv: %d)\n",
				      now(), name(), feat_list_num_[i], featureLocationAsStr(feat_list_loc_[i]),feat_list_seq_num_[i],ack_num_recv_);
	}
		
	for(i = 0; i < feat_conf_used_; i++){
		if (feat_conf_loc_[i] == DCCP_FEAT_LOC_LOCAL)
			type = DCCP_OPT_CONFIRML;
		else
			type = DCCP_OPT_CONFIRMR;
		
		result	= getFeature(feat_conf_num_[i], feat_conf_loc_[i], data, DCCP_OPT_MAX_LENGTH);
		if (result > 0){
			debug("%f, DCCP(%s)::addFeatureOptions() - Adding option type %d for feat %d, location %s\n", now(), name(), type, feat_conf_num_[i], featureLocationAsStr(feat_conf_loc_[i]));
			opt_->addFeatureOption(type,feat_conf_num_[i], data, result);
		} else
		    debug("%f, DCCP(%s)::addFeatureOptions() - getFeature() failed for feature %d, location %s. Error: %d \n", now(), name(), feat_conf_num_[i], featureLocationAsStr(feat_conf_loc_[i]),result); 
	}
	feat_conf_used_ = 0;
	delete [] data;
}