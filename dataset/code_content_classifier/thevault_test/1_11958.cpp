void NodeGroupWidget::SetNodeGroup(EMotionFX::NodeGroup* nodeGroup)
    {
        // check if the actor was set
        if (m_actor == nullptr)
        {
            m_nodeGroup = nullptr;
            return;
        }

        // set the node group
        m_nodeGroup = nodeGroup;

        // update the interface
        UpdateInterface();
    }