void StandardMaterial::Render(EMotionFX::ActorInstance* actorInstance, const Primitive* primitive)
    {
        // check if the shader is valid and return in case it's not
        if (m_activeShader == nullptr)
        {
            return;
        }

        // change depth buffer settings
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
        glDepthMask(GL_TRUE);

        const EMotionFX::TransformData* transformData = actorInstance->GetTransformData();

        if (m_attributes[SKINNING])
        {
            const AZ::Matrix3x4* skinningMatrices = transformData->GetSkinningMatrices();

            // multiple each transform by its inverse bind pose
            const size_t numBones = primitive->m_boneNodeIndices.size();
            for (size_t i = 0; i < numBones; ++i)
            {
                const size_t nodeNr = primitive->m_boneNodeIndices[i];
                const AZ::Matrix3x4& skinTransform = skinningMatrices[nodeNr];
                m_boneMatrices[i] = AZ::Matrix4x4::CreateFromMatrix3x4(skinTransform);
            }

            m_activeShader->SetUniform("matBones", m_boneMatrices, aznumeric_caster(numBones));
        }

        const MCommon::Camera*    camera         = GetGraphicsManager()->GetCamera();
        const AZ::Transform       worldTransform = actorInstance->GetWorldSpaceTransform().ToAZTransform();
        const AZ::Matrix4x4       world          = AZ::Matrix4x4::CreateFromTransform(worldTransform);
        const AZ::Matrix4x4       worldView      = camera->GetViewMatrix() * world;
        const AZ::Matrix4x4       worldViewProj  = camera->GetViewProjMatrix() * world;
        const AZ::Matrix4x4       worldIT        = world.GetInverseFull().GetTranspose();

        m_activeShader->SetUniform("matWorld", world);
        m_activeShader->SetUniform("matWorldIT", worldIT);
        m_activeShader->SetUniform("matWorldView", worldView);
        m_activeShader->SetUniform("matWorldViewProj", worldViewProj);

        // render the primitive
        glDrawElementsBaseVertex(GL_TRIANGLES, primitive->m_numTriangles * 3, GL_UNSIGNED_INT, (GLvoid*)(primitive->m_indexOffset * sizeof(uint32)), primitive->m_vertexOffset);
    }