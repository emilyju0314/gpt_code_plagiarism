void BlendTree::Output(AnimGraphInstance* animGraphInstance)
    {
        AZ_PROFILE_SCOPE(Animation, "BlendTree::Output");

        AZ_Assert(m_finalNode, "There should always be a final node. Something seems to be wrong with the blend tree creation.");

        // get the output pose
        AnimGraphPose* outputPose;

        // if this node is disabled, output the bind pose
        if (m_disabled)
        {
            RequestPoses(animGraphInstance);
            outputPose = GetOutputPose(animGraphInstance, OUTPUTPORT_POSE)->GetValue();
            outputPose->InitFromBindPose(animGraphInstance->GetActorInstance());
            return;
        }

        // output final node
        AnimGraphNode* finalNode = GetRealFinalNode();
        if (finalNode)
        {
            OutputIncomingNode(animGraphInstance, finalNode);

            RequestPoses(animGraphInstance);
            outputPose = GetOutputPose(animGraphInstance, OUTPUTPORT_POSE)->GetValue();
            *outputPose = *finalNode->GetMainOutputPose(animGraphInstance);

            finalNode->DecreaseRef(animGraphInstance);
        }
        else
        {
            RequestPoses(animGraphInstance);
            outputPose = GetOutputPose(animGraphInstance, OUTPUTPORT_POSE)->GetValue();
            outputPose->InitFromBindPose(animGraphInstance->GetActorInstance());
        }

        // visualize it
        if (GetEMotionFX().GetIsInEditorMode() && GetCanVisualize(animGraphInstance))
        {
            animGraphInstance->GetActorInstance()->DrawSkeleton(outputPose->GetPose(), m_visualizeColor);
        }
    }