void BlendGraphWidget::OnShiftClickedNode(GraphNode* node)
    {
        // when we are dealing with a state node
        if (node->GetType() == StateGraphNode::TYPE_ID)
        {
            EMotionFX::AnimGraphInstance* animGraphInstance = GetActiveGraph()->GetModelIndex().data(AnimGraphModel::ROLE_ANIM_GRAPH_INSTANCE).value<EMotionFX::AnimGraphInstance*>();
            if (animGraphInstance)
            {
                animGraphInstance->TransitionToState(node->GetName());
            }
        }
    }