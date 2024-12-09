QRect NodeGraph::CalcRectFromGraph() const
    {
        QRect result;

        // for all nodes
        for (const AZStd::pair<QPersistentModelIndex, AZStd::unique_ptr<GraphNode> >& modelIndexAndGraphNode : m_graphNodeByModelIndex)
        {
            GraphNode* graphNode = modelIndexAndGraphNode.second.get();

            // add the rect
            result |= graphNode->GetRect();

            // for all connections
            const size_t numConnections = graphNode->GetNumConnections();
            for (size_t c = 0; c < numConnections; ++c)
            {
                result |= graphNode->GetConnection(c)->CalcRect();
            }
        }

        return result;
    }