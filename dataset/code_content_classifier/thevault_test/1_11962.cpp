bool AnimGraphVisualNode::GetHasError() const
    {
        // extract anim graph instance
        EMotionFX::AnimGraphInstance* animGraphInstance = ExtractAnimGraphInstance();
        if (animGraphInstance == nullptr)
        {
            return false;
        }

        // return the error state of the emfx node
        EMotionFX::AnimGraphObjectData* uniqueData = m_emfxNode->FindOrCreateUniqueNodeData(animGraphInstance);
        return m_emfxNode->HierarchicalHasError(uniqueData);
    }