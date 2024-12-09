bool AnimGraphVisualNode::GetAlwaysColor() const
    {
        // extract anim graph instance
        EMotionFX::AnimGraphInstance* animGraphInstance = ExtractAnimGraphInstance();

        return (animGraphInstance == nullptr) || (animGraphInstance->GetIsOutputReady(m_emfxNode->GetParentNode()->GetObjectIndex()) == false);
    }