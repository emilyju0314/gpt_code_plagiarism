#include<bits/stdc++.h>
using namespace std;
struct Point{
    long long x,y;
    Point():x(0),y(0){}
    Point(long long _x,long long _y):x(_x),y(_y){}
    bool operator<(Point other)const{
        if(x==other.x)return y<other.y;
        return x<other.x;
    }
};
struct Vector{
    long long x,y;
    Vector(long long _x,long long _y):x(_x),y(_y){}
};
Vector to_vector(Point a,Point b){
    return Vector(b.x-a.x,b.y-a.y);
}
long long cross(Vector a,Vector b){
    return (a.x*b.y)-(a.y*b.x);
}
bool ccw(Point a,Point b,Point c){
    return cross(to_vector(a,b),to_vector(a,c))>0;
}
bool collinear(Point a,Point b,Point c){
    return cross(to_vector(a,b),to_vector(a,c))==0;
}
vector<Point> convex_hull(vector<Point> point){
    vector<Point> hull;
    sort(point.begin(),point.end());
    for(int i=0;i<2;i++){
        int start=hull.size();
        for(auto p:point){
            while(hull.size()>=2
                &&!ccw(hull[hull.size()-2],hull[hull.size()-1],p)
                &&!collinear(hull[hull.size()-2],hull[hull.size()-1],p))hull.pop_back();
            hull.push_back(p);
        }
        hull.pop_back();
        reverse(point.begin(),point.end());
    }
    return hull;
}
int n;
int main(){
    scanf("%d",&n);
    assert(n>=3);
    vector<Point> point;
    for(int i=0;i<n;i++){
        long long x,y;
        scanf("%lld %lld",&x,&y);
        point.push_back(Point(x,y));
    }
    vector<Point> hull=convex_hull(point);
    int start=0;
    for(int i=1;i<hull.size();i++){
        if(hull[i].y<hull[start].y||(hull[i].y==hull[start].y&&hull[i].x<hull[start].x))start=i;
    }
    printf("%d\n",hull.size());
    for(int i=start;i<hull.size();i++){
        printf("%lld %lld\n",hull[i].x,hull[i].y);
    }
    for(int i=0;i<start;i++){
        printf("%lld %lld\n",hull[i].x,hull[i].y);
    }
    return 0;
}