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
  bool operator==(Point p)const{ return fabs(x-p.x)<eps && fabs(y-p.y)<eps; }
  bool operator<(Point p)const{ 
    return equals(x,p.x) ? y-p.y<-eps : x-p.x<-eps; }
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

bool isParallel(Vector a,Vector b){
  return equals(cross(a,b),0.0);
}

bool isParallel(Segment s,Segment t){
  return equals(cross(s.p1-s.p2,t.p1-t.p2),0.0);
}

bool intersect(Line L,Segment s){
  return cross(L.p2-L.p1,s.p1-L.p1)*cross(L.p2-L.p1,s.p2-L.p1)<eps;
}

Point getCrossPointLL(Line a,Line b){
  double A=cross(a.p2-a.p1,b.p2-b.p1);
  double B=cross(a.p2-a.p1,a.p2-b.p1);
  if(abs(A)<eps)return b.p1;
  return b.p1+(b.p2-b.p1)*(B/A);
}

int contains(Polygon g,Point p){
  int n=g.size();
  bool x=false;
  for(int i=0;i<n;i++){
    Vector a=g[i]-p,b=g[(i+1)%n]-p;
    if(abs(cross(a,b))<eps && dot(a,b)<eps)return 1;
    if(a.y>b.y)swap(a,b);
    if(a.y<eps && eps<b.y && cross(a,b)>eps)x=!x;
  }
  if(x)return 2;
  return 0;
}

int n;
Polygon p;

double cal(Line L){
  vector<Point> vp;
  FOR(i,0,n){
    Segment s(p[i],p[(i+1)%n]);
    if(isParallel(L,s))continue;
    if(!intersect(L,s))continue;
    vp.pb(getCrossPointLL(L,s));
  }
  sort(all(vp));
  vp.erase(unique(all(vp)),vp.end());
  double sum=0,res=0;
  FOR(i,0,vp.size()-1){
    Point a=vp[i],b=vp[i+1];
    if(a==b)continue;
    Point m=a+(b-a)/2.0;
    if(contains(p,m)==0)sum=0;
    else { sum+=abs(b-a); res=max(res,sum); }
  }
  return res;
}

double solve(){
  double res=0;
  FOR(i,0,n){
    FOR(j,i+1,n)res=max(res,cal(Line(p[i],p[j])));
  }
  return res;
}

int main()
{
  int c=1;
  while(cin>>n && n){
    p.clear();
    FOR(i,0,n){
      double x,y;
      cin>>x>>y;
      p.pb(Point(x,y));
    }
    cout<<"Case "<<c<<": "; pd(solve());
    c++;
  }
  return 0;
}