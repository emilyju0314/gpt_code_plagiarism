double ComputeSignedArea(const vector<PT>p){
    double area=0.0;
    for(int i=0; i<p.size(); i++){
        int j=(i+1)%p.size();
        area+=p[i].x*p[j].y-p[j].x*p[i].y;
    }
    return area/2.0;
}