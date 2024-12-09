void BlendTree::OnRemoveNode(AnimGraph* animGraph, AnimGraphNode* nodeToRemove)
    {
        if (GetVirtualFinalNode() == nodeToRemove)
        {
            SetVirtualFinalNode(nullptr);
        }

        if (GetFinalNode() == nodeToRemove)
        {
            m_finalNodeId = AnimGraphNodeId::InvalidId;
            m_finalNode = nullptr;
        }

        // call it for all children
        AnimGraphNode::OnRemoveNode(animGraph, nodeToRemove);
    }