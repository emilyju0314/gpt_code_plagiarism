#include<bits/stdc++.h>
#define MAX 30
#define inf 1<<29
#define linf 1e16
#define eps (1e-8)
#define Eps (1e-15)
#define mod 1000000007
#define pi acos(-1)
#define phi (1.0+sqrt(5))/2.0
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
typedef pair<double,double> pdd;
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
  bool operator<(Point p)const{ return equals(x,p.x) ? y-p.y<-eps : x-p.x<-eps; }
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

bool isParallel(Vector a,Vector b){
  return equals(cross(a,b),0.0);
}

bool isParallel(Segment s,Segment t){
  return equals(cross(s.p1-s.p2,t.p1-t.p2),0.0);
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

bool intersect(Point p1,Point p2,Point p3,Point p4){
  return (ccw(p1,p2,p3)*ccw(p1,p2,p4)<=0 &&
          ccw(p3,p4,p1)*ccw(p3,p4,p2)<=0);
}

bool intersect(Segment s1,Segment s2){
  return intersect(s1.p1,s1.p2,s2.p1,s2.p2);
}

Point getCrossPointLL(Line a,Line b){
  double A=cross(a.p2-a.p1,b.p2-b.p1);
  double B=cross(a.p2-a.p1,a.p2-b.p1);
  if(abs(A)<eps || abs(B)<eps)return b.p1;
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

bool contains(Polygon p,Segment s){
  vector<pair<double,Point> > v;
  int n=p.size();
  v.push_back(make_pair(0,s.p1));
  v.push_back(make_pair(abs(s.p1-s.p2),s.p2));
  for(int i=0;i<n;i++){
    Segment e(p[i],p[(i+1)%n]);
    if(isParallel(s,e))continue;
    if(!intersect(s,e))continue;
    Point m=getCrossPointLL(s,e);
    v.push_back(make_pair(abs(m-s.p1),m));
  }
  sort(v.begin(),v.end());
  for(int i=0;i<v.size()-1;i++){
    Point m=v[i].s+(v[i+1].s-v[i].s)/2.0;
    if(contains(p,m)==0)return false;
  }
  return true;
}

pair<Point,Point> closest_pair(Segment a,Segment b){
  pair<Point,Point> res(a.p1,b.p1);
  if(abs(a.p1-b.p2)<abs(res.f-res.s))res=mp(a.p1,b.p2);
  if(abs(a.p2-b.p1)<abs(res.f-res.s))res=mp(a.p2,b.p1);
  if(abs(a.p2-b.p2)<abs(res.f-res.s))res=mp(a.p2,b.p2);
  Point c;
  c=project(b,a.p1);
  if(ccw(b.p1,b.p2,c)==0 &&
     abs(c-a.p1)<abs(res.f-res.s))res=mp(a.p1,c);
  c=project(b,a.p2);
  if(ccw(b.p1,b.p2,c)==0 &&
     abs(c-a.p2)<abs(res.f-res.s))res=mp(a.p2,c);
  c=project(a,b.p1);
  if(ccw(a.p1,a.p2,c)==0 &&
     abs(c-b.p1)<abs(res.f-res.s))res=mp(b.p1,c);
  c=project(a,b.p2);
  if(ccw(a.p1,a.p2,c)==0 &&
     abs(c-b.p2)<abs(res.f-res.s))res=mp(b.p2,c);
  return res;
}

int n,m;
Point s,t;
vector<Point> w,e;
Polygon W,E,WE;
vector<Point> vp[2];
vector<pid> g[2][MAX];

void add_edge(int ind,int to,int from,double cost){
  g[ind][to].pb(mp(from,cost));
  g[ind][from].pb(mp(to,cost));
}

double dijkstra(Point a){
  int ind=-1;
  Polygon p;
  if(contains(W,a)){ ind=0;p=W; }
  else { ind=1;p=E; }
  int start=vp[ind].size();
  g[ind][start].clear();
  FOR(i,0,vp[ind].size())
    if(contains(p,Segment(vp[ind][i],a)))
       g[ind][start].pb(mp(i,abs(a-vp[ind][i])));

  double d[MAX];
  priority_queue<pdi,vector<pdi>,greater<pdi> > pq;
  fill(d,d+MAX,inf);
  d[start]=0;
  pq.push(mp(0,start));

  while(pq.size()){
    pdi u=pq.top();
    pq.pop();

    if(d[u.s]<u.f)continue;
    if(u.s==0)return d[u.s];

    FOR(i,0,g[ind][u.s].size()){
      int next=g[ind][u.s][i].f;
      double cost=g[ind][u.s][i].s+d[u.s];
      if(cost<d[next]){
        d[next]=cost;
        pq.push(mp(cost,next));
      }
    }
  }
  return inf;
}

void make_graphs(){
  W.pb(Point(0,1000));
  W.pb(Point(0,0));
  FOR(i,0,n)W.pb(w[i]);
  E.pb(Point(1000,0));
  E.pb(Point(1000,1000));
  RFOR(i,m,0)E.pb(e[i]);

  vp[0].pb(s);
  FOR(i,0,W.size())vp[0].pb(W[i]);
  FOR(i,0,vp[0].size()){
    FOR(j,i+1,vp[0].size()){
      if(contains(W,Segment(vp[0][i],vp[0][j])))
        add_edge(0,i,j,abs(vp[0][i]-vp[0][j]));
    }
  }
  vp[1].pb(t);
  FOR(i,0,E.size())vp[1].pb(E[i]);
  FOR(i,0,vp[1].size()){
    FOR(j,i+1,vp[1].size()){
      if(contains(E,Segment(vp[1][i],vp[1][j])))
        add_edge(1,i,j,abs(vp[1][i]-vp[1][j]));
    }
  }
}

pdd check(Segment a,Segment b){
  pdd res(inf,inf);
  if(isParallel(a,b)){
    Segment seg=a;
    Point c;
    bool flag=false;
    c=project(a,b.p1);
    if(ccw(seg.p1,seg.p2,c)==0){ seg.p1=c;flag=true; }
    c=project(a,b.p2);
    if(ccw(seg.p1,seg.p2,c)==0){ seg.p2=c;flag=true; }
    if(flag){
      Vector v=seg.p2-seg.p1;
      v=v/abs(v);
      double L=0,R=abs(seg.p1-seg.p2);
      FOR(k,0,50){
        double m1=(L*phi+R)/(1.0+phi);
        double m2=(L+R*phi)/(1.0+phi);
        Point p1,p2;
        p1=seg.p1+v*m1;
        p2=project(b,p1);
        double res1=dijkstra(p1)+dijkstra(p2);
        p1=seg.p1+v*m2;
        p2=project(b,p1);
        double res2=dijkstra(p1)+dijkstra(p2);
        if(res1<res2)R=m2;
        else L=m1;
      }
      Point p1=seg.p1+v*L,p2=project(b,p1);
      res.f=abs(p1-p2);
      res.s=dijkstra(seg.p1+v*L)+dijkstra(project(b,seg.p1+v*L));
      return res;
    }
  }
  pair<Point,Point> pp=closest_pair(a,b);
  res.f=abs(pp.f-pp.s);
  res.s=dijkstra(pp.f)+dijkstra(pp.s);
  return res;
}

bool comp(pdd a,pdd b){
  return fabs((a.f)-(b.f))<Eps ? b.s-a.s<-Eps : b.f-a.f<-Eps;
}

void solve(){
  make_graphs();
  pdd res(inf,inf);
  FOR(i,0,n-1){
    Segment s1(w[i],w[i+1]);
    FOR(j,0,m-1){
      Segment s2(e[j],e[j+1]);
      pdd tmp=check(s1,s2);
      if(comp(res,tmp))res=tmp;
    }
  }
  printf("%.10f %.10f\n",res.f,res.f+res.s);
}

int main()
{
  cin>>s.x>>s.y>>t.x>>t.y;
  cin>>n;
  w.resize(n);
  FOR(i,0,n)cin>>w[i].x>>w[i].y;
  cin>>m;
  e.resize(m);
  FOR(i,0,m)cin>>e[i].x>>e[i].y;
  solve();
  return 0;
}