void MeshDeformerStack::UpdateByModifierType(ActorInstance* actorInstance, Node* node, float timeDelta, uint32 typeID, bool resetMesh, bool forceUpdateDisabledDeformers)
    {
        bool resetDone = false;
        for (MeshDeformer* deformer : m_deformers)
        {
            // if the deformer of the correct type and is enabled
            if (deformer->GetType() == typeID && (deformer->GetIsEnabled() || forceUpdateDisabledDeformers))
            {
                // if this is the first enabled deformer
                if (resetMesh && !resetDone)
                {
                    // reset all output vertex data to the original vertex data
                    m_mesh->ResetToOriginalData();
                    resetDone = true;
                }

                // update the mesh deformer
                deformer->Update(actorInstance, node, timeDelta);
            }
        }
    }