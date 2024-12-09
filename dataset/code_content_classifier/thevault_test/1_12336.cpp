void GLActor::RenderMeshes(EMotionFX::ActorInstance* actorInstance, EMotionFX::Mesh::EMeshType meshType, uint32 renderFlags)
    {
        const size_t lodLevel     = actorInstance->GetLODLevel();
        const size_t numMaterials = m_materials[lodLevel].size();

        if (numMaterials == 0)
        {
            return;
        }

        if (m_vertexBuffers[meshType][lodLevel] == nullptr || m_indexBuffers[meshType][lodLevel] == nullptr)
        {
            return;
        }

        if (m_vertexBuffers[meshType][lodLevel]->GetBufferID() == MCORE_INVALIDINDEX32)
        {
            return;
        }

        // activate vertex and index buffers
        m_vertexBuffers[meshType][lodLevel]->Activate();
        m_indexBuffers[meshType][lodLevel]->Activate();

        // render all the primitives in each material
        for (const MaterialPrimitives* materialPrims : m_materials[lodLevel])
        {
            if (materialPrims->m_primitives[meshType].empty())
            {
                continue;
            }

            Material* material = materialPrims->m_material;
            if (material == nullptr)
            {
                continue;
            }

            material->SetAttribute(Material::LIGHTING,      (renderFlags & RENDER_LIGHTING) != 0);
            material->SetAttribute(Material::TEXTURING,     (renderFlags & RENDER_TEXTURING) != 0);
            material->SetAttribute(Material::SKINNING,      (meshType == EMotionFX::Mesh::MESHTYPE_GPU_DEFORMED));
            material->SetAttribute(Material::SHADOWS,       false);     // self-shadowing disabled

            // if the materials are homogenous, activate globally
            uint32 activationFlags = Material::GLOBAL | Material::LOCAL;
            material->Activate(activationFlags);

            // render all primitives
            for (const Primitive& primitive : materialPrims->m_primitives[meshType])
            {
                material->Render(actorInstance, &primitive);
            }

            material->Deactivate();
        }
    }