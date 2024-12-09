void detail::edge::messageBwd(std::vector<int>& evidence) {

	// collect the original functions
	factor F = second->theta;
	F = F.condition(evidence);

	// collect the incoming messages
	for (size_t i = 0; i < second->edges.size(); ++i) {
		detail::edge* e = second->edges[i];
		if (e == this) {
			continue; // skip current edge
		}
		if (e->first->id == second->id) {
			F *= e->bwd.condition(evidence); //e->getMessage2();
		} else if (e->second->id == second->id) {
			F *= e->fwd.condition(evidence); //e->getMessage1();
		}
	}

	// find the evidence variables in the scope of the cluster
	variable_set evid;
	for (variable_set::const_iterator i = second->clique.begin();
			i != second->clique.end(); ++i) {
		int v = i->label();
		if (evidence[v] >= 0) {
			evid |= *i;
		}
	}

	// marginalize the eliminator
	variable_set elim = (second->clique - sepset);
	elim -= evid;
	if (elim.size() > 0) {
		F = F.sum(elim);
	}

	this->bwd = F;

}