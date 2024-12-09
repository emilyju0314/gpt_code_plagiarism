bool isInside(vector<Point> polygon, int n, Point p)
{
    // There must be at least 3 vertices in polygon[]
    if (n < 3)  return false;

    // Create a point for line segment from p to infinite
    Point extreme = {INF, p.y};

    // Count intersections of the above line with sides of polygon
    int count = 0, i = 0;
    do
    {
        if (doIntersect(polygon[i], polygon[(i+1)%n], p, extreme))
        {
            if (onSegment(polygon[i], p, polygon[(i+1)%n]))
                return true;
            count++;
        }
        i = (i + 1)%n;
    } while (i != 0);

    // Return true if count is odd, false otherwise
    return count&1;  // Same as (count%2 == 1)
}