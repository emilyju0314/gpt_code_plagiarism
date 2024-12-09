void MorphTargetsWindowPlugin::ReInit(bool forceReInit)
    {
        const CommandSystem::SelectionList& selection = GetCommandManager()->GetCurrentSelection();
        EMotionFX::ActorInstance* actorInstance = selection.GetSingleActorInstance();
        ReInit(actorInstance, forceReInit);
    }