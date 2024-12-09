#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<complex>
#include<cassert>
#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define inf (1<<28)
#define EPS (1e-10)
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1 
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0
#define MAX 110
#define equals(a,b) (fabs((a)-(b)) < EPS)

using namespace std;

struct P
{
  int to;
  double cost;
  P(int to=-inf,double cost=-inf):to(to),cost(cost){}
  bool operator < (const P& a)const
  {
    return cost > a.cost;
  }
};

typedef vector<P> vp;
typedef vector<vp> vvp;

class Point
{
  public:
  double x,y;

  Point(double x = -inf,double y = -inf): x(x),y(y){}

  Point operator + (Point p ){return Point(x+p.x,y+p.y);}
  Point operator - (Point p){return Point(x-p.x,y-p.y);}
  Point operator * (double a){return Point(a*x,a*y);}
  Point operator / (double a){return Point(x/a,y/a);}

  bool operator < (const Point& p) const
  {
    return x != p.x?x<p.x:y<p.y;
  }

  bool operator == (const Point& p)const
  {
    return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
  }

};

ostream& operator << (ostream& os,const Point& p)
{
  os << setiosflags(ios::fixed) << setprecision(5) << "(" << p.x << "," << p.y << ")";
}

struct Segment
{
  Point p1,p2;
  Segment(Point p1 = Point(-1,-1),Point p2 = Point(-1,-1)):p1(p1),p2(p2){}
};
typedef Point Vector;
typedef Segment Line;
typedef vector<Point> Polygon;

struct Circle
{
  Point p;
  double r;
  Circle(Point p=Point(),double r=-inf):p(p),r(r){}
};

struct Illuminant
{
  double r,a,theta,b,maxpower;
  Point p;
  Illuminant(Point p=Point(),double r=-inf,double theta=-inf,double a=-inf,double b=-inf,double maxpower=-inf):p(p),r(r),theta(theta),a(a),b(b),maxpower(maxpower){}
};

double dot(Point a,Point b)
{
  return a.x*b.x + a.y*b.y;
}
double cross(Point a,Point b)
{
  return a.x*b.y - a.y*b.x;
}

double norm(Point a)
{
  return a.x*a.x+a.y*a.y;
}

double toRad(double agl)
{
  return (agl*M_PI/180.0);
}

Point rotate(Point a,double rad)
{
  return Point(cos(rad)*a.x - sin(rad)*a.y,sin(rad)*a.x + cos(rad)*a.y);
}


int ccw(Point p0,Point p1,Point p2)
{
  Point a = p1-p0;
  Point b = p2-p0;
  if(cross(a,b) > EPS)return COUNTER_CLOCKWISE;
  if(cross(a,b) < -EPS)return CLOCKWISE;
  if(dot(a,b) < -EPS)return ONLINE_BACK;
  if(norm(a) < norm(b))return ONLINE_FRONT;
  return ON_SEGMENT;
}

double abs(Point a)
{
  return sqrt(norm(a));
}

double getDistanceLP(Line s,Point p)
{
  return abs(cross(s.p2-s.p1,p-s.p1))/abs(s.p2-s.p1);
}

double getDistanceSP(Segment s,Point p)
{
  if(dot(s.p2-s.p1,p-s.p1) < 0.0)return abs(p-s.p1);
  if(dot(s.p1-s.p2,p-s.p2) < 0.0)return abs(p-s.p2);
  return getDistanceLP(s,p);
}

double angle(Point a,Point b,Point c)
{
  double ux = b.x - a.x, uy = b.y - a.y;
  double vx = c.x - a.x, vy = c.y - a.y;
  return acos((ux*vx + uy*vy)/sqrt((ux*ux + uy*uy) * (vx*vx + vy*vy)));
}  

template<typename T>
bool visit(const T& G,int v,vector<int>& order,vector<int>& color)
{
  color[v] = 1;
  for(__typeof((G[v]).begin()) e = G[v].begin();e != G[v].end();e++)
    {
      if(color[e->to] == 2)continue;//このvisit以外のvisitで訪れた
      if(color[e->to] == 1)return false;//このvisitで訪れた
      if(!visit(G,e->to,order,color))return false;
    }
  order.push_back(v);
  color[v] = 2;
  return true;
}

template<typename T>
bool topologicalSort(const T& G,vector<int>& order)
{
  int SizeG = G.size();
  vector<int> color(SizeG); 
  for(int u=0;u<SizeG;u++)
    if(!color[u] && !visit(G,u,order,color))
      return false;
  reverse(order.begin(),order.end());
  return true;
}


int n;
Illuminant illuminants[MAX];
vvp graph;
double dp[MAX];

//is the Circle c in the Illuminant ill?
bool check(Illuminant ill,Circle c)
{
  Point L = Point(ill.p.x + ill.r*cos(toRad(ill.b-ill.theta/2.0)),ill.p.y + ill.r*sin(toRad(ill.b-ill.theta/2.0)));
  Point R = Point(ill.p.x + ill.r*cos(toRad(ill.b+ill.theta/2.0)),ill.p.y + ill.r*sin(toRad(ill.b+ill.theta/2.0)));

  if(ccw(ill.p,L,c.p) == CLOCKWISE)return false;
  if(ccw(ill.p,R,c.p) == COUNTER_CLOCKWISE)return false;

  double distL = getDistanceLP(Line(ill.p,L),c.p);
  double distR = getDistanceLP(Line(ill.p,R),c.p);

  if(!( equals(distL,c.r) || distL > c.r ))return false;
  if(!( equals(distR,c.r) || distR > c.r ))return false;

  double dist = sqrt(norm(ill.p-c.p)) + c.r;
  if(!( equals(dist,ill.a) || ill.a > dist ))return false;
  return true;
}

void create_graph()
{
  rep(i,graph.size())graph[i].clear();
  graph.resize(n+2,vp());

  REP(i,1,n+1)
    {
      REP(j,1,n+2)
	{
	  if(i == j)continue;
	  if(check(illuminants[i],Circle(illuminants[j].p,illuminants[j].r)))graph[i].push_back(P(j,illuminants[i].maxpower));

	}
    }

}

double compute(vp vst)
{
  graph[0] = vst;
  vector<int> order;
  topologicalSort(graph,order);

  double dp[n+3];
  rep(i,n+3)dp[i] = 0;
  dp[0] = illuminants[0].maxpower;

  rep(i,order.size())
    {
      int cur = order[i];
      rep(j,graph[cur].size())
	{
	  int next = graph[cur][j].to;
	  dp[next] = min(illuminants[next].maxpower,
			 dp[next] + dp[cur]);
	}
    }
  return dp[n+1];
}

double getArg(double a,double b,double c)
{
  return acos((b*b+c*c-a*a)/(2.0*b*c));
}

int main()
{
  while(cin >> n)
    {
      illuminants[0].p = Point(0,0);
      illuminants[n+1].maxpower = inf;
      cin >> illuminants[0].theta >> illuminants[0].a >> illuminants[0].maxpower;
      REP(i,1,n+1)cin >> illuminants[i].p.x >> illuminants[i].p.y >> illuminants[i].r >> illuminants[i].theta >> illuminants[i].a >> illuminants[i].b >> illuminants[i].maxpower;
      cin >> illuminants[n+1].p.x >> illuminants[n+1].p.y >> illuminants[n+1].r;

      create_graph();

      double ans = 0;
      double theta = illuminants[0].theta;
      double a = illuminants[0].a;
      double maxpower = illuminants[0].maxpower;
      REP(i,1,n+2)
	{

	  //-----------------------------------------------

	  double alpha = atan2(illuminants[i].p.y,illuminants[i].p.x);
	  double A = sqrt(norm(illuminants[i].p));
	  double B = illuminants[i].r;
	  double C = sqrt(A*A-B*B);
	  double varg = acos((C*C+A*A-B*B)/(2.0*C*A)) + alpha;
	  varg = varg*180/M_PI;

	  if(!equals(varg,360.0) && varg > 360.0)varg -= 360.0;//※rev
	  varg -= theta/2.0;
	  if(!equals(varg,0.0) && varg < 0.0)varg = 360.0 - varg;

	  vector<P> vst;
	  REP(j,1,n+2)
	    {
	      if(check(Illuminant(Point(0,0),a,theta,a,varg,maxpower),Circle(illuminants[j].p,illuminants[j].r)))
		vst.push_back(P(j,maxpower));
	    }
	  ans = max(ans,compute(vst));

	  //-----------------------------------------------

	  alpha = atan2(illuminants[i].p.y,illuminants[i].p.x);
	  A = sqrt(norm(illuminants[i].p));
	  B = illuminants[i].r;
	  C = sqrt(A*A-B*B);
	  varg = -acos((C*C+A*A-B*B)/(2.0*C*A)) + alpha;
	  varg = varg*180/M_PI;

	  //if(!equals(varg,360.0) && varg > 360.0)varg -= 360.0;//※rev
	  if(!equals(varg,0.0) && varg < 0)varg = 360.0 + varg;
	  varg += theta/2.0;
	  if(!equals(varg,360.0) && varg > 360.0)varg -= 360.0;

	  vst.clear();
	  REP(j,1,n+2)
	    {
	      if(check(Illuminant(Point(0,0),a,theta,a,varg,maxpower),Circle(illuminants[j].p,illuminants[j].r)))
		vst.push_back(P(j,maxpower));
	    }
	  ans = max(ans,compute(vst));

	}

      cout << (int)ans << endl;

    }
  return 0;
}