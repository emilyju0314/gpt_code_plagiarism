#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}



#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b)) < EPS)
#define PI 3.141592653589793238
 
// COUNTER CLOCKWISE
static const Int CCW_COUNTER_CLOCKWISE = 1;
static const Int CCW_CLOCKWISE = -1;
static const Int CCW_ONLINE_BACK = 2;
static const Int CCW_ONLINE_FRONT = -2;
static const Int CCW_ON_SEGMENT = 0;

struct Point{
  double x,y;
  Point(){}
  Point(double x,double y) :x(x),y(y){}
  Point operator+(Point p) {return Point(x+p.x,y+p.y);}
  Point operator-(Point p) {return Point(x-p.x,y-p.y);}
  Point operator*(double k){return Point(x*k,y*k);}
  Point operator/(double k){return Point(x/k,y/k);}
  double norm(){return x*x+y*y;}
  double abs(){return sqrt(norm());}

  bool operator < (const Point &p) const{
    return x!=p.x?x<p.x:y<p.y;
    //grid-point only
    //return !equals(x,p.x)?x<p.x:!equals(y,p.y)?y<p.y:0;
  }

  bool operator == (const Point &p) const{
    return fabs(x-p.x)<EPS && fabs(y-p.y)<EPS;
  }
};

struct EndPoint{
  Point p;
  Int seg,st;
  EndPoint(){}
  EndPoint(Point p,Int seg,Int st):p(p),seg(seg),st(st){}
  bool operator<(const EndPoint &ep)const{
    if(p.y==ep.p.y) return st<ep.st;
    return p.y<ep.p.y;
  }
};

istream &operator >> (istream &is,Point &p){
  is>>p.x>>p.y;
  return is;
}

ostream &operator << (ostream &os,Point p){
  os<<fixed<<setprecision(12)<<p.x<<" "<<p.y;
  return os;
}

bool sort_x(Point a,Point b){
  return a.x!=b.x?a.x<b.x:a.y<b.y;
}

bool sort_y(Point a,Point b){
  return a.y!=b.y?a.y<b.y:a.x<b.x;
}

typedef Point Vector;
typedef vector<Point> Polygon;

istream &operator >> (istream &is,Polygon &p){
  for(Int i=0;i<(Int)p.size();i++) is>>p[i];
  return is;
}

struct Segment{
  Point p1,p2;
  Segment(){}
  Segment(Point p1, Point p2):p1(p1),p2(p2){}
};
typedef Segment Line;

istream &operator >> (istream &is,Segment &s){
  is>>s.p1>>s.p2;
  return is;
}

double norm(Vector a){
  return a.x*a.x+a.y*a.y;
}
double abs(Vector a){
  return sqrt(norm(a));
}
double dot(Vector a,Vector b){
  return a.x*b.x+a.y*b.y;
}
double cross(Vector a,Vector b){
  return a.x*b.y-a.y*b.x;
}

Point orth(Point p){return Point(-p.y,p.x);}

Point project(Segment s,Point p){
  Vector base=s.p2-s.p1;
  double r=dot(p-s.p1,base)/norm(base);
  return s.p1+base*r;
}

Point reflect(Segment s,Point p){
  return p+(project(s,p)-p)*2.0;
}

double arg(Vector p){
  return atan2(p.y,p.x);
}

Vector polar(double a,double r){
  return Point(cos(r)*a,sin(r)*a);
}

Int ccw(Point p0,Point p1,Point p2){
  Vector a = p1-p0;
  Vector b = p2-p0;
  if(cross(a,b) > EPS) return CCW_COUNTER_CLOCKWISE;
  if(cross(a,b) < -EPS) return CCW_CLOCKWISE;
  if(dot(a,b) < -EPS) return CCW_ONLINE_BACK;
  if(a.norm()<b.norm()) return CCW_ONLINE_FRONT;
  return CCW_ON_SEGMENT;
}

bool intersectSS(Point p1,Point p2,Point p3,Point p4){
  return (ccw(p1,p2,p3)*ccw(p1,p2,p4) <= 0 &&
          ccw(p3,p4,p1)*ccw(p3,p4,p2) <= 0 );
}

bool intersectSS(Segment s1,Segment s2){
  return intersectSS(s1.p1,s1.p2,s2.p1,s2.p2);
}

bool intersectPS(Polygon p,Segment l){
  Int n=p.size();
  for(Int i=0;i<n;i++)
    if(intersectSS(Segment(p[i],p[(i+1)%n]),l)) return 1;
  return 0;
}

double getDistanceLP(Line l,Point p){
  return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));
}

double getDistanceSP(Segment s,Point p){
  if(dot(s.p2-s.p1,p-s.p1) < 0.0 ) return abs(p-s.p1);
  if(dot(s.p1-s.p2,p-s.p2) < 0.0 ) return abs(p-s.p2);
  return getDistanceLP(s,p);
}

double getDistanceSS(Segment s1,Segment s2){
  if(intersectSS(s1,s2)) return 0.0;
  return min(min(getDistanceSP(s1,s2.p1),getDistanceSP(s1,s2.p2)),
             min(getDistanceSP(s2,s1.p1),getDistanceSP(s2,s1.p2)));
}

Point getCrossPointSS(Segment s1,Segment s2){
  for(Int k=0;k<2;k++){
    if(getDistanceSP(s1,s2.p1)<EPS) return s2.p1; 
    if(getDistanceSP(s1,s2.p2)<EPS) return s2.p2;
    swap(s1,s2);
  }
  Vector base=s2.p2-s2.p1;
  double d1=abs(cross(base,s1.p1-s2.p1));
  double d2=abs(cross(base,s1.p2-s2.p1));
  double t=d1/(d1+d2);
  return s1.p1+(s1.p2-s1.p1)*t;
}

Point getCrossPointLL(Line l1,Line l2){
  double a=cross(l1.p2-l1.p1,l2.p2-l2.p1);
  double b=cross(l1.p2-l1.p1,l1.p2-l2.p1);
  if(abs(a)<EPS&&abs(b)<EPS) return l2.p1;
  return l2.p1+(l2.p2-l2.p1)*(b/a);
}

// IN:2 ON:1 OUT:0
Int contains(Polygon g,Point p){
  Int n=g.size();
  bool x=false;
  for(Int i=0;i<n;i++){
    Point a=g[i]-p,b=g[(i+1)%n]-p;
    if(fabs(cross(a,b)) < EPS && dot(a,b) < EPS) return 1;
    if(a.y>b.y) swap(a,b);
    if(a.y < EPS && EPS < b.y && cross(a,b) > EPS ) x = !x;
  }
  return (x?2:0);
}

Vector translate(Vector v,double theta){
  Vector res;
  res.x=cos(theta)*v.x-sin(theta)*v.y;
  res.y=sin(theta)*v.x+cos(theta)*v.y;
  return res;
}


struct Precision{
  Precision(){
    cout<<fixed<<setprecision(12);
  }
}precision_beet;

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  Polygon ps(n);
  for(Int i=0;i<n;i++) cin>>ps[i];
  for(Int i=0;i<n;i++) ps.push_back(Point(ps[i]));
  for(Int i=0;i<n;i++) ps.push_back(Point(ps[i]));

  double ans=1e18;
  Int l=n,r=n+1;
  for(Int i=n;i<n+n;i++){
    while(r<i+1) r++;
    double th=arg(ps[i+1]-ps[i]);
    Vector v1=polar(100,th+2*PI/3);
    Vector v2=polar(100,th+4*PI/3);

    Line b(ps[i],ps[i+1]);

    auto calc=
      [&](Int k,Vector v,Int w)->double{
        Point p=getCrossPointLL(b,Line(ps[k],ps[k]+v));
        if(abs(p-ps[i+w])<abs(p-ps[i+!w])) return -1;
        return abs(p-ps[i+w]);        
      };
    
    while(calc(l,v2,1)<0) l++;
    while(calc(l,v2,1)<calc(l-1,v2,1)) l--;
    while(calc(l,v2,1)<calc(l+1,v2,1)) l++;
    while(calc(r,v1,0)<calc(r-1,v1,0)) r--;
    while(calc(r,v1,0)<calc(r+1,v1,0)) r++;

    Point p1=getCrossPointLL(b,Line(ps[r],ps[r]+v1));
    Point p2=getCrossPointLL(b,Line(ps[l],ps[l]+v2));
    chmin(ans,abs(p1-p2));
  }

  cout<<ans<<endl;
  return 0;
}

