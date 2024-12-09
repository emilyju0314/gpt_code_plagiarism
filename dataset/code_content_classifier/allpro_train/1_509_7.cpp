#include<bits/stdc++.h>
using namespace std;
using Int = long long;


#define EPS (1e-8)
#define equals(a,b) (fabs((a)-(b)) < EPS)
#define PI 3.141592653589793238
 
// COUNTER CLOCKWISE
static const int CCW_COUNTER_CLOCKWISE = 1;
static const int CCW_CLOCKWISE = -1;
static const int CCW_ONLINE_BACK = 2;
static const int CCW_ONLINE_FRONT = -2;
static const int CCW_ON_SEGMENT = 0;

//Intercsect Circle & Circle
static const int ICC_SEPERATE = 4;
static const int ICC_CIRCUMSCRIBE = 3;
static const int ICC_INTERSECT = 2;
static const int ICC_INSCRIBE = 1;
static const int ICC_CONTAIN = 0;

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

istream &operator >> (istream &is,Point &p){
  is>>p.x>>p.y;
  return is;
}

ostream &operator << (ostream &os,Point p){
  os<<fixed<<setprecision(9)<<p.x<<" "<<p.y;
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

struct Circle{
  Point c;
  double r;
  Circle(){}
  Circle(Point c,double r):c(c),r(r){}
};

istream &operator >> (istream &is,Circle &c){
  is>>c.c>>c.r;
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

bool isOrthogonal(Vector a,Vector b){
  return equals(dot(a,b),0.0);
}

bool isOrthogonal(Point a1,Point a2,Point b1,Point b2){
  return isOrthogonal(a1-a2,b1-b2);
}

bool isOrthogonal(Segment s1,Segment s2){
  return equals(dot(s1.p2-s1.p1,s2.p2-s2.p1),0.0);
}

bool isParallel(Vector a,Vector b){
  return equals(cross(a,b),0.0);
}

bool isParallel(Point a1,Point a2,Point b1,Point b2){
  return isParallel(a1-a2,b1-b2);
}

bool isParallel(Segment s1,Segment s2){
  return equals(cross(s1.p2-s1.p1,s2.p2-s2.p1),0.0); 
}

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

int ccw(Point p0,Point p1,Point p2);
bool intersectSS(Point p1,Point p2,Point p3,Point p4);
bool intersectSS(Segment s1,Segment s2);
bool intersectPS(Polygon p,Segment l);
int intersectCC(Circle c1,Circle c2);
bool intersectSC(Segment s,Circle c);
double getDistanceLP(Line l,Point p);
double getDistanceSP(Segment s,Point p);
double getDistanceSS(Segment s1,Segment s2);
Point getCrossPointSS(Segment s1,Segment s2);
Point getCrossPointLL(Line l1,Line l2);
Polygon getCrossPointCL(Circle c,Line l);
Polygon getCrossPointCC(Circle c1,Circle c2);
int contains(Polygon g,Point p);
Polygon andrewScan(Polygon s);
Polygon convex_hull(Polygon ps);
double diameter(Polygon s);
bool isConvex(Polygon p);
double area(Polygon s);
Polygon convexCut(Polygon p,Line l);
Line bisector(Point p1,Point p2);
Vector translate(Vector v,double theta);
vector<Line> corner(Line l1,Line l2);

int ccw(Point p0,Point p1,Point p2){
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
  int n=p.size();
  for(int i=0;i<n;i++)
    if(intersectSS(Segment(p[i],p[(i+1)%n]),l)) return 1;
  return 0;
}

int intersectCC(Circle c1,Circle c2){
  if(c1.r<c2.r) swap(c1,c2);
  double d=abs(c1.c-c2.c);
  double r=c1.r+c2.r;
  if(equals(d,r)) return ICC_CIRCUMSCRIBE;
  if(d>r) return ICC_SEPERATE;
  if(equals(d+c2.r,c1.r)) return ICC_INSCRIBE;
  if(d+c2.r<c1.r) return ICC_CONTAIN;
  return ICC_INTERSECT;
}

bool intersectSC(Segment s,Circle c){
  double d=getDistanceSP(s,c.c);
  return d<=c.r;
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

Polygon getCrossPointCL(Circle c,Line l){
  Polygon p(2);
  Vector pr=project(l,c.c);
  Vector e=(l.p2-l.p1)/abs(l.p2-l.p1);
  double base=sqrt(c.r*c.r-norm(pr-c.c));
  p[0]=pr+e*base;
  p[1]=pr-e*base;
  return p;
}

Polygon getCrossPointCC(Circle c1,Circle c2){
  Polygon p(2);
  double d=abs(c1.c-c2.c);
  double a=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
  double t=arg(c2.c-c1.c);
  p[0]=c1.c+polar(c1.r,t+a);
  p[1]=c1.c+polar(c1.r,t-a);
  return p;
}

// IN:2 ON:1 OUT:0
int contains(Polygon g,Point p){
  int n=g.size();
  bool x=false;
  for(int i=0;i<n;i++){
    Point a=g[i]-p,b=g[(i+1)%n]-p;
    if(fabs(cross(a,b)) < EPS && dot(a,b) < EPS) return 1;
    if(a.y>b.y) swap(a,b);
    if(a.y < EPS && EPS < b.y && cross(a,b) > EPS ) x = !x;
  }
  return (x?2:0);
}

Polygon andrewScan(Polygon s){
  Polygon u,l;
  if(s.size()<3) return s;
  sort(s.begin(),s.end());
  u.push_back(s[0]);
  u.push_back(s[1]);
  l.push_back(s[s.size()-1]);
  l.push_back(s[s.size()-2]);
  for(int i=2;i<(int)s.size();i++){
    for(int n=u.size();n>=2&&ccw(u[n-2],u[n-1],s[i])!=CCW_CLOCKWISE;n--){
      u.pop_back();
    }
    u.push_back(s[i]);
  } 
  for(int i=s.size()-3;i>=0;i--){
    for(int n=l.size();n>=2&&ccw(l[n-2],l[n-1],s[i])!=CCW_CLOCKWISE;n--){
      l.pop_back();
    }
    l.push_back(s[i]);
  }
  reverse(l.begin(),l.end());
  for(int i=u.size()-2;i>=1;i--) l.push_back(u[i]);
  return l;
} 

Polygon convex_hull(Polygon ps){
  int n=ps.size();
  sort(ps.begin(),ps.end(),sort_y);
  int k=0;
  Polygon qs(n*2);
  for(int i=0;i<n;i++){
    while(k>1&&cross(qs[k-1]-qs[k-2],ps[i]-qs[k-1])<0) k--;
    qs[k++]=ps[i];
  }
  for(int i=n-2,t=k;i>=0;i--){
    while(k>t&&cross(qs[k-1]-qs[k-2],ps[i]-qs[k-1])<0) k--;
    qs[k++]=ps[i];
  }
  qs.resize(k-1);
  return qs;
}

double diameter(Polygon s){
  Polygon p=s;
  int n=p.size();
  if(n==2) return abs(p[0]-p[1]);
  int i=0,j=0;
  for(int k=0;k<n;k++){
    if(p[i]<p[k]) i=k;
    if(!(p[j]<p[k])) j=k;
  }
  double res=0;
  int si=i,sj=j;
  while(i!=sj||j!=si){
    res=max(res,abs(p[i]-p[j]));
    if(cross(p[(i+1)%n]-p[i],p[(j+1)%n]-p[j])<0.0){
      i=(i+1)%n;
    }else{
      j=(j+1)%n;
    }
  }
  return res;
}

bool isConvex(Polygon p){
  bool f=1;
  int n=p.size();
  for(int i=0;i<n;i++){
    int t=ccw(p[(i+n-1)%n],p[i],p[(i+1)%n]);
    f&=t!=CCW_CLOCKWISE;
  }
  return f;
}

double area(Polygon s){
  double res=0;
  for(int i=0;i<(int)s.size();i++){
    res+=cross(s[i],s[(i+1)%s.size()])/2.0;
  }
  return abs(res);
}
double area(Circle c1,Circle c2){
  double d=abs(c1.c-c2.c);
  if(c1.r+c2.r<=d+EPS) return 0;
  if(d<=abs(c1.r-c2.r)){
    double r=min(c1.r,c2.r);
    return PI*r*r;
  }
  double rc=(d*d+c1.r*c1.r-c2.r*c2.r)/(2*d);
  double th=acos(rc/c1.r);
  double ph=acos((d-rc)/c2.r);
  return c1.r*c1.r*th+c2.r*c2.r*ph-d*c1.r*sin(th);
}

Polygon convexCut(Polygon p,Line l){
  Polygon q;
  for(int i=0;i<(int)p.size();i++){
    Point a=p[i],b=p[(i+1)%p.size()];
    if(ccw(l.p1,l.p2,a)!=-1) q.push_back(a);
    if(ccw(l.p1,l.p2,a)*ccw(l.p1,l.p2,b)<0)
      q.push_back(getCrossPointLL(Line(a,b),l));
  }
  return q;
}

Line bisector(Point p1,Point p2){
  Circle c1=Circle(p1,abs(p1-p2)),c2=Circle(p2,abs(p1-p2));
  Polygon p=getCrossPointCC(c1,c2);
  if(cross(p2-p1,p[0]-p1)>0) swap(p[0],p[1]);
  return Line(p[0],p[1]);
}

Vector translate(Vector v,double theta){
  Vector res;
  res.x=cos(theta)*v.x-sin(theta)*v.y;
  res.y=sin(theta)*v.x+cos(theta)*v.y;
  return res;
}

vector<Line> corner(Line l1,Line l2){
  vector<Line> res;
  if(isParallel(l1,l2)){
    double d=getDistanceLP(l1,l2.p1)/2.0;
    Vector v1=l1.p2-l1.p1;
    v1=v1/v1.abs()*d;
    Point p=l2.p1+translate(v1,90.0*(PI/180.0));
    double d1=getDistanceLP(l1,p);
    double d2=getDistanceLP(l2,p);
    if(abs(d1-d2)>d){
      p=l2.p1+translate(v1,-90.0*(PI/180.0));
    }
    res.push_back(Line(p,p+v1));
  }else{
    Point p=getCrossPointLL(l1,l2);
    Vector v1=l1.p2-l1.p1,v2=l2.p2-l2.p1;
    v1=v1/v1.abs();
    v2=v2/v2.abs();
    res.push_back(Line(p,p+(v1+v2)));
    res.push_back(Line(p,p+translate(v1+v2,90.0*(PI/180.0))));
  }
  return res;
}

Polygon tangent(Circle c1,Point p2){
  Circle c2=Circle(p2,sqrt(norm(c1.c-p2)-c1.r*c1.r));
  Polygon p=getCrossPointCC(c1,c2);
  sort(p.begin(),p.end());
  return p;
}



signed main(){
  double uw,uh,a,b,ab;
  while(cin>>uw>>uh>>a>>b>>ab,uw!=0){
    Circle c1(Point(0,0),sqrt(a/PI));
    Circle c2(Point(0,0),sqrt(b/PI));
    bool f=0;
    if(c1.r<=c2.r) swap(c1,c2),f=1;
    double l=max(0.0,c1.r-c2.r),r=c1.r+c2.r+EPS;
    for(int k=0;k<100;k++){
      double m=(l+r)/2;
      c2.c.x=m;
      //cout<<area(c1,c2)<<endl;
      if(area(c1,c2)<=ab) r=m;
      else l=m;
    }
    c2.c.x=l;
    
    double EPS3=1e-4;
    assert(abs(area(c1,c2)-ab)<=EPS3);

    l=0,r=PI/2;
    for(int k=0;k<200;k++){
      double m=(l+r)/2;
      Circle t=c2;
      t.c=translate(c2.c,m);
      if(c1.r+max(c1.r,t.c.x+t.r)<=uw) r=m;
      else l=m;
    }
    c2.c=translate(c2.c,r);
    //cout<<c1.c<<"/"<<c2.c<<endl;
    
    Vector v(c1.r,c1.r);
    c1.c=c1.c+v;
    c2.c=c2.c+v;
    
    //cout<<c1.c<<"/"<<c2.c<<endl;

    if(f) swap(c1,c2);
    f=1;
    f&=(c1.c.x-c1.r>=-EPS3);
    f&=(c1.c.x+c1.r<=uw+EPS3);
    f&=(c1.c.y-c1.r>=-EPS3);
    f&=(c1.c.y+c1.r<=uh+EPS3);
    f&=(c2.c.x-c2.r>=-EPS3);
    f&=(c2.c.x+c2.r<=uw+EPS3);
    f&=(c2.c.y-c2.r>=-EPS3);
    f&=(c2.c.y+c2.r<=uh+EPS3);
    if(f) cout<<c1.c<<" "<<c1.r<<" "<<c2.c<<" "<<c2.r<<endl;
    else cout<<"impossible"<<endl;
    //else cout<<c1.c<<" "<<c1.r<<"/"<<c2.c<<" "<<c2.r<<endl;
  }
  return 0;
}