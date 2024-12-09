bool StyledDockWidget::event(QEvent* event)
    {
        switch (event->type())
        {
        case QEvent::NonClientAreaMouseMove:
        case QEvent::NonClientAreaMouseButtonPress:
        case QEvent::NonClientAreaMouseButtonRelease:
        case QEvent::NonClientAreaMouseButtonDblClick:
            {
                return true;
            }
        case QEvent::MouseButtonPress:
        case QEvent::MouseMove:
        case QEvent::MouseButtonRelease:
            {
                // For these events, make sure FancyDocking is being used or it will disable
                // Mouse events for the whole Widget
                DockMainWindow* parentMainWindow = qobject_cast<DockMainWindow*>(parentWidget());
                if (parentMainWindow && parentMainWindow->HasFancyDocking())
                {
                    return true;
                }
            }
        }

        return QDockWidget::event(event);
    }