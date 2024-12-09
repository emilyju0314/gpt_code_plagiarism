#include <iostream>
#include <complex>
#include <utility>
#include <vector>
using namespace std;

typedef complex<double> Point, Vector;
typedef pair<Point, Point> Segment, Line;
typedef vector<Point> Polygon;

#define X real()
#define Y imag()
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

double dot(Vector a, Vector b){
    return a.X * b.X + a.Y * b.Y;
}

double cross(Vector a, Vector b){
    return a.X * b.Y - a.Y * b.X;
}

double norm(Vector a){
    return a.X * a.X + a.Y * a.Y;
}

double abs(Vector a){
    return sqrt(norm(a));
}

int contains(Polygon g, Point p){
    int n = g.size();
    bool x = false;
    for(int i=0; i<n; i++){
        Point a = g[i] - p;
        Point b = g[(i + 1) % n] - p;
        if(abs(cross(a, b)) < EPS && dot(a, b) < EPS) return 1;
        if(a.Y > b.Y) swap(a, b);
        if(a.Y < EPS && EPS < b.Y && cross(a, b) > EPS) x = !x;
    }

    return (x ? 2 : 0);
}

int main(){
    int g; cin>>g;
    Polygon poly;
    for(int i=0; i<g; i++){
        double a, b; cin>>a>>b;
        poly.emplace_back(a, b);
    }

    int n; cin>>n;
    for(int i=0; i<n; i++){
        double a, b; cin>>a>>b;
        Point p1 = {a, b};

        cout << contains(poly, p1) << endl;
    }
}
