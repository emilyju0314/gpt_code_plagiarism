double dist_point_seg(Point& a, Point& b, Point& p) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;

    double s = dx*dx + dy*dy;

    double u = ((p.x - a.x) * dx + (p.y - a.y) * dy) / s;
    
    if(u > 1) {
        u = 1;
    } else if(u < 0) {
        u = 0;
    }

    double x1 = a.x + u * dx;
    double y1 = a.y + u * dy;

    double x2 = x1 - p.x;
    double y2 = y1 - p.y;

    return sqrt(x2*x2 + y2*y2);
}