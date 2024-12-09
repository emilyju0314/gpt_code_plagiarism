void ActorComponent::OnAttached(AZ::EntityId attachedEntityId)
        {
            const AZ::EntityId* busIdPtr = LmbrCentral::AttachmentComponentNotificationBus::GetCurrentBusId();
            if (busIdPtr)
            {
                const auto result = AZStd::find(m_attachments.begin(), m_attachments.end(), attachedEntityId);
                if (result == m_attachments.end())
                {
                    m_attachments.emplace_back(attachedEntityId);
                }
                else
                {
                    return;
                }
            }

            if (!m_actorInstance)
            {
                return;
            }

            ActorInstance* targetActorInstance = nullptr;
            ActorComponentRequestBus::EventResult(targetActorInstance, attachedEntityId, &ActorComponentRequestBus::Events::GetActorInstance);

            const char* jointName = nullptr;
            LmbrCentral::AttachmentComponentRequestBus::EventResult(jointName, attachedEntityId, &LmbrCentral::AttachmentComponentRequestBus::Events::GetJointName);
            if (targetActorInstance)
            {
                Node* node = jointName ? m_actorInstance->GetActor()->GetSkeleton()->FindNodeByName(jointName) : m_actorInstance->GetActor()->GetSkeleton()->GetNode(0);
                if (node)
                {
                    const size_t jointIndex = node->GetNodeIndex();
                    Attachment* attachment = AttachmentNode::Create(m_actorInstance.get(), jointIndex, targetActorInstance, true /* Managed externally, by this component. */);
                    m_actorInstance->AddAttachment(attachment);
                }
            }
        }