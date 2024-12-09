bool Actor::CheckIfIsMaterialUsed(size_t lodLevel, size_t index) const
    {
        // iterate through all nodes of the actor and check its meshes
        const size_t numNodes = m_skeleton->GetNumNodes();
        for (size_t i = 0; i < numNodes; ++i)
        {
            // if the mesh is in LOD range check if it uses the material
            if (CheckIfIsMaterialUsed(GetMesh(lodLevel, i), index))
            {
                return true;
            }
        }

        // return false, this means that no mesh uses the given material
        return false;
    }