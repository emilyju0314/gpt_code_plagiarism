double cal_arc_(PT p1,PT p2,double r){
    double A = dist2D_sqr(p1,p2);
    double B = dist2D_sqr(p1,PT(0.0,0.0));
    double C = dist2D_sqr(p2,PT(0.0,0.0));
    double ang = acos((B+C-A)/(2.0*sqrt(B*C)));
    return r*ang;
}