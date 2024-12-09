bool Actor::CheckIfIsMaterialUsed(Mesh* mesh, size_t materialIndex) const
    {
        // check if the mesh is valid
        if (mesh == nullptr)
        {
            return false;
        }

        // iterate through the submeshes
        const size_t numSubMeshes = mesh->GetNumSubMeshes();
        for (size_t s = 0; s < numSubMeshes; ++s)
        {
            // if the submesh material index is the same as the material index we search for, then it is being used
            if (mesh->GetSubMesh(s)->GetMaterial() == materialIndex)
            {
                return true;
            }
        }

        return false;
    }