void DockTabBar::currentIndexChanged(int current)
    {
        Q_UNUSED(current);

        resizeEvent(nullptr);
    }