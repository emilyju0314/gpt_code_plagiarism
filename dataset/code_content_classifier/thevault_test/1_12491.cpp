void HeaderTrackWidget::keyPressEvent(QKeyEvent* event)
    {
        if (m_plugin)
        {
            m_plugin->OnKeyPressEvent(event);
        }
    }