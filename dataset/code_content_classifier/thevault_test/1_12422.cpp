EditorComponentAPIRequests::AddComponentsOutcome EditorLevelComponentAPIComponent::AddComponentsOfType(const AZ::ComponentTypeList& componentTypeIds)
        {
            //Always get the EntityId of the Level.
            AZ::EntityId levelEntityId;
            ToolsApplicationRequestBus::BroadcastResult(levelEntityId, &ToolsApplicationRequests::GetCurrentLevelEntityId);
            if (!levelEntityId.IsValid())
            {
                return EditorComponentAPIRequests::AddComponentsOutcome(AZStd::string("Invalid Level EntityId. Most likely there's no level loaded in the Editor."));
            }

            EditorComponentAPIRequests::AddComponentsOutcome outcome;
            EditorComponentAPIBus::BroadcastResult(outcome, &EditorComponentAPIRequests::AddComponentsOfType, levelEntityId, componentTypeIds);
            return outcome;
        }