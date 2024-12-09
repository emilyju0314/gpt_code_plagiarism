void NodeGroupWidget::SelectNodesButtonPressed()
    {
        // check if node group is set
        if (m_nodeGroup == nullptr)
        {
            return;
        }

        // set the action for the selected nodes
        QWidget* senderWidget = (QWidget*)sender();
        if (senderWidget == m_addNodesButton)
        {
            m_nodeAction = CommandSystem::CommandAdjustNodeGroup::NodeAction::Add;
        }
        else
        {
            m_nodeAction = CommandSystem::CommandAdjustNodeGroup::NodeAction::Replace;
        }

        // get the selected actorinstance
        const CommandSystem::SelectionList& selection       = GetCommandManager()->GetCurrentSelection();
        EMotionFX::ActorInstance*           actorInstance   = selection.GetSingleActorInstance();

        // show hint if no/multiple actor instances is/are selected
        if (actorInstance == nullptr)
        {
            return;
        }

        // create selection list for the current nodes within the group
        m_nodeSelectionList.Clear();
        if (senderWidget == m_selectNodesButton)
        {
            for (const uint16 i : m_nodeGroup->GetNodeArray())
            {
                EMotionFX::Node* node = m_actor->GetSkeleton()->GetNode(i);
                m_nodeSelectionList.AddNode(node);
            }
        }

        // show the node selection window
        m_nodeSelectionWindow->Update(actorInstance->GetID(), &m_nodeSelectionList);
        m_nodeSelectionWindow->show();
    }