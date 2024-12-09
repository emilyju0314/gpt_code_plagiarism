void DCCPAgent::confirmFeature(u_int8_t num, dccp_feature_location location){
	int walker = 0;
	while (walker < feat_conf_used_){ //walk through the list
		if (feat_conf_num_[walker] == num && feat_conf_loc_[walker] == location){
			//we have found the feature
			break;
		}
		walker++;
	}

	if (walker == feat_conf_used_ && feat_conf_used_ < feat_size_){
		//add to the end of list
		feat_conf_num_[walker] = num;
		feat_conf_loc_[walker] = location;
		feat_conf_used_++;
	}
}