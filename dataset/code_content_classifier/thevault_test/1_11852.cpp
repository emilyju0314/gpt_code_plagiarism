QSize DockTabBar::sizeHint() const
    {
        if (m_singleTabFillsWidth && count() == 1)
        {
            return TabBar::tabSizeHint(0);
        }

        return TabBar::sizeHint();
    }