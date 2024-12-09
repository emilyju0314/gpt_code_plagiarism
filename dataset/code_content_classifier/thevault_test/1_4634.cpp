double signedArea(vector<Point>& points)
{
    double area = 0;
    int N = points.size();

    for (int i = 0; i < N; ++i)
        area += (points[i].x * points[(i + 1) % N].y - points[(i + 1) % N].x * points[i].y);

    return area / 2.0;
}