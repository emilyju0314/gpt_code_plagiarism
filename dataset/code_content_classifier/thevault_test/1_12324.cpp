void MotionSetHierarchyWidget::Update(EMotionFX::MotionSet* motionSet, CommandSystem::SelectionList* selectionList)
    {
        m_motionSet = motionSet;
        m_currentSelectionList = selectionList;

        if (selectionList == nullptr)
        {
            m_currentSelectionList = &(GetCommandManager()->GetCurrentSelection());
        }

        Update();
    }