bool NodeGraph::CheckIfHasConnection(GraphNode* sourceNode, AZ::u16 outputPortNr, GraphNode* targetNode, AZ::u16 inputPortNr) const
    {
        const size_t numConnections = targetNode->GetNumConnections();
        for (size_t i = 0; i < numConnections; ++i)
        {
            NodeConnection* connection = targetNode->GetConnection(i);

            // check if the connection properties are equal
            if (connection->GetInputPortNr() == inputPortNr)
            {
                if (connection->GetSourceNode() == sourceNode)
                {
                    if (connection->GetOutputPortNr() == outputPortNr)
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }