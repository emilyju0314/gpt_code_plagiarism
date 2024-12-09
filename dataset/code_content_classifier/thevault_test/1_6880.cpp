bool DCCPAgent::finishFeatureNegotiation(u_int8_t num, dccp_feature_location location){
	int walker = 0;
	while (walker < feat_list_used_){ //walk through the list
		if (feat_list_num_[walker] == num && feat_list_loc_[walker] == location){
			//we found the feature
			//move the rest of the list one step up
			if (walker + 1 < feat_list_used_){
				for(int i = walker; i < feat_list_used_-1; i++){
					feat_list_num_[i] = feat_list_num_[i+1];
					feat_list_loc_[i] = feat_list_loc_[i+1];
				}
			}
			feat_list_used_--;
			return true;
				
		}
		walker++;
	}
	return false;
}