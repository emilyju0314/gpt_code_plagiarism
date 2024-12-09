#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cassert>
#include<climits>
#include<map>
#include<set>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define IINF (INT_MAX)
#define EPS (1e-10)
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1 
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0
#define equals(a,b) (fabs((a)-(b)) < EPS)
#define MAX 20

using namespace std;

typedef pair<int,int> ii;

// Library - template - begin

class Point
{
  public:
  double x,y;

  Point(double x = -IINF,double y = -IINF): x(x),y(y){}

  Point operator + (Point p){return Point(x+p.x,y+p.y);}
  Point operator - (Point p){return Point(x-p.x,y-p.y);}
  Point operator * (double a){return Point(a*x,a*y);}
  Point operator / (double a){return Point(x/a,y/a);}
  Point operator * (Point a){ return Point(x * a.x - y * a.y, x * a.y + y * a.x); }

  bool operator < (const Point& p) const
  {
    return !equals(x,p.x)?x<p.x:y<p.y;
  }

  bool operator == (const Point& p)const
  {
    return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
  }

};

struct Segment
{
  Point p1,p2;
  Segment(Point p1 = Point(),Point p2 = Point()):p1(p1),p2(p2){}
  bool operator == (const Segment& p)const
  {
    return p.p1 == p1 && p.p2 == p2;
  }
};

typedef Point Vector;
typedef Segment Line;
typedef vector<Point> Polygon;

ostream& operator << (ostream& os,const Point& a)
{
  os << "(" << a.x << "," << a.y << ")";
}

ostream& operator << (ostream& os,const Segment& a)
{
  os << "( " << a.p1 << " , " << a.p2 << " )";
}

double dot(Point a,Point b){ return a.x*b.x + a.y*b.y; }

double cross(Point a,Point b){ return a.x*b.y - a.y*b.x; }

double norm(Point a){ return a.x*a.x+a.y*a.y; }

double abs(Point a){ return sqrt(norm(a)); }

//rad は角度をラジアンで持たせること
Point rotate(Point a,double rad){ return Point(cos(rad)*a.x - sin(rad)*a.y,sin(rad)*a.x + cos(rad)*a.y); }

// 度をラジアンに変換
double toRad(double agl){ return agl*M_PI/180.0; }

// Library - template - end

// Library - CCW - begin

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

// Library - CCW - end

// Library - intersect - begin

bool intersectLL(Line l, Line m) {
  return abs(cross(l.p2-l.p1, m.p2-m.p1)) > EPS || // non-parallel
         abs(cross(l.p2-l.p1, m.p1-l.p1)) < EPS;   // same line
}
bool intersectLS(Line l, Line s) {
  return cross(l.p2-l.p1, s.p1-l.p1)*       // s[0] is left of l
         cross(l.p2-l.p1, s.p2-l.p1) < EPS; // s[1] is right of l
}
bool intersectLP(Line l,Point p) {
  return abs(cross(l.p2-p, l.p1-p)) < EPS;
}
bool intersectSS(Line s, Line t) {
  return ccw(s.p1,s.p2,t.p1)*ccw(s.p1,s.p2,t.p2) <= 0 &&
         ccw(t.p1,t.p2,s.p1)*ccw(t.p1,t.p2,s.p2) <= 0;
}
bool intersectSP(Line s, Point p) {
  return abs(s.p1-p)+abs(s.p2-p)-abs(s.p2-s.p1) < EPS; // triangle inequality
}

Point projection(Line l,Point p) {
  double t = dot(p-l.p1, l.p1-l.p2) / norm(l.p1-l.p2);
  return l.p1 + (l.p1-l.p2)*t;
}
Point reflection(Line l,Point p) {
  return p + (projection(l, p) - p) * 2;
}
double distanceLP(Line l, Point p) {
  return abs(p - projection(l, p));
}
double distanceLL(Line l, Line m) {
  return intersectLL(l, m) ? 0 : distanceLP(l, m.p1);
}

double distanceLS(Line l, Line s) {
  if (intersectLS(l, s)) return 0;
  return min(distanceLP(l, s.p1), distanceLP(l, s.p2));
}
double distanceSP(Line s, Point p) {
  Point r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s.p1 - p), abs(s.p2 - p));
}

double distanceSS(Line s, Line t) {
  if (intersectSS(s, t)) return 0;
  return min(min(distanceSP(s, t.p1), distanceSP(s, t.p2)),
             min(distanceSP(t, s.p1), distanceSP(t, s.p2)));
}
Point crosspoint(Line l, Line m) {
  double A = cross(l.p2 - l.p1, m.p2 - m.p1);
  double B = cross(l.p2 - l.p1, l.p2 - m.p1);
  if (abs(A) < EPS && abs(B) < EPS) return m.p1; // same line
  if (abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
  return m.p1 +   (m.p2 - m.p1) * (B / A);
}

// Library - intersect - end

// Library - Dent - begin


int pow(int x,int n)
{
  int res = 1;
  for(;n;n>>=1)
    {
      if(n&1)res = res*x;
      x = x * x;
    }
  return res;
}

int chromatic_number(vector<vector<int> > &M)
{
  int n = M.size();
  vector<int> F(n);
  rep(i,n)
    {
      F[i] |= 1<<i;
      rep(j,n)
	{
	  if(M[i][j])F[i] |= 1 << j;
	}
    }

  vector<int> I(1<<n);
  I[0] = 1;
  for(int i=1;i<(1<<n);i++)
    {
      int v = __builtin_ctz(i);
      I[i] = I[i^(1<<v)] + I[i & ~F[v]];
    }
  int low = 0,high = n;
  while(low+1 < high)
    {
      int k = (low+high)/2,g = 0;
      rep(i,(1<<n))
	{
	  if(__builtin_popcount(i) & 1)
	    {
	      g -= pow(I[i],k);
	    }
	  else
	    {
	      g += pow(I[i],k);
	    }
	}
      if(g != 0)high = k;
      else low = k;
    }
  return high;
}

// Library - Dent - end

struct P
{
  Point p;
  int type;
  P(Point p=Point(),int type=IINF):p(p),type(type){}
  bool operator < (const P& a)const
  {
    if(!(p == a.p))return p < a.p;
    return type < a.type;
  }
};

bool isParallel(Vector a,Vector b)
{
  return equals(cross(a,b),0.0);
}

bool isParallel(Point a1,Point a2,Point b1,Point b2)
{
  return isParallel(a1-a2,b1-b2);
}

bool isParallel(Segment s1,Segment s2)
{
  return equals(cross(s1.p2-s1.p1,s2.p2-s2.p1),0.0);
}

bool intersect(Segment seg1,Segment seg2)
{
  if(!isParallel(seg1,seg2))return false;

  double dist = distanceSS(seg1,seg2);

  if(!equals(dist,0.0))return false;

  vector<P> vec;
  
  vec.push_back(P(seg1.p1,0));
  vec.push_back(P(seg1.p2,0));
  vec.push_back(P(seg2.p1,1));
  vec.push_back(P(seg2.p2,1));
  sort(vec.begin(),vec.end());
  if(vec[1].p == vec[2].p)return false;
  
  return true;

}

vector<int> G[MAX];

int main()
{

  int N;
  while(cin >> N,N)
    {
      map<string,int> Index;
      int dex = 0;
      string country[N];
      vector<Point> coor[N];
      int index[N];

      rep(i,N)
	{
	  cin >> country[i];
	  if(Index.find(country[i]) == Index.end())Index[country[i]] = dex++;
	  int x,y;
	  while(cin >> x, x != -1)
	    {
	      cin >> y;
	      coor[i].push_back(Point(x,y));
	    }
	}

      rep(i,N)
	{
	  index[i] = Index[country[i]];
	  //cout << "index[" << i << "] = " << index[i] << endl;
	}
      int n = Index.size();
      rep(i,n)G[i].clear();

      set<ii> used;

      rep(i,N)
	{
	  REP(j,i+1,N)
	    {	 
	      if(index[i] == index[j])continue;
	      if(used.find(ii(index[i],index[j])) != used.end())continue;

	      vector<Point> vec;
	      bool check = false;
	      
	      rep(k,coor[i].size())
		{
		  Segment seg1 = Segment(coor[i][k],coor[i][(k+1)%coor[i].size()]);
		  rep(l,coor[j].size())
		    {
		      Segment seg2 = Segment(coor[j][l],coor[j][(l+1)%coor[j].size()]);

		      if(intersect(seg1,seg2))
			{
			  check = true;
			  goto Skip;
			}
		    }
		}
	    Skip:;	      
	      if(check)
		{
		  used.insert(ii(index[i],index[j]));
		  used.insert(ii(index[j],index[i]));
		  G[index[i]].push_back(index[j]);
		  G[index[j]].push_back(index[i]);
		}
	    }
	}
      /*
      cout << "Graph === " << endl;
      rep(i,n)
	{
	  cout << "i = " << i << endl;
	  rep(j,G[i].size())
	    {
	      cout << G[i][j];
	    }
	  cout << endl;
	}
      */
      vector<vector<int> > M(n,vector<int>(n,0));
      //cout << "n = " << n << endl;
      rep(i,n)
	{
	  rep(j,G[i].size())
	    {
	      int to = G[i][j];
	      M[i][to] = M[to][i] = 1;
	    }
	}      
      //cout << "-----------222----" << endl;
      cout << chromatic_number(M) << endl;

    }
  return 0;
}