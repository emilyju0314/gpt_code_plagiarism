void AttributesWindow::OnRemoveTransitionAction()
    {
        AZ_Assert(m_displayingModelIndex.isValid(), "Object shouldn't be null.");

        QAction* action = static_cast<QAction*>(sender());
        const int actionIndex = action->property("actionIndex").toInt();
        AZ_Assert(m_displayingModelIndex.data(AnimGraphModel::ROLE_MODEL_ITEM_TYPE).value<AnimGraphModel::ModelItemType>() == AnimGraphModel::ModelItemType::TRANSITION,
            "Expected a transition");

        EMotionFX::AnimGraphStateTransition* transition = m_displayingModelIndex.data(AnimGraphModel::ROLE_TRANSITION_POINTER).value<EMotionFX::AnimGraphStateTransition*>();
        CommandSystem::RemoveTransitionAction(transition, actionIndex);
    }