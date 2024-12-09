EditorOnlyEntityHandler* FindHandlerForEntities(const AZ::SliceComponent::EntityList& entities, const EditorOnlyEntityHandlers& editorOnlyEntityHandlers)
        {
            EditorOnlyEntityHandler* editorOnlyEntityHandler = nullptr;
            for (auto handlerCandidate : editorOnlyEntityHandlers)
            {
                const bool handlerInvalid = handlerCandidate == nullptr;
                if (handlerInvalid)
                {
                    continue;
                }

                // See if this handler can handle at least one of the entities.
                for (AZ::Entity* entity : entities)
                {
                    if (handlerCandidate->IsEntityUniquelyForThisHandler(entity))
                    {
                        editorOnlyEntityHandler = handlerCandidate;
                        break;
                    }
                }

                const bool editorOnlyHandlerValid = editorOnlyEntityHandler != nullptr;
                if (editorOnlyHandlerValid)
                {
                    break;
                }
            }

            return editorOnlyEntityHandler;
        }