bool BlendGraphWidget::CheckIfIsCreateConnectionValid(AZ::u16 portNr, GraphNode* portNode, NodePort* port, bool isInputPort)
    {
        MCORE_UNUSED(port);
        MCORE_ASSERT(m_activeGraph);

        GraphNode* sourceNode = m_activeGraph->GetCreateConnectionNode();
        GraphNode* targetNode = portNode;

        // don't allow connection to itself
        if (sourceNode == targetNode)
        {
            return false;
        }

        // if we're not dealing with state nodes
        if (sourceNode->GetType() != StateGraphNode::TYPE_ID || targetNode->GetType() != StateGraphNode::TYPE_ID)
        {
            // dont allow to connect an input port to another input port or output port to another output port
            if (isInputPort == m_activeGraph->GetCreateConnectionIsInputPort())
            {
                return false;
            }
        }

        // if this were states, it's all fine
        if (sourceNode->GetType() == StateGraphNode::TYPE_ID || targetNode->GetType() == StateGraphNode::TYPE_ID)
        {
            return CheckIfIsValidTransition(sourceNode, targetNode);
        }

        // check if there is already a connection in the port
        MCORE_ASSERT(portNode->GetType() == BlendTreeVisualNode::TYPE_ID);
        MCORE_ASSERT(sourceNode->GetType() == BlendTreeVisualNode::TYPE_ID);
        BlendTreeVisualNode* targetBlendNode;
        BlendTreeVisualNode* sourceBlendNode;
        AZ::u16 sourcePortNr;
        AZ::u16 targetPortNr;

        // make sure the input always comes from the source node
        if (isInputPort)
        {
            sourceBlendNode = static_cast<BlendTreeVisualNode*>(sourceNode);
            targetBlendNode = static_cast<BlendTreeVisualNode*>(targetNode);
            sourcePortNr    = m_activeGraph->GetCreateConnectionPortNr();
            targetPortNr    = portNr;
        }
        else
        {
            sourceBlendNode = static_cast<BlendTreeVisualNode*>(targetNode);
            targetBlendNode = static_cast<BlendTreeVisualNode*>(sourceNode);
            sourcePortNr    = portNr;
            targetPortNr    = m_activeGraph->GetCreateConnectionPortNr();
        }

        EMotionFX::AnimGraphNode::Port& sourcePort = sourceBlendNode->GetEMFXNode()->GetOutputPort(sourcePortNr);
        EMotionFX::AnimGraphNode::Port& targetPort = targetBlendNode->GetEMFXNode()->GetInputPort(targetPortNr);

        // if the port data types are not compatible, don't allow the connection
        if (sourcePort.CheckIfIsCompatibleWith(targetPort) == false)
        {
            return false;
        }

        EMotionFX::AnimGraphNode* parentNode = targetBlendNode->GetEMFXNode()->GetParentNode();
        EMotionFX::BlendTree* blendTree = static_cast<EMotionFX::BlendTree*>(parentNode);

        if (blendTree->ConnectionWillProduceCycle(sourceBlendNode->GetEMFXNode(), targetBlendNode->GetEMFXNode()))
        {
            return false;
        }

        return true;
    }