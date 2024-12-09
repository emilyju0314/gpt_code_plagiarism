double dis(struct Segment S, struct Point P){
    double p, xx, yy;
    long long x = P.x, y = P.y, x1 = S.P1.x, y1 = S.P1.y, x2 = S.P2.x, y2 = S.P2.y;
    long long a = x - x1, b = y - y1, c = x2 - x1, d = y2 - y1, dot = (a * c) + (b * d), len = (c * c) + (d * d);

    if ((dot < 0) || (x1 == x2 && y1 == y2)) xx = x1, yy = y1;
    else if (dot > len) xx = x2, yy = y2;
    else p = (1.0 * dot) / len, xx = x1 + (p * c), yy = y1 + (p * d);
    xx = -xx + x, yy = -yy + y;
    return sqrt((xx * xx) + (yy * yy));
}