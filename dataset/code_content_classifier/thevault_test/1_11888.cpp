void SkinningInfoVertexAttributeLayer::CollectInfluencedNodes(AZStd::vector<uint32>& influencedNodes, bool clearInfluencedNodesArray)
    {
        if (clearInfluencedNodesArray)
        {
            influencedNodes.clear();
        }

        // get the number of vertices/attributes
        const size_t numAttributes = m_data.GetNumRows();
        for (size_t a = 0; a < numAttributes; ++a)
        {
            // get the number of influences for the current vertex
            const size_t numInfluences = GetNumInfluences(a);

            // iterate through all influences and compare them with the old node
            for (size_t i = 0; i < numInfluences; ++i)
            {
                const size_t influencedNodeNr = GetInfluence(a, i)->GetNodeNr();

                // check if the influenced node is already in our array, if not add it so that we only store each node once
                if (AZStd::find(begin(influencedNodes), end(influencedNodes), influencedNodeNr) == end(influencedNodes))
                {
                    influencedNodes.emplace_back(aznumeric_cast<uint32>(influencedNodeNr));
                }
            }
        }
    }