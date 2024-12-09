void SelectionList::AddAnimGraph(EMotionFX::AnimGraph* animGraph)
    {
        if (!CheckIfHasAnimGraph(animGraph))
        {
            m_selectedAnimGraphs.emplace_back(animGraph);
        }
    }