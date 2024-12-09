#include<bits/stdc++.h>
#define inf 1<<29
#define linf 1e10L
#define eps (1e-11L)
#define Eps (1e-7L)
#define mod 1000000007
#define pi acos(-1.0)
#define phi (1.0L+sqrtl(5.0L))/2.0L
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define pd(a) printf("%.10Lf\n",(ld)(a))
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(a)-1;(b)<=i;i--)
#define equals(a,b) (fabs((a)-(b))<Eps)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,ld> pid;
typedef pair<ld,int> pdi;
typedef vector<int> vi;
typedef vector<pii> vpi;

class Point{
public:
  ld x,y;
  Point(ld x=0.0L,ld y=0.0L):x(x),y(y){}

  Point operator+(Point p){ return Point(x+p.x,y+p.y);}
  Point operator-(Point p){ return Point(x-p.x,y-p.y);}
  Point operator*(ld k){ return Point(x*k,y*k);}
  Point operator/(ld k){ return Point(x/k,y/k);}
  bool operator<(Point p)const{ 
    return equals(x,p.x) ? y-p.y<-eps : x-p.x<-eps; }
  bool operator==(Point p)const{ 
    return fabs(x-p.x)<eps && fabs(y-p.y)<eps;}

  ld abs(){ return sqrtl(norm());}
  ld norm(){ return (x*x+y*y);}
};
typedef Point Vector;
typedef vector<Point> Polygon;

class Segment{
public:
  Point p1,p2;
  Segment(Point p1=Point(),Point p2=Point()):p1(p1),p2(p2){}
};
typedef Segment Line;

ld norm(Vector a){ return (a.x*a.x+a.y*a.y);}
ld abs(Vector a){ return sqrtl(norm(a));}
ld dot(Vector a,Vector b){ return (a.x*b.x+a.y*b.y);}
ld cross(Vector a,Vector b){ return (a.x*b.y-a.y*b.x);}

Point project(Segment s,Point p){
  Vector base=(s.p2-s.p1);
  ld r=(dot(p-s.p1,base)/base.norm());
  return (s.p1+base*r);
}

bool isParallel(Segment s,Segment t){
  return equals(cross(s.p1-s.p2,t.p1-t.p2),0.0L);
}

Point getCrossPointLL(Line a,Line b){
  ld A=cross(a.p2-a.p1,b.p2-b.p1);
  ld B=cross(a.p2-a.p1,a.p2-b.p1);
  if(abs(A)<eps || abs(B)<eps)return b.p1;
  return b.p1+(b.p2-b.p1)*(B/A);
}

ld getDistanceLP(Line l,Point p){
  return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));
}

bool onLine(Line L,Point p){ return getDistanceLP(L,p)<eps; }

int ccw(Point p0,Point p1,Point p2){
  Vector a=p1-p0;
  Vector b=p2-p0;
  if(!onLine(Line(p0,p1),p2))return (cross(a,b)>eps ? 1:-1);
  if(dot(a,b)<-eps)return 2;
  if(a.norm()<b.norm())return -2;
  return 0;
}

bool onSegment(Segment s,Point p){
  if(!onLine(s,p))return false;
  if(dot(s.p2-s.p1,p-s.p1)<-eps)return false;
  if(dot(s.p1-s.p2,p-s.p2)<-eps)return false;
  return true;
}

ld getPolygonArea(Polygon p){
  ld area=0.0L;
  int n=p.size();
  for(int i=0;i<n;i++)area+=cross(p[i%n],p[(i+1)%n]);
  return area/2.0L;
}

int contains(Polygon g,Point p){
  int n=g.size();
  bool x=false;
  for(int i=0;i<n;i++){
    Vector a=g[i]-p,b=g[(i+1)%n]-p;
    Segment s(g[i],g[(i+1)%n]);
    if(onSegment(s,p))return 1;
    if(a.y>b.y)swap(a,b);
    if(a.y<eps && eps<b.y && cross(a,b)>eps)x=!x;
  }
  if(x)return 2;
  return 0;
}

vector<Polygon> Polygon_cut(Polygon p,Line L){
  vector<Polygon> res;
  vector<vector<int> > g;
  vector<Point> v;
  int n=p.size();
  int ver[p.size()*2];
  fill(ver,ver+p.size()*2,-1);
  for(int i=0;i<n;i++){
    int j=(i+1)%n;
    if(ccw(L.p1,L.p2,p[i])!=-1){
      v.push_back(p[i]);
      ver[v.size()-1]=i;
    }
    Segment s(p[i],p[j]);
    if(isParallel(L,s))continue;
    Point m=getCrossPointLL(s,L);
    if(dot(s.p2-s.p1,m-s.p1)<eps || dot(s.p1-s.p2,m-s.p2)<eps)continue;
    v.push_back(m);
  }

  g.resize(v.size());
  bool onL[v.size()];
  fill(onL,onL+v.size(),false);
  FOR(i,0,v.size())onL[i]=onLine(L,v[i]);
  FOR(i,0,v.size()){
    int j=(i+1)%v.size();
    if(ver[i]+ver[j]==-2)continue;
    if(ver[i]!=-1 && ver[j]!=-1){
      if((ver[i]+1)%n!=ver[j])continue;
      if(onL[i] && onL[j] && dot(L.p2-L.p1,v[j]-v[i])<-eps)continue;
    }
    else if(onL[i] && onL[j])continue;
    g[i].push_back(j);
  }
  
  vector<pair<ld,int> > list;
  for(int i=0;i<v.size();i++)
    if(onLine(L,v[i]))
      list.push_back(make_pair(dot(L.p2-L.p1,v[i]-L.p1),i));
  sort(list.begin(),list.end());
  for(int i=1;i<list.size();i++){
    int a=list[i-1].s,b=list[i].s;
    if(contains(p,v[a]+(v[b]-v[a])/2.0L)==2)g[a].push_back(b);
  }

  reverse(list.begin(),list.end());
  bool used[v.size()];
  fill(used,used+v.size(),false);

  for(int i=0;i<list.size();i++){
    int s=list[i].s,a=-1;
    for(int j=0;j<g[s].size();j++){
      if(used[g[s][j]])continue;
      a=g[s][j];
    }
    if(a==-1)continue;
    Polygon P;

    while(1){
      P.push_back(v[a]);
      if(onL[a] && used[a])break;
      used[a]=true;
      if(a==s)break;
      int b=-1;
      for(int j=0;j<g[a].size();j++){
        b=g[a][j];
        if(onL[b])break;
      }
      if(b==-1){ P.clear();break; }
      a=b;
    }
    if(getPolygonArea(P)>eps)res.push_back(P);
  }
  
  return res;
}

int n;
Vector v,rv;
Polygon p;

ld cal(Point a){
  ld res=-linf;
  vector<Polygon> vp;
  vp=Polygon_cut(p,Line(a,a+v));
  FOR(i,0,vp.size())res=max(res,getPolygonArea(vp[i]));
  vp=Polygon_cut(p,Line(a+v,a));
  FOR(i,0,vp.size())res=max(res,getPolygonArea(vp[i]));
  if(res==-linf)return linf;
  return res;
}

bool comp(Point a,Point b){ return dot(rv,a)<dot(rv,b); }

ld solve(){
  ld res=linf;
  vector<Point> vp;
  rv.x=-v.y;
  rv.y=v.x;
  FOR(i,0,n)vp.pb(project(Line(Point(),rv),p[i]));
  sort(all(vp),comp);
  FOR(i,1,n){
    Point a=vp[i-1],b=vp[i];
    Vector V=(b-a);
    if(abs(V)<Eps)continue;
    V=V/abs(V);
    ld L=0.0L,R=abs(b-a);
    FOR(k,0,50){
      ld m1=(L*phi+R)/(phi+1.0L);
      ld m2=(L+R*phi)/(phi+1.0L);
      ld res1=cal(a+V*m1);
      ld res2=cal(a+V*m2);
      if(res1<res2)R=m2;
      else L=m1;
      if(equals(L,R))break;
    }
    res=min(res,cal(a+V*L));
  }  
  return res;
}

int main()
{
  while(cin>>n && n){
    cin>>v.x>>v.y;
    p.resize(n);
    FOR(i,0,n)cin>>p[i].x>>p[i].y;
    pd(solve());
  }
  return 0;
}