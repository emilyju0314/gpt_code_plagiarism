int DCCPAgent::findFeatureInList(u_int8_t num, dccp_feature_location location){
	int walker = 0;
	while (walker < feat_list_used_){ //walk through the list
		if (feat_list_num_[walker] == num && feat_list_loc_[walker] == location){
			//we have found the feature
			return walker;
		}
		walker++;
	}
	return -1;
}