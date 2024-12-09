void NodeGraph::RenderReplaceTransition(QPainter& painter)
    {
        // prepare the Qt painter
        QColor headTailColor(0, 255, 0);
        painter.setPen(headTailColor);
        painter.setBrush(headTailColor);
        const uint32 circleRadius = 4;

        // get the number of nodes and iterate through them
        for (const GraphNodeByModelIndex::value_type& indexAndGraphNode : m_graphNodeByModelIndex)
        {
            GraphNode* graphNode = indexAndGraphNode.second.get();

            // get the number of connections and iterate through them
            const size_t numConnections = graphNode->GetNumConnections();
            for (size_t j = 0; j < numConnections; ++j)
            {
                NodeConnection* connection = graphNode->GetConnection(j);

                // in case the mouse is over the transition
                if (connection->GetIsTailHighlighted() && connection->GetIsWildcardTransition() == false)
                {
                    // calculate its start and end points
                    QPoint start, end;
                    connection->CalcStartAndEndPoints(start, end);

                    // calculate the normalized direction vector of the transition from tail to head
                    AZ::Vector2 dir = AZ::Vector2(aznumeric_cast<float>(end.x() - start.x()), aznumeric_cast<float>(end.y() - start.y()));
                    dir.Normalize();

                    AZ::Vector2 newStart = AZ::Vector2(aznumeric_cast<float>(start.x()), aznumeric_cast<float>(start.y())) + dir * (float)circleRadius;
                    painter.drawEllipse(QPoint(aznumeric_cast<int>(newStart.GetX()), aznumeric_cast<int>(newStart.GetY())), circleRadius, circleRadius);
                    return;
                }
            }
        }
    }