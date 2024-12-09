void CommandAdjustActor::SetIsAttachmentNode(EMotionFX::Actor* actor, bool isAttachmentNode)
    {
        const size_t numNodes = actor->GetNumNodes();
        for (size_t i = 0; i < numNodes; ++i)
        {
            EMotionFX::Node* node = actor->GetSkeleton()->GetNode(i);
            if (!node)
            {
                continue;
            }

            node->SetIsAttachmentNode(isAttachmentNode);
        }
    }