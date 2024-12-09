void BlendGraphWidget::SetVirtualFinalNode(const QModelIndex& nodeModelIndex)
    {
        if (nodeModelIndex.isValid())
        {
            const QModelIndex parent = nodeModelIndex.parent();
            NodeGraphByModelIndex::const_iterator it = m_nodeGraphByModelIndex.find(parent);
            if (it != m_nodeGraphByModelIndex.end())
            {
                EMotionFX::AnimGraphNode* parentNode = it->first.data(AnimGraphModel::ROLE_NODE_POINTER).value<EMotionFX::AnimGraphNode*>();
                if (azrtti_typeid(parentNode) == azrtti_typeid<EMotionFX::BlendTree>())
                {
                    EMotionFX::AnimGraphNode* node = nodeModelIndex.data(AnimGraphModel::ROLE_NODE_POINTER).value<EMotionFX::AnimGraphNode*>();
                    EMotionFX::BlendTree* blendTree = static_cast<EMotionFX::BlendTree*>(parentNode);

                    // update all graph node opacity values
                    it->second->RecursiveSetOpacity(blendTree->GetFinalNode(), 0.065f);
                    it->second->RecursiveSetOpacity(node, 1.0f);

                    if (node != blendTree->GetFinalNode())
                    {
                        GraphNode* graphNode = it->second->FindGraphNode(nodeModelIndex);
                        graphNode->SetBorderColor(QColor(0, 255, 0));
                    }
                }
            }
        }
    }