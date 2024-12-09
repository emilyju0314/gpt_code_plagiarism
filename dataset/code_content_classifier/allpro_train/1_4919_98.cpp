#include<bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define inf 100000000
#define eps (1e-11)
#define equals(a,b) (fabs((a)-(b))<eps)
using namespace std;

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
  Segment(Point p1,Point p2):p1(p1),p2(p2){}
};
double norm(Vector a){ return (a.x*a.x+a.y*a.y);}
double abs(Vector a){ return sqrt(norm(a));}
double dot(Vector a,Vector b){ return (a.x*b.x+a.y*b.y);}
double cross(Vector a,Vector b){ return (a.x*b.y-a.y*b.x);}

static const int COUNTER_CLOCKWISE=1;
static const int CLOCKWISE=-1;
static const int ONLINE_BACK=2;
static const int ONLINE_FRONT=-2;
static const int ON_SEGMENT=0;

int ccw(Point p0,Point p1,Point p2){
  Vector a=p1-p0;
  Vector b=p2-p0;
  if(cross(a,b)>eps)return COUNTER_CLOCKWISE;
  if(cross(a,b)<-eps)return CLOCKWISE;
  if(dot(a,b)<-eps)return ONLINE_BACK;
  if(a.norm()<b.norm())return ONLINE_FRONT;
  return ON_SEGMENT;
}

bool intersect(Point p1,Point p2,Point p3,Point p4){
  return (ccw(p1,p2,p3)*ccw(p1,p2,p4)<=0 &&
          ccw(p3,p4,p1)*ccw(p3,p4,p2)<=0);
}

bool intersect(Segment s1,Segment s2){
  return intersect(s1.p1,s1.p2,s2.p1,s2.p2);
}

int main()
{
  int n;
  int a,b,c,d,e,f,sx,sy,gx,gy;
  Point p[3];

  cin>>n;
  for(int i=0;i<n;i++){
    cin>>p[0].x>>p[0].y>>p[1].x>>p[1].y>>p[2].x>>p[2].y;
    cin>>sx>>sy>>gx>>gy;
    Segment s(Point(sx,sy),Point(gx,gy));
    int c=0;
    for(int i=0;i<3;i++){
      if(intersect(s,Segment(p[i],p[(i+1)%3])))c++;
    }
    if(c==1)cout<<"OK"<<endl;
    else cout<<"NG"<<endl;
  }
  return 0;
}