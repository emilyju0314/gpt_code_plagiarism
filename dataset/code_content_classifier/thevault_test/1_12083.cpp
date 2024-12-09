AZStd::unordered_set<AZ::Component*> GetRelatedIncompatibleComponents(const AZ::Component* component1)
    {
        AZStd::unordered_set<AZ::Component*> incompatibleComponents;

        auto entity = component1 ? component1->GetEntity() : nullptr;
        if (entity)
        {
            auto componentDescriptor1 = AzToolsFramework::GetComponentDescriptor(component1);
            if (componentDescriptor1)
            {
                AZ::ComponentDescriptor::DependencyArrayType providedServices1;
                AZ::ComponentDescriptor::DependencyArrayType providedServices2;
                AZ::ComponentDescriptor::DependencyArrayType incompatibleServices1;
                AZ::ComponentDescriptor::DependencyArrayType incompatibleServices2;

                //get the list of required and incompatible services from the primary component
                componentDescriptor1->GetProvidedServices(providedServices1, nullptr);
                componentDescriptor1->GetIncompatibleServices(incompatibleServices1, nullptr);

                //build a list of all components attached to the entity
                AZ::Entity::ComponentArrayType allComponents = entity->GetComponents();

                //also include invalid components waiting for requirements to be met
                EditorPendingCompositionRequestBus::Event(entity->GetId(), &EditorPendingCompositionRequests::GetPendingComponents, allComponents);

                //for every component related to the entity, determine if its services are incompatible with the primary component
                for (auto component2 : allComponents)
                {
                    //don't test against itself
                    if (component1 == component2)
                    {
                        continue;
                    }

                    auto componentDescriptor2 = AzToolsFramework::GetComponentDescriptor(component2);
                    if (!componentDescriptor2)
                    {
                        continue;
                    }

                    //get the list of required and incompatible services for the comparison component
                    providedServices2.clear();
                    componentDescriptor2->GetProvidedServices(providedServices2, nullptr);

                    incompatibleServices2.clear();
                    componentDescriptor2->GetIncompatibleServices(incompatibleServices2, nullptr);

                    //if provided services overlap incompatible services for either component then add it to the list
                    if (DoContainersIntersect(providedServices1, incompatibleServices2) ||
                        DoContainersIntersect(providedServices2, incompatibleServices1))
                    {
                        incompatibleComponents.insert(component2);
                    }
                }
            }
        }
        return incompatibleComponents;
    }