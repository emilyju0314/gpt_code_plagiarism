const MeshBuilderVertexLookup MeshBuilder::FindVertexIndex(size_t orgVertexNr) const
    {
        // if there are no layers, we can't find a valid index
        if (m_layers.empty())
        {
            return {};
        }

        // try to locate a matching duplicate
        return FindMatchingDuplicate(orgVertexNr);
    }