int EditorNetModel::addAgentLink(Agent *src_agent, Agent *dst_agent) {

	if (!src_agent->AgentPartner_ && !dst_agent->AgentPartner_
			&& checkAgentCompatibility(src_agent->name(), dst_agent->name())) {
		// Only connect agents that don't have a partner yet
		// and are compatible with each other
	 
		agent_type src_type = classifyAgent(src_agent->name());

		if (   src_type == UDP_SOURCE_AGENT
		    || src_type == TCP_SOURCE_AGENT
		    || src_type == FULLTCP_AGENT) {

			src_agent->AgentRole_ = SOURCE;
			dst_agent->AgentRole_ = DESTINATION;
		} else {
			src_agent->AgentRole_ = DESTINATION;
			src_agent->AgentRole_ = SOURCE;
		}

		src_agent->AgentPartner_ = dst_agent;
		dst_agent->AgentPartner_ = src_agent;
		return TCL_OK;
	}

	return TCL_ERROR;
}