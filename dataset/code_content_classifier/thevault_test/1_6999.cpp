void 
EditorNetModel::removeAgent(Agent *a) {
	Node * n;
	TrafficSource * ts, * next_ts;
	n = a->node_;
	
	if (a->AgentPartner_ != NULL) {
		a->AgentPartner_->AgentPartner_ = NULL;
		a->AgentPartner_->AgentRole_ = 0;
	}
	n->delete_agent(a);
	a->detach();

	for (ts = a->traffic_sources_; ts; ts = next_ts) {
		// Save next traffic source in list since this
		// traffic source will be deleted in removeTrafficSource
		next_ts = ts->next_;
		removeTrafficSource(ts);
	}

	delete a;
}