void CycleFinder::dfs(const Graph& G,
					  std::pair<std::bitset<STATES>, size_t> vMap,
					  std::vector<SimpleCycle>& fromV,
					  SimpleCycle& c)
{
	size_t v = vMap.second;
	//Push vertex on a stack and mark it
	stack.push_back(v);
	onStack[v] = true;
	//Iterate over all adjacent vertices
	for (auto edge : G.adj(vMap.first))
	{
		size_t w = edge.to();
		//If its marked indicated its on the current path
		//And thus should not be explored
		//We have found all cycles for nodes on ignore list
		//so no need to traverse them
		if (!onStack[w] && !ignore[w])
		{
			c.add_edge(edge);
			std::pair<std::bitset<STATES>, size_t> e(edge.to_state(),edge.to());
			//Traverse adjacent node recusively
			dfs(G, e, fromV, c);
		}
		else if (stack[0] == w && !ignore[w])
		{
			//Cycle is found for either self loop
			//or when tail of path is equal to head
			c.add_edge(edge);
			if (c.is_cycle())  fromV.push_back(c);
			c = SimpleCycle();
		}
	}
	//Push it of the stack for further exploration
	//And unmark it
	stack.pop_back();
	onStack[v] = false;
}