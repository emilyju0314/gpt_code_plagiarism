void AutoNetModel::scale_estimate()
{
	/* Determine the maximum link delay. */
	double emax = 0., emean = 0., dist;
	Node *n;
	int edges=0;
	for (n = nodes_; n != 0; n = n->next_) {
		for (Edge* e = n->links(); e != 0; e = e->next_) {
		        edges++;
			dist = n->distance(*(e->neighbor()));
			emean+=dist;
			if (dist > emax)
				emax = dist;
		}
	}
	emean/=edges;
	
	/*store this because we need it for monitors*/
	node_size_ = node_sizefac_ * emean;
	/*
	 * Check for missing node or edge sizes. If any are found,
	 * compute a reasonable default based on the maximum edge
	 * dimension.
	 */
	for (n = nodes_; n != 0; n = n->next_) {
		n->size(node_size_);
		for (Edge* e = n->links(); e != 0; e = e->next_)
			e->size(.03 * emean);
	}
}