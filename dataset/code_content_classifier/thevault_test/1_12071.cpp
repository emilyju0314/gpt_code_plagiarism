double TimeViewPlugin::CalcFitScale(double minScale, double maxScale) const
    {
        // get the duration
        double maxTime;
        GetDataTimes(&maxTime, nullptr, nullptr);

        // calculate the right scale to fit it
        double scale = 1.0;
        if (maxTime > 0.0)
        {
            double width    = m_trackDataWidget->geometry().width();
            scale   = (width / m_pixelsPerSecond) / maxTime;
        }

        if (scale < minScale)
        {
            scale = minScale;
        }

        if (scale > maxScale)
        {
            scale = maxScale;
        }

        return scale;
    }