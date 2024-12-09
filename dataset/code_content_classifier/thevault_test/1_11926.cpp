bool Actor::CheckIfHasSkinningDeformer(size_t lodLevel, size_t nodeIndex) const
    {
        // check if there is a mesh
        Mesh* mesh = GetMesh(lodLevel, nodeIndex);
        if (!mesh)
        {
            return false;
        }

        // check if there is a mesh deformer stack
        MeshDeformerStack* stack = GetMeshDeformerStack(lodLevel, nodeIndex);
        if (!stack)
        {
            return false;
        }

        return (stack->CheckIfHasDeformerOfType(SoftSkinDeformer::TYPE_ID) || stack->CheckIfHasDeformerOfType(DualQuatSkinDeformer::TYPE_ID));
    }