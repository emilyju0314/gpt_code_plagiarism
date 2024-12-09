double distToLine(Point p, Point a, Point b, Point &c) {
    // formula: c = a + u * ab
    Vector ap = Vector(a, p), ab = Vector(a, b);
    double u = ap.dot(ab) / (ab.mod()*ab.mod());
    ab.scale(u);
    ab.translate(a);
    c = a;
    return p.dist(c); 
}