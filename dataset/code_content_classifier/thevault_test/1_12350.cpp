NodeConnection* NodeGraph::FindConnection(const QPoint& mousePos)
    {
        // for all nodes in the graph
        for (const GraphNodeByModelIndex::value_type& indexAndGraphNode : m_graphNodeByModelIndex)
        {
            GraphNode* graphNode = indexAndGraphNode.second.get();

            // iterate over all connections
            const size_t numConnections = graphNode->GetNumConnections();
            for (size_t c = 0; c < numConnections; ++c)
            {
                NodeConnection* connection  = graphNode->GetConnection(c);
                if (connection->CheckIfIsCloseTo(mousePos))
                {
                    return connection;
                }
            }
        }

        // failure, there is no connection at the given mouse position
        return nullptr;
    }