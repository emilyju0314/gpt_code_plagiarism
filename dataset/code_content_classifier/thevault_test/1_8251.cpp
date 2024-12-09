void Graph::add_edge(const std::bitset<STATES> &u,
					 const std::bitset<STATES> &v,
					 const size_t latency)
{
	//Find state IDs
	size_t uid = vertexID.find(u)->second;
	size_t vid = vertexID.find(v)->second;
	//Create a new Edge and insert
	Edge uv(u, uid, v, vid, latency);
	G[uid].push_back(uv);

	//Increment Edge Count
	++E;
	//Increment Indegree Count
	inDegree[vid] += 1;
	//TODO : Add Exception Check
}