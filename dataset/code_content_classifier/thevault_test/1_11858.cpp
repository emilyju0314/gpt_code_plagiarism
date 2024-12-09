void DockTabBar::finishDrag()
    {
        QMouseEvent event(QEvent::MouseButtonRelease, {0.0f, 0.0f}, Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
        mouseReleaseEvent(&event);
    }