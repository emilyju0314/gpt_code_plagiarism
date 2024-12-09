void Actor::ResizeTransformData()
    {
        Pose& bindPose = *m_skeleton->GetBindPose();
        bindPose.LinkToActor(this, Pose::FLAG_LOCALTRANSFORMREADY, false);

        const size_t numMorphs = bindPose.GetNumMorphWeights();
        for (size_t i = 0; i < numMorphs; ++i)
        {
            bindPose.SetMorphWeight(i, 0.0f);
        }

        m_invBindPoseTransforms.resize(m_skeleton->GetNumNodes());
    }