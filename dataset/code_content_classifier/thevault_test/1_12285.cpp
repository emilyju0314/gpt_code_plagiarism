void SelectionList::AddMotionInstance(EMotionFX::MotionInstance* motionInstance)
    {
        if (!CheckIfHasMotionInstance(motionInstance))
        {
            m_selectedMotionInstances.emplace_back(motionInstance);
        }
    }