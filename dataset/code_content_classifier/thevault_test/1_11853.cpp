void DockTabBar::tabLayoutChange()
    {
        TabBar::tabLayoutChange();

        // Only the active tab's close button should be shown
        const ButtonPosition closeSide = (ButtonPosition)style()->styleHint(QStyle::SH_TabBar_CloseButtonPosition, nullptr, this);
        const int numTabs = count();
        const int activeTabIndex = currentIndex();
        for (int i = 0; i < numTabs; ++i)
        {
            if (auto button = tabButton(i, closeSide))
            {
                button->setVisible(i == activeTabIndex);
            }
        }

        // If the tab indicators are showing, then we need to show our underlay
        if (m_leftButton->isVisible())
        {
            // The underlay will take up the combined space behind the left and
            // right indicator buttons
            QRect total = m_leftButton->geometry();
            total = total.united(m_rightButton->geometry());
            m_tabIndicatorUnderlay->setGeometry(total);

            // The indicator buttons get raised when shown, so we need to stack
            // our underlay under the left button, which will place it under
            // both indicator buttons, and then show it
            m_tabIndicatorUnderlay->stackUnder(m_leftButton);
            m_tabIndicatorUnderlay->show();
        }
        else
        {
            m_tabIndicatorUnderlay->hide();
        }
    }