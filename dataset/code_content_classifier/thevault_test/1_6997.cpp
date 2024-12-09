int 
EditorNetModel::addNode(float cx, float cy) {
	Node * node;

	// Find the next node id number
	if (node_id_count == 0 ) {
		for (node = nodes_; node != 0; node = node->next_) {
			if (node->num() > node_id_count) {
				node_id_count = node->num(); 
			}
		}
		node_id_count++;
	}
	 
	node = addNode(node_id_count);
	if (node) {
		node->place(cx,cy);
	}

	return (TCL_OK);
}