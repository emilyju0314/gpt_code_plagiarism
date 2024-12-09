NodePort* NodeGraph::FindPort(int32 x, int32 y, GraphNode** outNode, AZ::u16* outPortNr, bool* outIsInputPort, bool includeInputPorts)
    {
        // get the number of nodes in the graph and iterate through them
        for (const GraphNodeByModelIndex::value_type& indexAndGraphNode : m_graphNodeByModelIndex)
        {
            GraphNode* graphNode = indexAndGraphNode.second.get();

            // skip the node in case it is collapsed
            if (graphNode->GetIsCollapsed())
            {
                continue;
            }

            // check if we're in a port of the given node
            NodePort* result = graphNode->FindPort(x, y, outPortNr, outIsInputPort, includeInputPorts);
            if (result)
            {
                *outNode = graphNode;
                return result;
            }
        }

        // failure, no port at the given coordinates
        return nullptr;
    }