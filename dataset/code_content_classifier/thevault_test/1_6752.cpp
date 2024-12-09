int 
EditView::cmdgetObjProperty(float cx, float cy) { 
	Animation *p;
	Tcl& tcl = Tcl::instance();

	// matrix_ comes from class View (view.h)
	//  - imap is the inverse mapping
	//    (i.e from screen to world coordinate systems)
	matrix_.imap(cx, cy);

	// Finds the object which contains the coordinate (cx, cy)
	p = model_->inside(cx, cy);
	
	if (p == NULL) {
	   tcl.resultf("NONE");
	} else {
	   tcl.resultf("%s",p->property());
 	}
	return(TCL_OK);	
}