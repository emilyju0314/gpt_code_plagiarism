void RepositioningLayerPass::Process()
    {
        ActorInstance* actorInstance = m_motionSystem->GetActorInstance();
        if (!actorInstance->GetMotionExtractionEnabled())
        {
            actorInstance->SetTrajectoryDeltaTransform(Transform::CreateIdentityWithZeroScale());
            return;
        }

        // Get the motion extraction node and check if we are actually playing any motions.
        Actor* actor = actorInstance->GetActor();
        Node* motionExtractNode = actor->GetMotionExtractionNode();
        if (!motionExtractNode || m_motionSystem->GetNumMotionInstances() == 0)
        {
            actorInstance->SetTrajectoryDeltaTransform(Transform::CreateIdentityWithZeroScale());
            return;
        }

        Transform finalTrajectoryDelta = Transform::CreateIdentityWithZeroScale(); 
        Transform trajectoryDelta;

        // Get the original transform data pointer, which we need for the additive blending.
        Pose* bindPose = actorInstance->GetTransformData()->GetBindPose();

        // Bottom up traversal of the layers.
        bool firstBlend = true;
        const size_t numMotionInstances = m_motionSystem->GetNumMotionInstances();
        for (size_t i = numMotionInstances - 1; i != InvalidIndex; --i)
        {
            MotionInstance* motionInstance = m_motionSystem->GetMotionInstance(i);
            if (!motionInstance->GetMotionExtractionEnabled())
            {
                continue;
            }

            // This motion doesn't influence the motion extraction node.
            if (!motionInstance->ExtractMotion(trajectoryDelta))
            {
                continue;
            }

            // Blend the relative movement.
            const float weight = motionInstance->GetWeight();
            if (motionInstance->GetBlendMode() != BLENDMODE_ADDITIVE || firstBlend)
            {
                finalTrajectoryDelta.Blend(trajectoryDelta, weight);
                firstBlend = false;
            }
            else
            {
                finalTrajectoryDelta.BlendAdditive(trajectoryDelta, bindPose->GetLocalSpaceTransform(motionExtractNode->GetNodeIndex()), weight);
            }
        }

        // Apply the final trajectory delta transform the the actor instance.
        actorInstance->SetTrajectoryDeltaTransform(finalTrajectoryDelta);
        actorInstance->ApplyMotionExtractionDelta();
    }