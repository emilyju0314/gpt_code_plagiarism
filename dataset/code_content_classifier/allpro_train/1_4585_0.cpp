#include<bits/stdc++.h>
#define inf (1e12)
#define eps (1e-5)
#define Eps (1e-15)
#define mod 1000000007
#define pi acos(-1.0)
#define phi (1.0+sqrt(5.0))/2.0
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define pd(a) printf("%.10f ",(double)(a))
#define pdouble(a) printf("%.10Lf\n",(ld)(a))
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(a)-1;(b)<=i;i--)
#define Unique(v) v.erase(unique(all(v)),v.end())
#define equals(a,b) (fabs((a)-(b))<eps)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,double> pid;
typedef pair<double,int> pdi;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;

class Point{
public:
  double x,y;
  Point(double x=0,ld y=0):x(x),y(y){}

  Point operator+(Point p){ return Point(x+p.x,y+p.y);}
  Point operator-(Point p){ return Point(x-p.x,y-p.y);}
  Point operator*(double k){ return Point(x*k,y*k);}
  Point operator/(double k){ return Point(x/k,y/k);}
  bool operator<(Point p)const{ 
    return equals(x,p.x) ? y-p.y<-eps : x-p.x<-eps; }
  bool operator==(Point p)const{ 
    return fabs(x-p.x)<eps && fabs(y-p.y)<eps;}

  double abs(){ return sqrt(norm());}
  double norm(){ return (x*x+y*y);}
};
typedef Point Vector;
typedef vector<Point> Polygon;

class Segment{
public:
  Point p1,p2;
  Segment(Point p1=Point(),Point p2=Point()):p1(p1),p2(p2){}
  bool operator==(Segment s)const{
    if(s.p1==p1 && s.p2==p2)return true;
    if(s.p2==p1 && s.p1==p2)return true;
    return false;
  }
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

int ccw(Point p0,Point p1,Point p2){
  Vector a=p1-p0;
  Vector b=p2-p0;
  if(cross(a,b)>eps)return 1;
  if(cross(a,b)<-eps)return -1;
  if(dot(a,b)<-eps)return 2;
  if(a.norm()<b.norm())return -2;
  return 0;
}

Point rotate(Point base,Point a,double r){
  Point b=a-base;
  a.x=b.x*cos((r/180.0)*pi)-b.y*sin((r/180.0)*pi);
  a.y=b.x*sin((r/180.0)*pi)+b.y*cos((r/180.0)*pi);
  a=a+base;
  return a;
}

int N;
double H,W,R;
double h,w;
Point o = Point(0,0);
vector<Point> vp;
vector<Vector> cand;

bool check(Vector v){
  Line L = Line(o,v);
  double w1=0,w2=inf,w3=inf,w4=0,sumw = 0;
  double h1=0,h2=inf,h3=inf,h4=0,sumh = 0;
  FOR(i,0,N){
    Point p = project(L,vp[i]);
    double dis = abs(p);
    if(ccw(o,v,p)==2){
      if(dis-w3<eps)w3 = dis;
      if(w4-dis<eps)w4 = dis;
    }
    else {
      if(dis-w2<eps)w2 = dis;
      if(w1-dis<eps)w1 = dis;
    }
    dis = abs(vp[i]-p);
    if(ccw(o,v,vp[i])==1){
      if(dis-h3<eps)h3 = dis;
      if(h4-dis<eps)h4 = dis;
    }
    else{
      if(dis-h2<eps)h2 = dis;
      if(h1-dis<eps)h1 = dis;
    }
  }
  if(!equals(w4,0) )sumw+=w4;
  if(equals(w3,inf))sumw-=w2;
  if(!equals(w1,0) )sumw+=w1;
  if(equals(w2,inf))sumw-=w3;

  if(!equals(h4,0) )sumh+=h4;
  if(equals(h3,inf))sumh-=h2;
  if(!equals(h1,0)) sumh+=h1;
  if(equals(h2,inf))sumh-=h3;

  if(sumh-h<eps && sumw-w<eps)return true;
  if(sumh-w<eps && sumw-h<eps)return true;
  return false;
}

string solve(){
  h = (H-R-R),w = (W-R-R); 
  if(N==1){
    if(2.0*R-H<eps && 2.0*R-W<eps)return "Yes";
    return "No";
  }
  FOR(i,0,vp.size()){
    FOR(j,0,vp.size()){
      if(i==j)continue;
      Point a=vp[i],b=vp[j];
      double dis = abs(b-a);
      Vector v = (b-a)/dis;
      if(dis-w < eps)cand.pb(v);
      else {
        cand.pb(rotate(Point(0,0),v,acos(w/dis)/pi*180.0));
        cand.pb(rotate(Point(0,0),v,360.0-acos(w/dis)/pi*180.0));
      }
      if(dis-h < eps)cand.pb(v);
      else {
        cand.pb(rotate(Point(0,0),v,acos(h/dis)/pi*180.0));
        cand.pb(rotate(Point(0,0),v,360.0-acos(h/dis)/pi*180.0));
      }
    }
  }
  FOR(i,0,cand.size())
    if(check(cand[i]))return "Yes";
  return "No";
}

int main()
{
  cin>>N>>H>>W>>R;
  FOR(i,0,N){
    double x,y;
    cin>>x>>y;
    vp.pb(Point(x,y));
  }
  cout<<solve()<<endl;
  return 0;
}

