int RouteLogic::lookup_flat(char* asrc, char* adst, int& result) {
	Tcl& tcl = Tcl::instance();
	int src = atoi(asrc) + 1;
	int dst = atoi(adst) + 1;

	if (route_ == 0) {
		// routes are computed only after the simulator is running
		// ($ns run).
		tcl.result("routes not yet computed");
		return (TCL_ERROR);
	}
	if (src >= size_ || dst >= size_) {
		tcl.result("node out of range");
		return (TCL_ERROR);
	}
	result = route_[INDEX(src, dst, size_)].next_hop - 1;
	return TCL_OK;
}