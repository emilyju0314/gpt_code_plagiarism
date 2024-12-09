bool EditorActorComponent::IsValidAttachment(const AZ::EntityId& attachment, const AZ::EntityId& attachTo) const
        {
            // Cannot attach to yourself.
            if (attachment == attachTo)
            {
                return false;
            }

            // Detect if attachTo is already in another circular chain.
            auto AttachmentStep = [](AZ::EntityId attach, int stride) -> AZ::EntityId
            {
                AZ_Assert(stride > 0, "Stride value has to be greater than 0.");

                if (attach.IsValid())
                {
                    for (int i = 0; i < stride; ++i)
                    {
                        AZ::EntityId next;
                        EditorActorComponentRequestBus::EventResult(next, attach, &EditorActorComponentRequestBus::Events::GetAttachedToEntityId);
                        if (!next.IsValid())
                        {
                            return next;
                        }
                        attach = next;
                    }
                    return attach;
                }
                else
                {
                    return attach;
                }
            };
            AZ::EntityId slowWalker = attachTo;
            AZ::EntityId fastWalker = attachTo;
            while (fastWalker.IsValid())
            {
                slowWalker = AttachmentStep(slowWalker, 1);
                fastWalker = AttachmentStep(fastWalker, 2);
                if (fastWalker.IsValid() && fastWalker == slowWalker)
                {
                    return false; // Cycle detected if slowWalker meets fastWalker.
                }
            }

            // Walk our way up to the root.
            AZ::EntityId resultId;
            EditorActorComponentRequestBus::EventResult(resultId, attachTo, &EditorActorComponentRequestBus::Events::GetAttachedToEntityId);
            while (resultId.IsValid())
            {
                AZ::EntityId localResult;
                EditorActorComponentRequestBus::EventResult(localResult, resultId, &EditorActorComponentRequestBus::Events::GetAttachedToEntityId);

                // We detected a loop.
                if (localResult == attachment)
                {
                    return false;
                }

                resultId = localResult;
            }

            return true;
        }