bool circle_3pts(Point p1, Point p2, Point p3, Point& c, double& rad) {
    Line r(p1, p2), s(p2, p3);
 
    double m1 = -1. / r.a, m2 = -1. / s.a;
    Point med1 = (p1 + p2) / 2.;
    Point med2 = (p2 + p3) / 2.;
    Line r1(med1, m1), s1(med2, m2);
 
    if(!r1.intersect(s1, c)) return false;
 
    rad = c.dist(p1);
    return true;
}