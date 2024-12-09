void Graph::add_vertex(const std::bitset<STATES> &state)
{
	//check if already in Graph
	if (vertexID.find(state) != vertexID.end())  return;

	//else proceed to add in graph
	size_t stateID = V;	//assign state ID
	std::pair<std::bitset<STATES>, size_t> vertex(state, stateID);
	//add to map
	vertexID.insert(vertex);
	//add to adjadency list
	std::vector<Edge> adj;
	G.push_back(adj);

	//increment vertex count
	++V;
	inDegree.push_back(0);
}