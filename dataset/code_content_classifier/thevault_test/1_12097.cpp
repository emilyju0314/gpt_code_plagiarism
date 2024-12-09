void AnimGraphHubNode::OnRemoveNode(AnimGraph* animGraph, AnimGraphNode* nodeToRemove)
    {
        const size_t numAnimGraphInstances = animGraph->GetNumAnimGraphInstances();
        for (size_t i = 0; i < numAnimGraphInstances; ++i)
        {
            AnimGraphInstance* animGraphInstance = animGraph->GetAnimGraphInstance(i);
            
            UniqueData* uniqueData = static_cast<UniqueData*>(FindOrCreateUniqueNodeData(animGraphInstance));          
            if (uniqueData->m_sourceNode == nodeToRemove)
            {
                uniqueData->m_sourceNode = nullptr;
            }
        }
    }