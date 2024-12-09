bool DCCPAgent::changeFeature(u_int8_t num, dccp_feature_location location){
	if (allow_mult_neg_ > 0){
		int pos = findFeatureInList(num,location);

		if (pos >= 0){
			feat_list_seq_num_[pos] = seq_num_;
			feat_list_first_[pos] = true;
			return true;
		}
		//does not exist, check if full
		if (feat_list_used_ == feat_size_)
			return false;		
	} else {
		//check if the list is full, or if this feature is already in neg
		if (feat_list_used_ == feat_size_ || featureIsChanging(num, location))
			return false;
	}

	feat_list_num_[feat_list_used_] = num;
	feat_list_loc_[feat_list_used_] = location;
	feat_list_seq_num_[feat_list_used_] = 0;
	feat_list_first_[feat_list_used_] = true;
	debug("%f, DCCP(%s)::changeFeature() - Added feature %d, location %s\n",
	      now(), name(), num, featureLocationAsStr(location));
	feat_list_used_++;
	return true;
}