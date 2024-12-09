void PrintTickbusHandlers(AZ::EntityId* entityId)
    {
        AZStd::string tickbusPrintoutTitle = "TickBus handlers in tick order";

        // If an entity ID was given, then update the printout title to contain information about that entity.
        if (entityId != nullptr)
        {
            // Search for the passed in entity, to print out its name.
            // Most people are going to think of their entities in terms of the name, and not the ID.
            AZ::Entity* entity = FindEntity(*entityId);

            if (entity != nullptr)
            {
                tickbusPrintoutTitle = AZStd::string::format("%s for entity \"%s\" %s",
                    tickbusPrintoutTitle.c_str(),
                    entity->GetName().c_str(),
                    entityId->ToString().c_str());
            }
            else
            {
                // If the entity wasn't found, then print out the ID at least.
                tickbusPrintoutTitle = AZStd::string::format("%s for entity with id %s, entity could not be found",
                    tickbusPrintoutTitle.c_str(),
                    entityId->ToString().c_str());
            }

        }
        AZ_Printf("TickBusOrderViewer", tickbusPrintoutTitle.c_str());

        // Visit every tickbus handler. These are already sorted in the order they will be called.
        AZ::TickBus::EnumerateHandlers([entityId](AZ::TickEvents* handler)
        {
            // If this handler is a component, then it will have an associated entity.
            // This will allow printing additional, useful information for the user.
            AZ::Component* component = azrtti_cast<AZ::Component*>(handler);
            if (component && (entityId == nullptr || component->GetEntityId() == *entityId))
            {
                AZStd::string entityName = component->GetEntity() != nullptr ?
                    component->GetEntity()->GetName() : "[No entity found]";
                // Print out everything about this tickbus listener that can help the user debug
                // their tick ordering issue that caused them to call this.
                // This includes:
                // * The component's type as a string and a UUID.
                // * The component's individual ID, which can be useful if the entity has duplicate components of the same type.
                // * The associated entity's name, so the user can trace this tick handler to the entity.
                // * The associated entity's ID, because entity names may not be unique.
                AZ_Printf("TickBusOrderViewer", "\t%d - Entity \"%s\" %s, component %s %s with ID %u",
                    handler->GetTickOrder(),
                    entityName.c_str(),
                    component->GetEntityId().ToString().c_str(),
                    component->RTTI_GetTypeName(),
                    component->RTTI_GetType().ToString<AZStd::string>().c_str(),
                    component->GetId());
            }
            else if(entityId == nullptr)
            {
                // This handler wasn't a component, so print out as much information as can be gathered.
                AZ_Printf("TickBusOrderViewer", "\t%d - Object with type %s %s",
                    handler->GetTickOrder(),
                    handler->RTTI_GetTypeName(),
                    handler->RTTI_GetType().ToString<AZStd::string>().c_str());
            }
            // Return true so the enumeration continues, all handles need to be checked.
            return true;
        });
    }