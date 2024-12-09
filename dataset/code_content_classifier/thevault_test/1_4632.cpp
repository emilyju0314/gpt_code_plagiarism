vector<Point> convexHull(vector<Point>& points)
{
    int N = points.size();
    int ind = 0;

    /// basic case
    if (N <= 3)
        return points;

    /// find lowest point (it belongs to the convex hull)
    for (int i = 1; i < N; ++i)
        if (points[i] < points[ind])
            ind = i;

    /// place it on the first position
    swap(points[0], points[ind]);

    /// sort points, using the lowset one, in counter-clockwise order (using c++ lambda)
    sort(points.begin() + 1, points.end(),
        [&](const Point A, const Point B) -> bool
         {
             return CCW(points[0], A, B) < 0;
         }
    );

    /// works as a stack
    vector<Point> hull(N);
    int dim = 0;

    for (int i = 0; i < N; ++i)
    {
        while (dim >= 2 && CCW(hull[dim - 2], hull[dim - 1], points[i]) >= 0) ///clockwise turn
            dim--;

        hull[dim++] = points[i];
    }

    hull.resize(dim);

    return hull;
}