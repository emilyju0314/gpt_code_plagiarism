void NodeGraph::ScrollTo(const QPointF& point)
    {
        m_startScrollOffset  = m_scrollOffset;
        m_targetScrollOffset = point;
        m_scrollTimer.start(1000 / 60);
        m_scrollPreciseTimer.Stamp();
    }