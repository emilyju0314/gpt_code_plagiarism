void BlendGraphWidget::SetSelectedTransitionsEnabled(bool isEnabled)
    {
        // only allowed when a state machine is currently being showed
        if (!CheckIfIsStateMachine())
        {
            return;
        }

        // gather the selected transitions
        AZStd::vector<NodeConnection*> selectedTransitions = GetActiveGraph()->GetSelectedNodeConnections();

        if (!selectedTransitions.empty())
        {
            MCore::CommandGroup commandGroup("Enable/disable transitions", static_cast<uint32>(selectedTransitions.size()));

            // iterate through the selected transitions and and enable or disable them
            for (NodeConnection* selectedTransition : selectedTransitions)
            {
                // get the transition and its visual representation
                StateConnection*                     visualTransition = static_cast<StateConnection*>(selectedTransition);
                EMotionFX::AnimGraphStateTransition* transition = FindTransitionForConnection(visualTransition);

                // get the target node
                EMotionFX::AnimGraphNode* targetNode = transition->GetTargetNode();
                if (targetNode == nullptr)
                {
                    MCore::LogError("Cannot enable/disable transition with id %s. Target node is invalid.", transition->GetId().ToString().c_str());
                    continue;
                }

                // get the parent node of the target node
                EMotionFX::AnimGraphNode* parentNode = targetNode->GetParentNode();
                if (parentNode == nullptr || (parentNode && azrtti_typeid(parentNode) != azrtti_typeid<EMotionFX::AnimGraphStateMachine>()))
                {
                    MCore::LogError("Cannot enable/disable transition with id %s. Parent node is invalid.", transition->GetId().ToString().c_str());
                    continue;
                }

                CommandSystem::AdjustTransition(transition, !isEnabled,
                    /*sourceNode=*/AZStd::nullopt, /*targetNode=*/AZStd::nullopt,
                    /*startOffsetXY=*/AZStd::nullopt, AZStd::nullopt, /*endOffsetXY=*/AZStd::nullopt, AZStd::nullopt,
                    /*attributesString=*/AZStd::nullopt, /*serializedMembers=*/AZStd::nullopt,
                    &commandGroup);
            }

            AZStd::string resultString;
            if (!GetCommandManager()->ExecuteCommandGroup(commandGroup, resultString))
            {
                if (resultString.size() > 0)
                {
                    MCore::LogError(resultString.c_str());
                }
            }
        }
    }