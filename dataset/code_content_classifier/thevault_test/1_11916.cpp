void Actor::UpdateStaticAabb()
    {
        ActorInstance* actorInstance = ActorInstance::Create(this, nullptr, m_threadIndex);
        actorInstance->UpdateMeshDeformers(0.0f);
        actorInstance->UpdateStaticBasedAabbDimensions();
        actorInstance->GetStaticBasedAabb(&m_staticAabb);
        actorInstance->Destroy();
    }