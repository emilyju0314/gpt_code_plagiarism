bool Actor::CheckIfHasMeshes(size_t lodLevel) const
    {
        // check if any of the nodes has a mesh
        const size_t numNodes = m_skeleton->GetNumNodes();
        for (size_t i = 0; i < numNodes; ++i)
        {
            if (GetMesh(lodLevel, i))
            {
                return true;
            }
        }

        // aaaah, no meshes found
        return false;
    }