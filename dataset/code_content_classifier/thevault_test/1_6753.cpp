int 
EditView::cmdgetObjectProperties(float cx, float cy, const char * type) { 
	Animation * animation_object;
	Tcl& tcl = Tcl::instance();

	// matrix_ comes from class View (view)
	//  - imap is the inverse mapping
	//    (i.e from screen to world coordinate systems)
	matrix_.imap(cx, cy);

	// Finds the object which contains the coordinate (cx, cy)
	animation_object = model_->inside(cx, cy);
	
	if (animation_object == NULL) {
	   tcl.resultf("NONE");
	} else {
	   tcl.resultf("%s",animation_object->getProperties(type));
	}
	return(TCL_OK);	
}