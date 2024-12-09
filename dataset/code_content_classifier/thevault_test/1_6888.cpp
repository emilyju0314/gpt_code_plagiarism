bool DCCPAgent::featureIsChanging(u_int8_t num, dccp_feature_location location){
	for (int i = 0; i< feat_list_used_; i++)
		if(feat_list_num_[i] == num && feat_list_loc_[i] == location)
			return true;
	return false;
}