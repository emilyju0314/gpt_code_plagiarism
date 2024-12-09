void EditorActorComponent::OnAttached(AZ::EntityId targetId)
        {
            const AZ::EntityId* busIdPtr = LmbrCentral::AttachmentComponentNotificationBus::GetCurrentBusId();
            if (busIdPtr)
            {
                const auto result = AZStd::find(m_attachments.begin(), m_attachments.end(), *busIdPtr);
                if (result == m_attachments.end())
                {
                    m_attachments.emplace_back(*busIdPtr);
                }
            }

            if (!m_actorInstance)
            {
                return;
            }

            ActorInstance* targetActorInstance = nullptr;
            ActorComponentRequestBus::EventResult(targetActorInstance, targetId, &ActorComponentRequestBus::Events::GetActorInstance);

            const char* jointName = nullptr;
            LmbrCentral::AttachmentComponentRequestBus::EventResult(jointName, GetEntityId(), &LmbrCentral::AttachmentComponentRequestBus::Events::GetJointName);
            if (targetActorInstance)
            {
                Node* node = jointName ? targetActorInstance->GetActor()->GetSkeleton()->FindNodeByName(jointName) : targetActorInstance->GetActor()->GetSkeleton()->GetNode(0);
                if (node)
                {
                    const size_t jointIndex = node->GetNodeIndex();
                    Attachment* attachment = AttachmentNode::Create(targetActorInstance, jointIndex, m_actorInstance.get(), true /* Managed externally, by this component. */);
                    targetActorInstance->AddAttachment(attachment);
                }
            }
        }