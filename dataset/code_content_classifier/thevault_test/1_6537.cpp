WebTrafSession::~WebTrafSession() 
{
	if (donePage_ != curPage_) {
		fprintf(stderr, "done pages %d != all pages %d\n",
			donePage_, curPage_);
		abort();
	}
	if (status_ != TIMER_IDLE) {
		fprintf(stderr, "WebTrafSession must be idle when deleted.\n");
		abort();
	}

	// Recycle the objects of page level attributes if needed
	// Reuse these objects may save memory for large simulations--xuanc
	if (recycle_page_) {
		if (rvInterPage_ != NULL)
			Tcl::instance().evalf("delete %s", rvInterPage_->name());
		if (rvPageSize_ != NULL)
			Tcl::instance().evalf("delete %s", rvPageSize_->name());
		if (rvInterObj_ != NULL)
			Tcl::instance().evalf("delete %s", rvInterObj_->name());
		if (rvObjSize_ != NULL)
			Tcl::instance().evalf("delete %s", rvObjSize_->name());
	}
}