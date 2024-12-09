std::string Graph::to_string(size_t stateLen) const
{
	std::string graphStr;
	//For all vertex
	for (auto &state : vertexID)
	{
		//TODO : Format String
		graphStr += "State : "
			     + state.first.to_string().substr(STATES - stateLen) 
			     + "\n";
		//For all edges of the vertex
		for (auto &edge : G[state.second])
			graphStr += edge.to_string(stateLen) + "\n";
	}
	return graphStr;
}