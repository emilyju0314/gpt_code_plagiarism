bool NodeGraph::LineIntersectsRect(const QRect& b, float x1, float y1, float x2, float y2, double* outX, double* outY)
    {
        // check first if any of the points are inside the rect
        if (outX == nullptr && outY == nullptr)
        {
            if (b.contains(QPoint(aznumeric_cast<int>(x1), aznumeric_cast<int>(y1))) || b.contains(QPoint(aznumeric_cast<int>(x2), aznumeric_cast<int>(y2))))
            {
                return true;
            }
        }

        // if not test for intersection with the line segments
        // check the top
        if (LinesIntersect(x1, y1, x2, y2, b.topLeft().x(), b.topLeft().y(), b.topRight().x(), b.topRight().y(), outX, outY))
        {
            return true;
        }

        // check the bottom
        if (LinesIntersect(x1, y1, x2, y2, b.bottomLeft().x(), b.bottomLeft().y(), b.bottomRight().x(), b.bottomRight().y(), outX, outY))
        {
            return true;
        }

        // check the left
        if (LinesIntersect(x1, y1, x2, y2, b.topLeft().x(), b.topLeft().y(), b.bottomLeft().x(), b.bottomLeft().y(), outX, outY))
        {
            return true;
        }

        // check the right
        if (LinesIntersect(x1, y1, x2, y2, b.topRight().x(), b.topRight().y(), b.bottomRight().x(), b.bottomRight().y(), outX, outY))
        {
            return true;
        }

        return false;
    }