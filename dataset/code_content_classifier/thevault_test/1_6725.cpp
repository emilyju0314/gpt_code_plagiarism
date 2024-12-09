void
Tag::addNodeMovementDestination(EditView * editview, 
                                double dx, double dy, double current_time) {
	Tcl_HashEntry * hash_entry;
	Tcl_HashSearch hash_search;
	Animation * animation_object;
	Node * node;
	float x,y;


	for (hash_entry = Tcl_FirstHashEntry(mbrHash_, &hash_search);
	     hash_entry != NULL;
	     hash_entry = Tcl_NextHashEntry(&hash_search)) {
		animation_object = (Animation *) Tcl_GetHashValue(hash_entry);

		if (animation_object->classid() == ClassNodeID) {
			node = (Node *) animation_object;
			x = node->x();
			y = node->y();

			editview->map(x,y);
			x += dx;
			y += dy;
			editview->imap(x,y);

			node->addMovementDestination(x, y, current_time);

		}
	}
}