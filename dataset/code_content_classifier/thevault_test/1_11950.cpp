void ActorPropertiesWindow::OnExcludedJointsFromBoundsSelectionDone(const AZStd::vector<SelectionItem>& selectedJoints)
    {
        EMotionFX::ActorInstance* actorInstance = m_excludeFromBoundsBrowseEdit->GetActorInstance();
        if (!actorInstance)
        {
            return;
        }

        AZStd::string command = AZStd::string::format("AdjustActor -actorID %i -nodesExcludedFromBounds \"", m_actor->GetID());

        // prepare the nodes excluded from bounds string
        size_t addedItems = 0;
        for (const SelectionItem& selectedJoint : selectedJoints)
        {
            EMotionFX::Node* node = m_actor->GetSkeleton()->FindNodeByName(selectedJoint.GetNodeName());
            if (node)
            {
                if (addedItems > 0)
                {
                    command += ';';
                }

                command += node->GetName();
                addedItems++;
            }
        }

        command += "\" -nodeAction \"select\"";

        // Reset the changes we did so that the undo data can be stored correctly.
        OnExcludedJointsFromBoundsSelectionChanged(m_excludeFromBoundsBrowseEdit->GetPreviouslySelectedJoints());

        AZStd::string result;
        if (!EMStudio::GetCommandManager()->ExecuteCommand(command, result))
        {
            AZ_Error("EMotionFX", false, result.c_str());
        }
    }