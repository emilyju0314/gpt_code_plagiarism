void AttributesWindow::OnRemoveStateAction()
    {
        AZ_Assert(m_displayingModelIndex.isValid(), "Object shouldn't be null.");

        QAction* action = static_cast<QAction*>(sender());
        const int actionIndex = action->property("actionIndex").toInt();

        AZ_Assert(m_displayingModelIndex.data(AnimGraphModel::ROLE_MODEL_ITEM_TYPE).value<AnimGraphModel::ModelItemType>() == AnimGraphModel::ModelItemType::NODE,
            "StateAction must added on an anim graph node");

        EMotionFX::AnimGraphNode* node = m_displayingModelIndex.data(AnimGraphModel::ROLE_NODE_POINTER).value<EMotionFX::AnimGraphNode*>();
        CommandSystem::RemoveStateAction(node, actionIndex);
    }