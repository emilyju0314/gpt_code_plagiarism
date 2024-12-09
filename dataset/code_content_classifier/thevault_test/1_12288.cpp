EMotionFX::ActorInstance* SelectionList::GetSingleActorInstance() const
    {
        if (GetNumSelectedActorInstances() == 0)
        {
            //LogDebug("Cannot get single selected actor instance. No actor instance selected.");
            return nullptr;
        }

        if (GetNumSelectedActorInstances() > 1)
        {
            //LogDebug("Cannot get single selected actor instance. Multiple actor instances selected.");
            return nullptr;
        }

        EMotionFX::ActorInstance* actorInstance = m_selectedActorInstances[0];
        if (!actorInstance)
        {
            return nullptr;
        }

        if (actorInstance->GetIsOwnedByRuntime())
        {
            return nullptr;
        }

        return m_selectedActorInstances[0];
    }