void ActorPropertiesWindow::OnFindBestMatchingNode()
    {
        // check if the actor is invalid
        if (m_actor == nullptr)
        {
            return;
        }

        // find the best motion extraction node
        EMotionFX::Node* bestMatchingNode = m_actor->FindBestMotionExtractionNode();
        if (bestMatchingNode == nullptr)
        {
            return;
        }

        // create the command group
        MCore::CommandGroup commandGroup("Adjust motion extraction node");

        // adjust the actor
        const AZStd::string command = AZStd::string::format("AdjustActor -actorID %i -motionExtractionNodeName \"%s\"", m_actor->GetID(), bestMatchingNode->GetName());
        commandGroup.AddCommandString(command);

        // execute the command group
        AZStd::string result;
        if (!EMStudio::GetCommandManager()->ExecuteCommandGroup(commandGroup, result))
        {
            AZ_Error("EMotionFX", false, result.c_str());
        }
    }