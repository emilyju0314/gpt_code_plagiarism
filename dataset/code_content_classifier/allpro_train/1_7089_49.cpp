#include<bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pi M_PI
#define inf 1<<30
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
  Segment(Point p1=Point(),Point p2=Point()):p1(p1),p2(p2){}
};
typedef Segment Line;

double norm(Vector a){ return (a.x*a.x+a.y*a.y);}
double abs(Vector a){ return sqrt(norm(a));}
double dot(Vector a,Vector b){ return (a.x*b.x+a.y*b.y);}
double cross(Vector a,Vector b){ return (a.x*b.y-a.y*b.x);}

double getDistanceLP(Line l,Point p){
  return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));
}

Point rotate(Point base,Point a,double r){
  Point b=a-base;
  a.x=b.x*cos((r/180)*M_PI)-b.y*sin((r/180)*M_PI);
  a.y=b.x*sin((r/180)*M_PI)+b.y*cos((r/180)*M_PI);
  a=a+base;
  return a;
}

Point getCrossPointLL(Line a,Line b){
  double A=cross(a.p2-a.p1,b.p2-b.p1);
  double B=cross(a.p2-a.p1,a.p2-b.p1);
  if(abs(A)<eps || abs(B)<eps)return b.p1;
  return b.p1+(b.p2-b.p1)*(B/A);
}

//  ?§?????????????????????????
Line getBisectorOfAngle(Point base,Point a,Point b){
  Vector v1=(a-base),v2=(b-base);
  double s=acos(dot(v1,v2)/(abs(v1)*abs(v2)))*360/(4*pi);
  return Line(base,rotate(base,a,s));
}

//  ????§???¢???????§?????????????????????????
Line getBisectorOfAngleInTriangle(Point base,Point a,Point b){
  Line L=getBisectorOfAngle(base,a,b);
  Point p=getCrossPointLL(Line(a,b),L);
  return Segment(base,p);
}

Point p1,p2,p3;
Segment s1,s2,s3;
Line L1,L2,L3;
vector<double> ans;

bool check(Line L,Point A,double a,double dis){
  Vector V=(L.p2-L.p1)/abs(L.p2-L.p1);
  Point P=L.p1+V*dis;
  double d=getDistanceLP(s3,P);
  if(((a+d)-abs(A-P))<eps)return true;
  return false;
}

bool ok(double dis){
  Vector V=(L1.p2-L1.p1)/abs(L1.p2-L1.p1);
  Point A=L1.p1+V*dis;
  double a,b,c,l,r,m;
  a=getDistanceLP(s1,A);

  l=0;r=abs(L2.p1-L2.p2);
  for(int i=0;i<50;i++){
    m=(l+r)/2.0;
    if(check(L2,A,a,m))l=m;
    else r=m;
  }
  V=(L2.p2-L2.p1)/abs(L2.p2-L2.p1);
  Point B=L2.p1+V*m;
  b=getDistanceLP(s3,B);

  l=0;r=abs(L3.p1-L3.p2);
  for(int i=0;i<50;i++){
    m=(l+r)/2.0;
    if(check(L3,A,a,m))l=m;
    else r=m;
  }
  V=(L3.p2-L3.p1)/abs(L3.p2-L3.p1);
  Point C=L3.p1+V*m;
  c=getDistanceLP(s3,C);

  if(equals(c+b,abs(C-B))){
    ans.push_back(a);
    ans.push_back(b);
    ans.push_back(c);
  }
  if(((c+b)-abs(C-B))<-eps)return true;
  return false;
}

int main()
{
  int a,b,c,d,e,f;
  while(1){
    cin>>a>>b>>c>>d>>e>>f;
    if(a+b+c+d+e+f==0)break;
    p1=Point(a,b);
    p2=Point(c,d);
    p3=Point(e,f);
    s1=Segment(p1,p2);
    s2=Segment(p1,p3);
    s3=Segment(p2,p3);
    L1=getBisectorOfAngleInTriangle(p1,p2,p3);
    L2=getBisectorOfAngleInTriangle(p2,p3,p1);
    L3=getBisectorOfAngleInTriangle(p3,p1,p2);
    Point cp=getCrossPointLL(L1,L2);
    L1.p2=cp;
    L2.p2=cp;
    L3.p2=cp;
    ans.clear();

    double l=0,r=abs(L1.p2-L1.p1);
    for(int i=0;i<50;i++){
      double m=(l+r)/2.0;
      if(ok(m))r=m;
      else l=m;
      if(!ans.empty())break;
    }

    printf("%.6f %.6f %.6f\n",ans[0],ans[1],ans[2]);
  }
  return 0;
}