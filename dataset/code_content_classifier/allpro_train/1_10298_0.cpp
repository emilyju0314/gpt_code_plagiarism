#include<bits/stdc++.h>
#define inf 10010
#define linf 1e16
#define eps (1e-8)
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

bool intersect(Line L,Segment s){
  return cross(L.p2-L.p1,s.p1-L.p1)*cross(L.p2-L.p1,s.p2-L.p1)<eps;
}

double getDistanceLP(Line l,Point p){
  return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));
}

bool iscrossLC(Line l,Circle c){
  if((getDistanceLP(l,c.c)-c.r)<eps)return true;
  return false;
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

vector<pdd> cut(double a,double b,double c,double d){
  vector<pdd> res;
  if(d-a<eps || b-c<eps)res.pb(mp(a,b));
  else if(c-a<eps && b-d<eps)res.pb(mp(linf,linf));
  else if(c-a<eps && d-b<eps)res.pb(mp(d,b));
  else if(a-c<eps && b-d<eps)res.pb(mp(a,c));
  else {
    res.pb(mp(a,c));
    res.pb(mp(d,b));
  }
  return res;
}

int n,m,R;
Polygon a,b;

ll count(Segment s){
  ll res=0;
  queue<pdd> q;
  q.push(mp(s.p1.y,s.p2.y));
  FOR(i,0,m){
    Point p1=b[i],p2=b[(i+1)%m];
    vector<pdd> v;
    vector<Point> vp,tmp;
    double h=abs(p1.y-p2.y);
    double w=abs(p1.x-p2.x);
    double u=-linf,d=linf;
    if(equals(w,0.0)){
      if(iscrossLC(s,Circle(p1,R))){
        u=max(u,p1.y+sqrt(R*R-(p1.x-s.p1.x)*(p1.x-s.p1.x)));
        d=min(d,p1.y-sqrt(R*R-(p1.x-s.p1.x)*(p1.x-s.p1.x)));
      }
      if(iscrossLC(s,Circle(p2,R))){
        u=max(u,p2.y+sqrt(R*R-(p2.x-s.p1.x)*(p2.x-s.p1.x)));
        d=min(d,p2.y-sqrt(R*R-(p2.x-s.p1.x)*(p2.x-s.p1.x)));
      }
      if(equals(u,-linf))continue;
      v.pb(mp(d,d+h));
      v.pb(mp(u-h,u));
    }
    else {
      if(iscrossLC(s,Circle(p1,R)))
        u=sqrt(R*R-(p1.x-s.p1.x)*(p1.x-s.p1.x));
      if(iscrossLC(s,Circle(p2,R)))
        d=sqrt(R*R-(p2.x-s.p1.x)*(p2.x-s.p1.x));
      if(intersect(s,Segment(p1,p2))){
        if(!equals(u,-linf) && !equals(d,linf)){
          v.pb(mp(p1.y+min(u,d),p1.y+R));
          v.pb(mp(p1.y-R,p1.y-min(u,d)));
        }
        else v.pb(mp(p1.y-R,p1.y+R));
      }
      else {
        if(!equals(u,-linf) && !equals(d,linf)){
          v.pb(mp(p1.y+min(u,d),p1.y+max(u,d)));
          v.pb(mp(p1.y-max(u,d),p1.y-min(u,d)));
        }
        else if(!equals(u,-linf))v.pb(mp(p1.y-u,p1.y+u));
        else if(!equals(d,linf))v.pb(mp(p1.y-d,p1.y+d));
      }
    }
    FOR(j,0,v.size()){
      queue<pdd> nq;
      while(q.size()){
        pdd u=q.front();
        q.pop();
        vector<pdd> vpdd=cut(u.f,u.s,v[j].f,v[j].s);
        FOR(k,0,vpdd.size()){
          if(vpdd[k].s-vpdd[k].f<eps)continue;
          if(vpdd[k].f==linf)continue;
          nq.push(vpdd[k]);
        }
      }
      while(nq.size()){
        q.push(nq.front());
        nq.pop();
      }
    }
  }
  while(q.size()){
    pdd u=q.front();
    if(u.s>eps)res+=int(u.s-eps);
    else res+=int(u.s-1);
    if(u.f>-eps)res-=int(u.f+1);
    else res-=int(u.f+eps);
    res++;
    q.pop();
  }
  return res;
}

ll count(int X){
  Line L(Point(X,0),Point(X,100));
  vector<double> v;
  FOR(i,0,n){
    Segment s(a[i],a[(i+1)%n]);
    if(isParallel(L,s))continue;
    if(!intersect(L,s))continue;
    Point M=getCrossPointLL(L,s);
    v.pb(M.y);
  }
  sort(all(v));
  ll res=0;
  FOR(i,1,v.size()){
    Point p1(X,v[i-1]),p2(X,v[i]);
    if(contains(a,p1+(p2-p1)/2.0)==2)res+=count(Segment(p1,p2));
  }
  return res;
}

ll solve(){
  ll res = 0;
  FOR(i,-inf,inf)res+=count(i);
  return res;
}

int main()
{
  cin>>n>>m>>R;
  a.resize(n);
  b.resize(m);
  FOR(i,0,n)cin>>a[i].x>>a[i].y;
  FOR(i,0,m)cin>>b[i].x>>b[i].y;
  cout<<solve()<<endl;
  return 0;
}