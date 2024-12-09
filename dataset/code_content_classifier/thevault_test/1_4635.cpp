Circle circleFrom3Points(const Point A, const Point B, const Point C)
{
    Line AB = perpendicularBisector(A, B);
    Line BC = perpendicularBisector(B, C);

    Point center = lineToLineIntersection(AB, BC);
    double radius = dist(center, B);

    return {center, radius};
}