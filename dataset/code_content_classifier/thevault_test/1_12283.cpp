void SelectionList::AddActorInstance(EMotionFX::ActorInstance* actorInstance)
    {
        if (!CheckIfHasActorInstance(actorInstance))
        {
            m_selectedActorInstances.emplace_back(actorInstance);
        }
    }