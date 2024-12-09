void SkinningInfoVertexAttributeLayer::RemoveAllInfluencesForNode(size_t nodeNr)
    {
        // get the number of vertices/attributes
        const size_t numAttributes = m_data.GetNumRows();
        for (size_t a = 0; a < numAttributes; ++a)
        {
            // iterate through all influences and compare them with the given node
            size_t i = 0;
            while (i < GetNumInfluences(a))
            {
                // remove the influence when it is linked to the given node
                if (GetInfluence(a, i)->GetNodeNr() == nodeNr)
                {
                    RemoveInfluence(a, i);
                }
                else
                {
                    i++;
                }
            }
        }
    }