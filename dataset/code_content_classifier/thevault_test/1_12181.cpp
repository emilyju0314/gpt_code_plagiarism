AZ::Entity* FindEntity(const AZ::EntityId& entityId)
    {
        // First check the component application for the entity. This is where game, editor, and the root system entities live.
        AZ::Entity* entity = nullptr;
        AZ::ComponentApplicationBus::BroadcastResult(entity, &AZ::ComponentApplicationRequests::FindEntity, entityId);

        if (entity == nullptr)
        {
            // The entity was not in the component application's entity list, but it may be a system entity for a module.
            AZ::ModuleManagerRequestBus::Broadcast(&AZ::ModuleManagerRequestBus::Events::EnumerateModules, [&entity, entityId](const AZ::ModuleData& moduleData)
            {
                AZ::Entity* moduleEntity = moduleData.GetEntity();
                if (moduleEntity != nullptr && moduleEntity->GetId() == entityId)
                {
                    entity = moduleEntity;
                    // The entity was found, so stop the enumeration.
                    return false;
                }
                // The matching entity is not in this module, keep looking through the rest of the modules.
                return true;
            });
        }
        return entity;
    }