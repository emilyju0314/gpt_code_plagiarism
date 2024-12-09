void AttachmentsWindow::OnAttachmentNodesSelected(AZStd::vector<SelectionItem> selection)
    {
        // check if selection is valid
        if (selection.size() != 1)
        {
            MCore::LogDebug("No valid attachment selected.");
            return;
        }

        const uint32 actorInstanceID    = selection[0].m_actorInstanceId;
        const char* nodeName            = selection[0].GetNodeName();
        if (EMotionFX::GetActorManager().FindActorInstanceByID(actorInstanceID) == nullptr)
        {
            return;
        }

        // create command group
        AZStd::string outResult;
        MCore::CommandGroup commandGroup("Adjust attachment node");

        // get the attachment
        EMotionFX::ActorInstance* attachment = GetSelectedAttachment();
        if (attachment == nullptr)
        {
            return;
        }

        AZStd::string oldNodeName = GetSelectedNodeName();

        // remove and readd the attachment
        commandGroup.AddCommandString(AZStd::string::format("RemoveAttachment -attachmentID %i -attachToID %i -attachToNode \"%s\"", attachment->GetID(), m_actorInstance->GetID(), oldNodeName.c_str()).c_str());
        commandGroup.AddCommandString(AZStd::string::format("AddAttachment -attachToID %i -attachmentID %i -attachToNode \"%s\"", m_actorInstance->GetID(), attachment->GetID(), nodeName).c_str());

        // execute the command group
        GetCommandManager()->ExecuteCommandGroup(commandGroup, outResult);
    }