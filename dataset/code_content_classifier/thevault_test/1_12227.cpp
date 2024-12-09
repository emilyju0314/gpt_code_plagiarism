void BlendSpace2DNode::DetermineOuterEdges(UniqueData& uniqueData)
    {
        uniqueData.m_outerEdges.clear();

        AZStd::unordered_map<Edge, AZ::u32, EdgeHasher> edgeToCountMap;
        for (const Triangle& tri : uniqueData.m_triangles)
        {
            for (int i = 0; i < 3; ++i)
            {
                int j = (i + 1) % 3;
                Edge edge;
                edge.m_vertIndices[0] = tri.m_vertIndices[i];
                edge.m_vertIndices[1] = tri.m_vertIndices[j];
                if (edge.m_vertIndices[0] > edge.m_vertIndices[1])
                {
                    AZStd::swap(edge.m_vertIndices[0], edge.m_vertIndices[1]);
                }
                auto mapIt = edgeToCountMap.find(edge);
                if (mapIt == edgeToCountMap.end())
                {
                    edgeToCountMap[edge] = 1;
                }
                else
                {
                    mapIt->second++;
                }
            }
        }
        for (auto& mapEntry : edgeToCountMap)
        {
            const AZ::u32 shareCount = mapEntry.second;
            AZ_Assert((shareCount == 1) || (shareCount == 2), "Edges should be shared by at most 2 triangles");
            if (shareCount == 1)
            {
                uniqueData.m_outerEdges.push_back(mapEntry.first);
            }
        }
    }