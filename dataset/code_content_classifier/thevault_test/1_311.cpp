bool PointInPolygon(const vector<PT>p, PT q){
    bool c=0;
    int s=p.size();
    for(int i=0,j=s-1; i<s; j=i++){
        if(((p[i].y>q.y)!=(p[j].y>q.y))&&(q.x<p[i].x+(p[j].x-p[i].x)*(q.y-p[i].y)/(p[j].y-p[i].y))) c=!c;
    }
    return c;
}