void SkinningInfoVertexAttributeLayer::RemapInfluences(size_t oldNodeNr, size_t newNodeNr)
    {
        // get the number of vertices/attributes
        const size_t numAttributes = m_data.GetNumRows();
        for (size_t a = 0; a < numAttributes; ++a)
        {
            // iterate through all influences and compare them with the old node
            const size_t numInfluences = GetNumInfluences(a);
            for (size_t i = 0; i < numInfluences; ++i)
            {
                // remap the influence to the new node when it is linked to the old node
                if (GetInfluence(a, i)->GetNodeNr() == oldNodeNr)
                {
                    GetInfluence(a, i)->SetNodeNr(static_cast<uint16>(newNodeNr));
                }
            }
        }
    }