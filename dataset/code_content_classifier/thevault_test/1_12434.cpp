EditorOnlyEntityHandler::Result 
        AdjustForEditorOnlyEntities(AZ::SliceComponent* slice, const AZStd::unordered_set<AZ::EntityId>& editorOnlyEntities, AZ::SerializeContext& serializeContext, EditorOnlyEntityHandler* customHandler)
        {
            AzToolsFramework::EntityList entities;
            slice->GetEntities(entities);

            // Invoke custom handler if provided, so callers can process the slice to account for editor-only entities
            // that are about to be removed.
            if (customHandler)
            {
                const EditorOnlyEntityHandler::Result handlerResult = customHandler->HandleEditorOnlyEntities(entities, editorOnlyEntities, serializeContext);
                if (!handlerResult)
                {
                    return handlerResult;
                }
            }

            // Remove editor-only entities from the slice's final entity list.
            for (auto entityIter = entities.begin(); entityIter != entities.end(); )
            {
                AZ::Entity* entity = (*entityIter);

                if (editorOnlyEntities.find(entity->GetId()) != editorOnlyEntities.end())
                {
                    entityIter = entities.erase(entityIter);
                    slice->RemoveEntity(entity);
                }
                else
                {
                    ++entityIter;
                }
            }

            return AZ::Success();
        }