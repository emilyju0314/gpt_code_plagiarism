bool PointOnSeg(struct Segment S, struct Point P){
    long long x = P.x, y = P.y, x1 = S.P1.x, y1 = S.P1.y, x2 = S.P2.x, y2 = S.P2.y;
    long long a = x - x1, b = y - y1, c = x2 - x1, d = y2 - y1, dot = (a * c) + (b * d), len = (c * c) + (d * d);

    if (x1 == x2 && y1 == y2) return (x1 == x && y1 == y);
    if (dot < 0 || dot > len) return false;
    return ((((x1 * len) + (dot * c)) == (x * len)) && (((y1 * len) + (dot * d)) == (y * len)));
}