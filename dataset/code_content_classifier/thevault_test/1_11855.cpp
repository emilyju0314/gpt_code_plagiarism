void DockTabBar::closeTabGroup()
    {
        // Close each of the tabs using our signal trigger so they are cleaned
        // up properly
        int numTabs = count();
        for (int i = 0; i < numTabs; ++i)
        {
            emit closeTab(0);
        }
    }