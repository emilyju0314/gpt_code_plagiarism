void SelectionList::AddMotion(EMotionFX::Motion* motion)
    {
        if (!CheckIfHasMotion(motion))
        {
            m_selectedMotions.emplace_back(motion);
        }
    }