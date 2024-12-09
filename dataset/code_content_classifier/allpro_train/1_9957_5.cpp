#include<bits/stdc++.h>
#define inf 1<<29
#define linf 1e16
#define eps (1e-8)
#define mod 1000000007
#define pi acos(-1)
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
typedef pair<int,double> pid;
typedef pair<double,int> pdi;
typedef vector<int> vi;
typedef vector<pii> vpi;

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

double norm(Vector a){ return (a.x*a.x+a.y*a.y);}
double abs(Vector a){ return sqrt(norm(a));}
double dot(Vector a,Vector b){ return (a.x*b.x+a.y*b.y);}
double cross(Vector a,Vector b){ return (a.x*b.y-a.y*b.x);}

Point project(Segment s,Point p){
  Vector base=(s.p2-s.p1);
  double r=(dot(p-s.p1,base)/base.norm());
  return (s.p1+base*r);
}

Point reflect(Segment s,Point p){
  return p+(project(s,p)-p)*2;
}

Polygon reflect(Line l,Polygon p){
  FOR(i,0,p.size())p[i]=reflect(l,p[i]);
  return p;
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

bool intersect(Line l,Segment s){
  return ccw(l.p1,l.p2,s.p1)*ccw(l.p1,l.p2,s.p2)<0;
}

int n;
Point s;
bool used[10]={};

int check(vector<Segment> vs){
  FOR(i,1,vs.size()){
    FOR(j,0,i){
      if(intersect(Line(s,vs[j].p1),vs[i]))continue;
      if(intersect(Line(s,vs[j].p2),vs[i]))continue;
      if(intersect(Line(s,vs[i].p1),vs[j]))continue;
      if(intersect(Line(s,vs[i].p2),vs[j]))continue;
      return 0;
    }
  }
  return 1;
}

int rec(Polygon p,vector<Segment> vs){
  if(vs.size()==p.size())return check(vs);
  int res = 0;
  FOR(i,0,p.size()){
    if(used[i])continue;
    used[i]=true;
    Segment e(p[i],p[(i+1)%p.size()]);
    vs.pb(e);
    res+=rec(reflect(e,p),vs);
    vs.pop_back();
    used[i]=false;
  }
  return res;
}

int main()
{
  while(cin>>n && n){
    Polygon p;
    vector<Segment> vs;
    cin>>s.x>>s.y;
    FOR(i,0,n){
      int x,y;
      cin>>x>>y;
      p.pb(Point(x,y));
    }
    cout<<rec(p,vs)<<endl;
  }
  return 0;
}