#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
const double EPS = 1e-8;
const double INF = 1e12;
const double PI = acos(-1);
#define EQ(n,m) (abs((n)-(m)) < EPS)

struct Point{
    double x,y,z;
    Point(double x, double y, double z):x(x), y(y), z(z){}
    Point(){}
    Point &operator +=(const Point &a){ x+=a.x; y+=a.y; z+=a.z; return *this; }
    Point &operator -=(const Point &a){ x-=a.x; y-=a.y; z-=a.z; return *this; }
    Point &operator *=(const double &a){ x*=a; y*=a; z*=a; return *this; }
    Point operator +(const Point &a) const{ return Point(x+a.x, y+a.y, z+a.z); }
    Point operator -(const Point &a) const{ return Point(x-a.x, y-a.y, z-a.z); }
    Point operator *(const double &a) const{ return Point(a*x, a*y, a*z); }
    Point operator -() { return Point(-x, -y, -z); }
};
double dot(const Point &a, const Point &b){
    return a.x*b.x +a.y*b.y +a.z*b.z;
}
Point cross(const Point &a, const Point &b){
    return Point(a.y*b.z -a.z*b.y, a.z*b.x -a.x*b.z, a.x*b.y -a.y*b.x);
}
double abs(const Point &a){
    return sqrt(dot(a, a));
}
Point unit(const Point &a){
    return a *(1/abs(a));
}
double arg2(const Point &a, const Point &b){
    return acos(dot(a, b)/(abs(a)*abs(b)));
}
bool operator ==(const Point &a, const Point &b){
    return abs(a-b) < EPS;
}
bool operator <(const Point &a, const Point &b){
    return !EQ(a.x,b.x)? a.x<b.x: !EQ(a.y,b.y)? a.y<b.y: a.z+EPS<b.z;
}
istream& operator>>(istream& is, Point& p){
    is >> p.x >> p.y >> p.z;
    return is;
}

Point rotate(const Point &p, const Point &axis, double angle){
    Point n = unit(axis);
    double SIN = sin(angle), COS = cos(angle);
    double vec[3] = {p.x, p.y, p.z};
    double mat[3][3] = {{COS +n.x*n.x*(1-COS), n.x*n.y*(1-COS) -n.z*SIN, n.x*n.z*(1-COS) +n.y*SIN},
                        {n.x*n.y*(1-COS) +n.z*SIN, COS +n.y*n.y*(1-COS), n.y*n.z*(1-COS) -n.x*SIN},
                        {n.x*n.z*(1-COS) -n.y*SIN, n.y*n.z*(1-COS) +n.x*SIN, COS +n.z*n.z*(1-COS)}};
    double ret[3] = {};
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            ret[i] += mat[i][j] *vec[j];
        }
    }
    return Point(ret[0], ret[1], ret[2]);
}

vector<Point> trans(vector<Point> p, int ori, int axis){
    Point diff = p[ori];
    double mag = 1/(abs(p[ori]-p[axis]));
    for(auto &v: p){
        v = (v -diff) *mag;
    }
    if(!EQ(p[axis].x, 0) or !EQ(p[axis].y, 0)){
        Point dir = cross(p[axis], Point(0, 0, 1));
        double angle = arg2(p[axis], Point(0, 0, 1));
        for(auto &v: p){
            v = rotate(v, dir, angle);
        }
    }
    if(p[axis].z < 0){
        for(auto &v: p){
            v = rotate(v, Point(1, 0, 0), PI);
        }
    }
    return p;
}
bool spin(vector<Point> &p, int offc){
    if(EQ(p[offc].x, 0) and EQ(p[offc].y, 0)) return false;
    Point v=p[offc]; v.z=0;
    double angle = acos(dot(v, Point(1, 0, 0))/abs(v));
    if(p[offc].y > 0) angle = -angle;
    for(auto &v: p){
        v = rotate(v, Point(0, 0, 1), angle);
    }
    return true;
}
bool check(vector<Point> &v, map<Point, int> &crsp, vector<vector<vector<int>>> &adj){
    int n = adj[0].size();
    for(int i=0; i<n; i++){
        if(crsp.count(v[i]) == 0) return false;
    }
    for(int i=0; i<n; i++){
        vector<int> tmp;
        for(int next: adj[1][i]){
            tmp.push_back(crsp[v[next]]);
        }
        sort(tmp.begin(), tmp.end());
        if(tmp != adj[0][crsp[v[i]]]) return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    vector<vector<Point>> p(2, vector<Point>(n));
    vector<vector<vector<int>>> adj(2, vector<vector<int>>(n));
    for(int d=0; d<2; d++){
        for(int i=0; i<n; i++) cin >> p[d][i];
        for(int i=0; i<n-1; i++){
            int a,b;
            cin >> a >> b;
            a -= n*d +1;
            b -= n*d +1;
            adj[d][a].push_back(b);
            adj[d][b].push_back(a);
        }
    }
    for(int i=0; i<n; i++){
        sort(adj[0][i].begin(), adj[0][i].end());
    }

    int leaf;
    for(leaf=0; leaf<n; leaf++){
        if(adj[0][leaf].size() == 1) break;
    }
    p[0] = trans(p[0], leaf, adj[0][leaf][0]);
    int offc = leaf;
    for(int i=0; i<n; i++){
        if(spin(p[0], i)){
            offc = i;
            break;
        }
    }
    map<Point, int> crsp;
    for(int i=0; i<n; i++){
        crsp[p[0][i]] = i;
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        if(adj[1][i].size() != 1) continue;
        vector<Point> v = trans(p[1], i, adj[1][i][0]);
        for(int j=0; j<n; j++){
            if(!EQ(p[0][offc].z, v[j].z)) continue;
            if(!EQ(abs(p[0][offc]), abs(v[j]))) continue;
            if(!spin(v, j)) continue;
            if(check(v, crsp, adj)) ans++;
        }
        if(offc==leaf and check(v, crsp, adj)){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
