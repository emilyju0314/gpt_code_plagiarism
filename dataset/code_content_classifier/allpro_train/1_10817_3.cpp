#include<bits/stdc++.h>
#define inf 1<<29
#define linf 1e18
#define eps (1e-10)
#define mod 1000000007
#define pi M_PI
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define pd(a) printf("%.10f\n",(double)(a))
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(a)-1;(b)<=i;i--)
#define equals(a,b) (fabs((a)-(b))<eps)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<double,int> pdi;
typedef vector<int> vi;
typedef vector<pii> vpi;
const int dx[8]={1,0,-1,0,1,1,-1,-1};
const int dy[8]={0,1,0,-1,1,-1,1,-1};

class Point{
public:
  double x,y;
  Point(double x=0,double y=0):x(x),y(y){}

  Point operator+(Point p){ return Point(x+p.x,y+p.y);}
  Point operator-(Point p){ return Point(x-p.x,y-p.y);}
  Point operator*(double k){ return Point(x*k,y*k);}
  Point operator/(double k){ return Point(x/k,y/k);}
  bool operator<(Point p)const{ return (x!=p.x ? x<p.x : y<p.y);}
  bool operator==(Point p)const{ return fabs(x-p.x)<eps && fabs(y-p.y)<eps;}

  double abs(){ return sqrt(norm());}
  double norm(){ return (x*x+y*y);}
};
typedef Point Vector;
typedef vector<Point> Polygon;

class Segment{
public:
  Point p1,p2;
  Segment(Point p1=Point(),Point p2=Point()):p1(p1),p2(p2){}
};
typedef Segment Line;

class Circle{
public:
  Point c;
  double r;
  Circle(Point c=Point(),double r=0.0):c(c),r(r){}
};

double norm(Vector a){ return (a.x*a.x+a.y*a.y);}
double abs(Vector a){ return sqrt(norm(a));}
double dot(Vector a,Vector b){ return (a.x*b.x+a.y*b.y);}
double cross(Vector a,Vector b){ return (a.x*b.y-a.y*b.x);}

bool in(Circle c,Point p){
  if(abs(c.c-p)-c.r<-eps)return true;
  return false;
}

Point project(Segment s,Point p){
  Vector base=(s.p2-s.p1);
  double r=(dot(p-s.p1,base)/base.norm());
  return (s.p1+base*r);
}

int ccw(Point p0,Point p1,Point p2){
  Vector a=p1-p0;
  Vector b=p2-p0;
  if(cross(a,b)>eps)return 1;
  if(cross(a,b)<-eps)return -1;
  if(dot(a,b)<-eps)return 2;
  if(a.norm()<b.norm())return -2;
  return 0;
}

double getDistanceLP(Line l,Point p){
  return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));
}

double getDistanceSP(Segment s,Point p){
  if(dot(s.p2-s.p1,p-s.p1)<0.0)return abs(p-s.p1);
  if(dot(s.p1-s.p2,p-s.p2)<0.0)return abs(p-s.p2);
  return getDistanceLP(s,p);
}

bool intersect(Circle c,Segment s){
  if(getDistanceSP(s,c.c)-c.r<-eps)return true;
  return false;
}

double getAngle(Vector a,Vector b){
  double tmp=dot(a,b)/(abs(a)*abs(b));
  if(tmp<-1.0)tmp=-1.0;
  if(1.0<tmp)tmp=1.0;
  double r=acos(tmp)*180.0/pi;
  if(cross(a,b)<-eps)r=360.0-r;
  return r;
}

pair<Point,Point> getCrossPoints(Circle c,Line l){
  Vector pr=project(l,c.c);
  Vector e=(l.p2-l.p1)/abs(l.p2-l.p1);
  double base=sqrt(c.r*c.r-norm(pr-c.c));
  return mp(pr+e*base,pr-e*base);
}

vector<Point> getCrossPointSC(Circle c,Segment s){
  vector<Point> res;
  pair<Point,Point> pp=getCrossPoints(c,s);
  if(ccw(s.p1,s.p2,pp.f)==0)res.push_back(pp.f);
  if(ccw(s.p1,s.p2,pp.s)==0)res.push_back(pp.s);
  return res;
}

double getCommonAreaTC(Point a,Point b,Circle c){
  double res=cross(a-c.c,b-c.c)/2.0;
  bool flag=true;
  if(res<0.0){
    swap(a,b);
    res=-res;
    flag=false;
  }
  if(ccw(a,b,c.c)==0 || ccw(a,b,c.c)==2 || ccw(a,b,c.c)==-2)return 0;
  if(in(c,a) && in(c,b));
  else if(in(c,a) && !in(c,b)){
    vector<Point> vp1=getCrossPointSC(c,Segment(b,a));
    vector<Point> vp2=getCrossPointSC(c,Segment(b,c.c)); 
    res+=(c.r*c.r*pi)*(getAngle(vp1[0]-c.c,vp2[0]-c.c)/360.0);
    res-=cross(vp1[0]-c.c,vp2[0]-c.c)/2.0;
    res-=cross(vp2[0]-b,vp1[0]-b)/2.0;
  }
  else if(!in(c,a) && in(c,b)){
    vector<Point> vp1=getCrossPointSC(c,Segment(a,c.c));
    vector<Point> vp2=getCrossPointSC(c,Segment(a,b));
    res+=(c.r*c.r*pi)*(getAngle(vp1[0]-c.c,vp2[0]-c.c)/360.0);
    res-=cross(vp1[0]-c.c,vp2[0]-c.c)/2.0;
    res-=cross(vp2[0]-a,vp1[0]-a)/2.0;
  }
  else {
    if(intersect(c,Segment(a,b))){
      Point m=b+(a-b)/2.0;
      res=getCommonAreaTC(a,m,c)+getCommonAreaTC(m,b,c);
    }
    else {
      vector<Point> vp1=getCrossPointSC(c,Segment(a,c.c));
      vector<Point> vp2=getCrossPointSC(c,Segment(b,c.c));
      res=(c.r*c.r*pi)*(getAngle(vp1[0]-c.c,vp2[0]-c.c)/360.0);
    }
  }
  if(flag)return res;
  return -res;
}

double getCommonAreaPC(Polygon p,Circle c){
  double res=0.0;
  int n=p.size();
  FOR(i,0,n)res+=getCommonAreaTC(p[i],p[(i+1)%n],c);
  return res;
}

int main()
{

  int n,x,y,r,m,score;
  Circle c;
  vector<pair<Polygon,int> > vp;
  
  cin>>n>>c.c.x>>c.c.y>>c.r;

  for(int i=0;i<n;i++){
    cin>>m>>score;
    Polygon p;
    for(int j=0;j<m;j++){
      cin>>x>>y;
      p.push_back(Point(x,y));
    }
    vp.push_back(mp(p,score));
  }
  double area=(c.r*c.r*pi),ans=0.0;
  
  for(int i=0;i<n;i++){
    ans+=getCommonAreaPC(vp[i].f,c)*vp[i].s/area;
  }

  pd(ans);
  return 0;
}
