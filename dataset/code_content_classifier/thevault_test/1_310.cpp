bool PointOnBoundaryOfPolygon(const vector<PT>p, PT q){
    int s=p.size();
    for(int i=0, j=s-1; i<s; j=i++){
        if(PointOnSegment(q, p[j], p[i])) return true;
    }
    return false;
}