int RouteLogic::lookup_hier(char* asrc, char* adst, int& result) {
	int i;
	int src[SMALL_LEN], dst[SMALL_LEN];
	Tcl& tcl = Tcl::instance();

	if ( hroute_ == 0) {
		tcl.result("Required Hier_data not sent");
		return TCL_ERROR;
	}
      
	ns_strtok(asrc, src);
	ns_strtok(adst, dst);

	for (i=0; i < level_; i++)
		if (src[i] <= 0) {
			tcl.result("negative src node number");
			return TCL_ERROR;
		}
	if (dst[0] <= 0) {
		tcl.result("negative dst domain number");
		return TCL_ERROR;
	}

	int d = src[0];
	int index = INDEX(src[0], src[1], Cmax_);
	int size = cluster_size_[index];

	if (hsize_[index] == 0) {
		tcl.result("Routes not computed");
		return TCL_ERROR;
	}
	if ((src[0] < D_) || (dst[0] < D_)) {
		if((src[1] < C_[d]) || (dst[1] < C_[dst[0]]))
			if((src[2] <= size) ||
			   (dst[2]<=cluster_size_[INDEX(dst[0],dst[1],Cmax_)]))
			{
				;
			}
	} else { 
		tcl.result("node out of range");
		return TCL_ERROR;
	}
	int next_hop = 0;
	/* if node-domain lookup */
	if (((dst[1] <= 0) && (dst[2] <= 0)) ||
	    (src[0] != dst[0])){
		next_hop = hroute_[index][N_D_INDEX(src[2], dst[0], size, C_[d], D_)];
	}
	/* if node-cluster lookup */
	else if ((dst[2] <= 0) || (src[1] != dst[1])) {
		next_hop = hroute_[index][N_C_INDEX(src[2], dst[1], size, C_[d], D_)];
	}
	/* if node-node lookup */
	else {
		next_hop = hroute_[index][N_N_INDEX(src[2], dst[2], size, C_[d], D_)];	
	}
	
	char target[SMALL_LEN];
	if (next_hop > 0) {
		get_address(target, next_hop, index, d, size, src);
		tcl.result(target);
		result= Address::instance().str2addr(target);
	} else {
		tcl.result("-1");
		result = -1;
	}
	return TCL_OK;
}