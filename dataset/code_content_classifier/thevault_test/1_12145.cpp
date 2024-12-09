void BlendTreeVisualNode::Sync()
    {
        // remove all ports and connections
        RemoveAllInputPorts();
        RemoveAllOutputPorts();
        RemoveAllConnections();

        // add all input ports
        const AZStd::vector<EMotionFX::AnimGraphNode::Port>& inPorts = m_emfxNode->GetInputPorts();
        const AZ::u16 numInputs = aznumeric_caster(inPorts.size());
        m_inputPorts.reserve(numInputs);
        for (AZ::u16 i = 0; i < numInputs; ++i)
        {
            NodePort* port = AddInputPort(false);
            port->SetNameID(inPorts[i].m_nameId);
            port->SetColor(GetPortColor(inPorts[i]));
        }

        if (GetHasVisualOutputPorts())
        {
            // add all output ports
            const AZStd::vector<EMotionFX::AnimGraphNode::Port>& outPorts = m_emfxNode->GetOutputPorts();
            const AZ::u16 numOutputs = aznumeric_caster(outPorts.size());
            m_outputPorts.reserve(numOutputs);
            for (AZ::u16 i = 0; i < numOutputs; ++i)
            {
                NodePort* port = AddOutputPort(false);
                port->SetNameID(outPorts[i].m_nameId);
                port->SetColor(GetPortColor(outPorts[i]));
            }
        }

        // Recreate connections
        const int rows = m_modelIndex.model()->rowCount(m_modelIndex);
        for (int row = 0; row < rows; ++row)
        {
            const QModelIndex childIndex = m_modelIndex.model()->index(row, 0, m_modelIndex);
            if (childIndex.data(AnimGraphModel::ROLE_MODEL_ITEM_TYPE).value<AnimGraphModel::ModelItemType>() == AnimGraphModel::ModelItemType::CONNECTION)
            {
                EMotionFX::BlendTreeConnection* connection = childIndex.data(AnimGraphModel::ROLE_CONNECTION_POINTER).value<EMotionFX::BlendTreeConnection*>();

                GraphNode* source = m_parentGraph->FindGraphNode(connection->GetSourceNode());
                GraphNode* target = this;
                const AZ::u16 sourcePort = connection->GetSourcePort();
                const AZ::u16 targetPort = connection->GetTargetPort();

                NodeConnection* visualConnection = new NodeConnection(m_parentGraph, childIndex, target, targetPort, source, sourcePort);
                target->AddConnection(visualConnection);
            }
        }

        UpdateNameAndPorts();

        AnimGraphVisualNode::Sync();
    }