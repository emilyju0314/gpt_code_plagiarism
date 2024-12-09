double DistToLine(PT p, PT A, PT B){
    double scale=dot(p-A,B-A)/dot(B-A,B-A);
    PT c;
    c.x=A.x+scale*(B.x-A.x);
    c.y=A.y+scale*(B.y-A.y);
    return dist2D(p, c);
}