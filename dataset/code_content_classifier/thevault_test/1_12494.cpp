void TrackHeaderWidget::keyReleaseEvent(QKeyEvent* event)
    {
        if (m_plugin)
        {
            m_plugin->OnKeyReleaseEvent(event);
        }
    }