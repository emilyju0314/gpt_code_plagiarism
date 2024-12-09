void Graph::addVertex(uint32_t nodeId)
	{
		Vertices::iterator it = m_vertices.find(nodeId);
		if (it == m_vertices.end()) //If iterator has been reached the end of the vertices map, it hasn't been found
		{
			Vertex *v = new Vertex(m_vertexIdCount, nodeId);
			m_vertices[nodeId]=v;
			m_vertexIdCount++;
		}
	}