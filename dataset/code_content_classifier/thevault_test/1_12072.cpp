void TimeViewPlugin::MakeTimeVisible(double timeValue, double offsetFactor, bool animate)
    {
        SetRedrawFlag();

        const double pixel = TimeToPixel(timeValue, false);

        // if we need to scroll to the right
        double width = m_trackDataWidget->geometry().width() / m_timeScale;
        m_targetScrollX += (pixel - width) + width * (1.0 - offsetFactor);

        if (m_targetScrollX < 0)
        {
            m_targetScrollX = 0;
        }

        if (animate == false)
        {
            m_scrollX = m_targetScrollX;
        }
    }