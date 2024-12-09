void DockTabBar::mousePressEvent(QMouseEvent* event)
    {
        if (event->button() != Qt::LeftButton)
        {
            event->ignore();
            return;
        }

        TabBar::mousePressEvent(event);
    }