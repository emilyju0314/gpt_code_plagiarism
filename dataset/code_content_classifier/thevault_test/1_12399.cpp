void NodeGroupsPlugin::ReInit()
    {
        // get the selected actor instance
        const CommandSystem::SelectionList& selection       = CommandSystem::GetCommandManager()->GetCurrentSelection();
        EMotionFX::ActorInstance*           actorInstance   = selection.GetSingleActorInstance();

        // show hint if no/multiple actor instances is/are selected
        if (actorInstance == nullptr)
        {
            m_currentActor = nullptr;
            m_nodeGroupWidget->SetActor(nullptr);
            m_nodeGroupWidget->SetNodeGroup(nullptr);
            m_nodeGroupManagementWidget->SetActor(nullptr);
            return;
        }

        // get the corresponding actor
        EMotionFX::Actor* actor = actorInstance->GetActor();

        // only reinit the node groups window if actorinstance changed
        if (m_currentActor != actor)
        {
            // set the new actor
            m_currentActor = actor;

            // set the new actor on each widget
            m_nodeGroupWidget->SetActor(m_currentActor);
            m_nodeGroupManagementWidget->SetActor(m_currentActor);
        }

        // set the dialog stack as main widget
        m_dock->setWidget(m_dialogStack);

        // update the interface
        UpdateInterface();
    }