double TimeViewPlugin::TimeToPixel(double timeInSeconds, bool scale) const
    {
        double result = ((timeInSeconds * m_pixelsPerSecond)) - m_scrollX;
        if (scale)
        {
            return (result * m_timeScale);
        }
        else
        {
            return result;
        }
    }