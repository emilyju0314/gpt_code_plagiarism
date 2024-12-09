double DistToLineSegment(PT p, PT A, PT B){
    PT c;
    if(dot(B-A,p-A)<eps) return dist2D(p, A);
    if(dot(A-B,p-B)<eps) return dist2D(p, B);
    return DistToLine(p, A, B);
}