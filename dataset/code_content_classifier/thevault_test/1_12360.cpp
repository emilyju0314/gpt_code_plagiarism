bool NodeGraph::CheckIfIsRelinkConnectionValid(NodeConnection* connection, GraphNode* newTargetNode, AZ::u16 newTargetPortNr, bool isTargetInput)
    {
        GraphNode* targetNode = connection->GetSourceNode();
        GraphNode* sourceNode = newTargetNode;
        AZ::u16 sourcePortNr = connection->GetOutputPortNr();
        AZ::u16 targetPortNr = newTargetPortNr;

        // don't allow connection to itself
        if (sourceNode == targetNode)
        {
            return false;
        }

        // if we're not dealing with state nodes
        if (sourceNode->GetType() != StateGraphNode::TYPE_ID || targetNode->GetType() != StateGraphNode::TYPE_ID)
        {
            if (isTargetInput == false)
            {
                return false;
            }
        }

        // if this were states, it's all fine
        if (sourceNode->GetType() == StateGraphNode::TYPE_ID || targetNode->GetType() == StateGraphNode::TYPE_ID)
        {
            return true;
        }

        // check if there is already a connection in the port
        AZ_Assert(sourceNode->GetType() == BlendTreeVisualNode::TYPE_ID, "Expected blend tree node");
        AZ_Assert(targetNode->GetType() == BlendTreeVisualNode::TYPE_ID, "Expected blend tree node");
        BlendTreeVisualNode* targetBlendNode = static_cast<BlendTreeVisualNode*>(sourceNode);
        BlendTreeVisualNode* sourceBlendNode = static_cast<BlendTreeVisualNode*>(targetNode);

        EMotionFX::AnimGraphNode* emfxSourceNode = sourceBlendNode->GetEMFXNode();
        EMotionFX::AnimGraphNode* emfxTargetNode = targetBlendNode->GetEMFXNode();
        EMotionFX::AnimGraphNode::Port& sourcePort = emfxSourceNode->GetOutputPort(sourcePortNr);
        EMotionFX::AnimGraphNode::Port& targetPort = emfxTargetNode->GetInputPort(targetPortNr);

        // if the port data types are not compatible, don't allow the connection
        if (targetPort.CheckIfIsCompatibleWith(sourcePort) == false)
        {
            return false;
        }

        return true;
    }