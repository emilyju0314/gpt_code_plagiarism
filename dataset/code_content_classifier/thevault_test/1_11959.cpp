void NodeGroupWidget::SetActor(EMotionFX::Actor* actor)
    {
        // set the new actor
        m_actor = actor;
        m_nodeGroup = nullptr;

        // update the interface
        UpdateInterface();
    }