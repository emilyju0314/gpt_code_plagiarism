void ActorPropertiesWindow::OnExcludedJointsFromBoundsSelectionChanged(const AZStd::vector<SelectionItem>& selectedJoints)
    {
        EMotionFX::ActorInstance* actorInstance = m_excludeFromBoundsBrowseEdit->GetActorInstance();
        if (!actorInstance)
        {
            return;
        }

        EMotionFX::Actor* actor = actorInstance->GetActor();
        EMotionFX::Skeleton* skeleton = actor->GetSkeleton();
        const size_t numJoints = m_actor->GetNumNodes();

        // Include all joints first.
        for (size_t i = 0; i < numJoints; ++i)
        {
            skeleton->GetNode(i)->SetIncludeInBoundsCalc(true);
        }

        // Exclude the selected joints.
        for (const SelectionItem& selectedJoint : selectedJoints)
        {
            EMotionFX::Node* node = skeleton->FindNodeByName(selectedJoint.GetNodeName());
            if (node)
            {
                node->SetIncludeInBoundsCalc(false);
            }
        }
    }