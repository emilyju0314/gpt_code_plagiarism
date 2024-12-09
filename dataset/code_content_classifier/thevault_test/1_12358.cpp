void NodeGraph::RenderCreateConnection(QPainter& painter)
    {
        if (GetIsRelinkingConnection())
        {
            // gather some information from the connection
            NodeConnection* connection      = GetRelinkConnection();
            QPoint          start           = connection->GetSourceRect().center();
            QPoint          end             = m_graphWidget->GetMousePos();

            QPen pen;
            pen.setColor(QColor(100, 100, 100));
            pen.setStyle(Qt::DotLine);
            painter.setPen(pen);
            painter.setBrush(Qt::NoBrush);

            QRect areaRect(end.x() - 150, end.y() - 150, 300, 300);
            for (const GraphNodeByModelIndex::value_type& indexAndGraphNode : m_graphNodeByModelIndex)
            {
                GraphNode* node = indexAndGraphNode.second.get();

                if (node->GetIsCollapsed())
                {
                    continue;
                }

                // if the node isn't intersecting the area rect it is not close enough
                if (areaRect.intersects(node->GetRect()) == false)
                {
                    continue;
                }

                // now check all ports to see if they would be valid
                const AZ::u16 numInputPorts = node->GetNumInputPorts();
                for (AZ::u16 i = 0; i < numInputPorts; ++i)
                {
                    if (CheckIfIsRelinkConnectionValid(m_relinkConnection, node, i, true))
                    {
                        QPoint tempStart = end;
                        QPoint tempEnd = node->GetInputPort(i)->GetRect().center();

                        if ((tempStart - tempEnd).manhattanLength() < 150)
                        {
                            painter.drawLine(tempStart, tempEnd);
                        }
                    }
                }
            }

            // figure out the color of the connection line
            if (m_targetPort)
            {
                if (m_conIsValid)
                {
                    painter.setPen(QColor(0, 255, 0));
                }
                else
                {
                    painter.setPen(QColor(255, 0, 0));
                }
            }
            else
            {
                painter.setPen(QColor(255, 255, 0));
            }

            // render the smooth line towards the mouse cursor
            painter.setBrush(Qt::NoBrush);

            DrawSmoothedLineFast(painter, start.x(), start.y(), end.x(), end.y(), 1);
        }


        // if we're not creating a connection there is nothing to render
        if (GetIsCreatingConnection() == false)
        {
            return;
        }

        //------------------------------------------
        // draw the suggested valid connections
        //------------------------------------------
        QPoint start = m_graphWidget->GetMousePos();
        QPoint end;

        QPen pen;
        pen.setColor(QColor(100, 100, 100));
        pen.setStyle(Qt::DotLine);
        painter.setPen(pen);
        painter.setBrush(Qt::NoBrush);

        if (m_graphWidget->CreateConnectionShowsHelpers())
        {
            QRect areaRect(start.x() - 150, start.y() - 150, 300, 300);
            for (const GraphNodeByModelIndex::value_type& indexAndGraphNode : m_graphNodeByModelIndex)
            {
                GraphNode* node = indexAndGraphNode.second.get();

                if (node->GetIsCollapsed())
                {
                    continue;
                }

                // if the node isn't intersecting the area rect it is not close enough
                if (areaRect.intersects(node->GetRect()) == false)
                {
                    continue;
                }

                // now check all ports to see if they would be valid
                const AZ::u16 numInputPorts = node->GetNumInputPorts();
                for (AZ::u16 i = 0; i < numInputPorts; ++i)
                {
                    if (m_graphWidget->CheckIfIsCreateConnectionValid(i, node, node->GetInputPort(i), true))
                    {
                        end = node->GetInputPort(i)->GetRect().center();

                        if ((start - end).manhattanLength() < 150)
                        {
                            painter.drawLine(start, end);
                        }
                    }
                }

                // now check all ports to see if they would be valid
                const AZ::u16 numOutputPorts = node->GetNumOutputPorts();
                for (AZ::u16 a = 0; a < numOutputPorts; ++a)
                {
                    if (m_graphWidget->CheckIfIsCreateConnectionValid(a, node, node->GetOutputPort(a), false))
                    {
                        end = node->GetOutputPort(a)->GetRect().center();

                        if ((start - end).manhattanLength() < 150)
                        {
                            painter.drawLine(start, end);
                        }
                    }
                }
            }
        }

        //------------------------------

        // update the end point
        start = GetCreateConnectionNode()->GetRect().topLeft() + GetCreateConnectionStartOffset();
        end   = m_graphWidget->GetMousePos();

        // figure out the color of the connection line
        if (m_targetPort)
        {
            if (m_conIsValid)
            {
                painter.setPen(QColor(0, 255, 0));
            }
            else
            {
                painter.setPen(QColor(255, 0, 0));
            }
        }
        else
        {
            painter.setPen(QColor(255, 255, 0));
        }

        // render the smooth line towards the mouse cursor
        painter.setBrush(Qt::NoBrush);

        if (m_graphWidget->CreateConnectionMustBeCurved())
        {
            DrawSmoothedLineFast(painter, start.x(), start.y(), end.x(), end.y(), 1);
        }
        else
        {
            QRect sourceRect = GetCreateConnectionNode()->GetRect();
            sourceRect.adjust(-2, -2, 2, 2);

            if (sourceRect.contains(end))
            {
                return;
            }

            // calc the real start point
            double realX, realY;
            if (NodeGraph::LineIntersectsRect(sourceRect, aznumeric_cast<float>(start.x()), aznumeric_cast<float>(start.y()), aznumeric_cast<float>(end.x()), aznumeric_cast<float>(end.y()), &realX, &realY))
            {
                start.setX(aznumeric_cast<int>(realX));
                start.setY(aznumeric_cast<int>(realY));
            }

            painter.drawLine(start, end);
        }
    }