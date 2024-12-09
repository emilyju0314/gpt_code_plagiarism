#include<bits/stdc++.h>
#define MAX 100
#define inf 1<<29
#define linf 1e16
#define eps (1e-10)
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
  bool operator<(Point p)const{ 
    return (!equals(x,p.x) ? x-p.x<-eps : y-p.y<-eps);}
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

int ccw(Point p0,Point p1,Point p2){
  Vector a=p1-p0;
  Vector b=p2-p0;
  if(cross(a,b)>eps)return 1;
  if(cross(a,b)<-eps)return -1;
  if(dot(a,b)<-eps)return 2;
  if(a.norm()<b.norm())return -2;
  return 0;
}

int n;
double tg,tw;
Polygon p;
vector<Point> vp;
vector<pid> g[MAX];
Point s,t;
int S,T;

void init(){
  p.clear();
  vp.clear();
  FOR(i,0,MAX)g[i].clear();
}

Point getPoint(Point a,Point b,Point c){
  Vector v=b-a;
  v=v/abs(v);
  double L=0.0,R=abs(b-a);
  FOR(i,0,50){
    double m1=(L+L+R)/3.0;
    double m2=(L+R+R)/3.0;
    double res1=(abs(v*m1))*tg+abs(a+v*m1-c)*tw;
    double res2=(abs(v*m2))*tg+abs(a+v*m2-c)*tw;
    if(res1-res2<-eps)R=m2;
    else L=m1;
  }
  return a+v*L;
}

double dijkstra(){
  double d[MAX];
  priority_queue<pdi,vector<pdi>,greater<pdi> > pq;
  fill(d,d+MAX,inf);
  d[S]=0;
  pq.push(mp(0,S));

  while(pq.size()){
    pdi u=pq.top();
    pq.pop();
    if(d[u.s]-u.f<-eps)continue;
    if(u.s==T)return d[u.s];

    FOR(i,0,g[u.s].size()){
      int next=g[u.s][i].f;
      double cost=d[u.s]+g[u.s][i].s;
      if(cost-d[next]<-eps){
        d[next]=cost;
        pq.push(mp(cost,next));
      }
    }
  }
  return inf;
}

double solve(){
  FOR(i,0,n){
    vp.pb(getPoint(p[i],p[(i+1)%n],s));
    vp.pb(getPoint(p[i],p[(i+1)%n],t));
    vp.pb(getPoint(p[(i+1)%n],p[i],s));
    vp.pb(getPoint(p[(i+1)%n],p[i],t));
  }
  vp.pb(s);
  FOR(i,0,n){
    Segment s(p[i],p[(i+1)%n]);
    vector<pdi> list;
    FOR(j,0,vp.size()){
      if(ccw(s.p1,s.p2,vp[j])==0)list.pb(mp(abs(s.p1-vp[j]),j));
    }
    sort(all(list));
    FOR(j,0,list.size()-1){
      int a=list[j].s,b=list[j+1].s;
      g[a].pb(mp(b,abs(vp[a]-vp[b])*tg));
      g[b].pb(mp(a,abs(vp[a]-vp[b])*tg));
    }
  }
  vp.pb(t);
  FOR(i,0,vp.size()){
    if(vp[i]==s)S=i;
    if(vp[i]==t)T=i;
  }
  FOR(i,0,vp.size())if(i!=T)g[i].pb(mp(T,abs(vp[i]-t)*tw));
  FOR(i,0,vp.size())if(i!=S)g[S].pb(mp(i,abs(vp[i]-s)*tw));

  return dijkstra();
}

int main()
{
  while(cin>>n && n){
    init();
    FOR(i,0,n){
      int x,y;
      cin>>x>>y;
      p.pb(Point(x,y));
      vp.pb(Point(x,y));
    }
    cin>>tg>>tw;
    cin>>s.x>>s.y>>t.x>>t.y;
    pd(solve());
  }
  return 0;
}