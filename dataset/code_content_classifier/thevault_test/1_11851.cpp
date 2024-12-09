DockTabBar::DockTabBar(QWidget* parent)
        : TabBar(parent)
        , m_tabIndicatorUnderlay(new QWidget(this))
        , m_leftButton(nullptr)
        , m_rightButton(nullptr)
        , m_contextMenu(nullptr)
        , m_closeTabMenuAction(nullptr)
        , m_closeTabGroupMenuAction(nullptr)
        , m_menuActionTabIndex(-1)
        , m_singleTabFillsWidth(false)
    {
        setFixedHeight(DockBar::Height);
        setMovable(true);
        SetUseMaxWidth(true);

        // Handle our close tab button clicks
        QObject::connect(this, &DockTabBar::tabCloseRequested, this, &DockTabBar::closeTab);

        // Handle when our current tab index changes
        QObject::connect(this, &TabBar::currentChanged, this, &DockTabBar::currentIndexChanged);

        // Our QTabBar base class has left/right indicator buttons for scrolling
        // through the tab header if all the tabs don't fit in the given space for
        // the widget, but they just float over the tabs, so we have added a
        // semi-transparent underlay that will be positioned below them so that
        // it looks better
        QPalette underlayPalette;
        underlayPalette.setColor(QPalette::Window, g_tabIndicatorUnderlayColor);
        m_tabIndicatorUnderlay->setAutoFillBackground(true);
        m_tabIndicatorUnderlay->setPalette(underlayPalette);
        QGraphicsOpacityEffect* effect = new QGraphicsOpacityEffect(m_tabIndicatorUnderlay);
        effect->setOpacity(g_tabIndicatorUnderlayOpacity);
        m_tabIndicatorUnderlay->setGraphicsEffect(effect);

        // The QTabBar has two QToolButton children that are used as left/right
        // indicators to scroll across the tab header when the width is too short
        // to fit all of the tabs
        for (QToolButton* button : findChildren<QToolButton*>(QString(), Qt::FindDirectChildrenOnly))
        {
            // Grab references to each button for use later
            if (button->accessibleName() == TabBar::tr("Scroll Left"))
            {
                m_leftButton = button;
            }
            else
            {
                m_rightButton = button;
            }
        }
    }