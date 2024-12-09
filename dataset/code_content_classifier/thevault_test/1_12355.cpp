void NodeGraph::FitGraphOnScreen(int32 width, int32 height, const QPoint& mousePos, bool animate)
    {
        // fit the entire graph in the view
        UpdateNodesAndConnections(width, height, mousePos);
        QRect sceneRect = CalcRectFromGraph();

        //  MCore::LOG("sceneRect: (%d, %d, %d, %d)", sceneRect.left(), sceneRect.top(), sceneRect.width(), sceneRect.height());

        if (sceneRect.isEmpty() == false)
        {
            const int border = aznumeric_cast<int>(10.0f * (1.0f / m_scale));
            sceneRect.adjust(-border, -border, border, border);
            ZoomOnRect(sceneRect, width, height, animate);
        }
    }