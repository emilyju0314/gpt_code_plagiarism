void detail::edge::messageFwd(std::vector<int>& evidence) {

	// collect the original functions
	factor F = first->theta;
	F = F.condition(evidence);

	// collect the incoming messages (should already be projected)
	for (size_t i = 0; i < first->edges.size(); ++i) {
		detail::edge* e = first->edges[i];
		if (e == this) {
			continue; // skip current edge
		}
		if (e->first->id == first->id) {
			F *= e->bwd.condition(evidence);
		} else if (e->second->id == first->id) {

			F *= e->fwd.condition(evidence);
		}
	}

	// Find the evidence variables in the scope of the cluster
	variable_set evid;
	for (variable_set::const_iterator i = first->clique.begin();
			i != first->clique.end(); ++i) {
		int v = i->label();
		if (evidence[v] >= 0) {
			evid |= *i;
		}
	}

	// Marginalize the non-evidence eliminator
	//F = F.condition(evidence);
	variable_set elim = (first->clique - sepset);
	elim -= evid;
	if (elim.size() > 0) {
		F = F.sum(elim);
	}

	// update the forward message
	this->fwd = F;

}