void BlendTree::Rewind(AnimGraphInstance* animGraphInstance)
    {
        for (AnimGraphNode* childNode : m_childNodes)
        {
            childNode->Rewind(animGraphInstance);
        }

        // call the base class rewind
        AnimGraphNode::Rewind(animGraphInstance);
    }