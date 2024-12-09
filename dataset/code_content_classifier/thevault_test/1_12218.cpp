void Recorder::RecordMainLocalTransforms()
    {
        // for all actor instances
        for (ActorInstanceData* actorInstanceData : m_actorInstanceDatas)
        {
            ActorInstance* actorInstance = actorInstanceData->m_actorInstance;
            const Transform& transform = actorInstance->GetLocalSpaceTransform();

        #ifndef EMFX_SCALE_DISABLED
            AddTransformKey(actorInstanceData->m_actorLocalTransform, transform.m_position, transform.m_rotation, transform.m_scale);
        #else
            AddTransformKey(actorInstanceData->m_actorLocalTransform, transform.m_position, transform.m_rotation, AZ::Vector3(1.0f, 1.0f, 1.0f));
        #endif
        }
    }