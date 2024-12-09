#include<iostream>
#include<cmath>
#include<complex>
#include<algorithm>
#include<vector>
#define EPS (1e-9)
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1 
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0
#define equals(a,b) (fabs((a)-(b)) < EPS)
#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
using namespace std;

class Point
{
  public:
  double x,y;

  Point(double x = -1,double y = -1): x(x),y(y){}

  Point operator + (Point p ){return Point(x+p.x,y+p.y);}
  Point operator - (Point p){return Point(x-p.x,y-p.y);}
  Point operator * (double a){return Point(a*x,a*y);}
  Point operator / (double a){return Point(x/a,y/a);}//※イケメンに限る

  bool operator < (const Point& p) const
  {
    return x != p.x?x<p.x:y<p.y;
  }

  bool operator == (const Point& p)const
  {
    return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
  }

//必要に応じて
double norm()
{
return x*x+y*y;
}

};

struct Segment
{
  Point p1,p2;
  Segment(Point p1 = Point(-1,-1),Point p2 = Point(-1,-1)):p1(p1),p2(p2){}
};
typedef Point Vector;
typedef Segment Line;
typedef vector<Point> Polygon;


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

bool pequals(Point a,Point b)
{
  return equals(a.x,b.x) && equals(a.y,b.y);
}

//rad は角度をラジアンで持たせること
Point rotate(Point a,double rad)
{
  return Point(cos(rad)*a.x - sin(rad)*a.y,sin(rad)*a.x + cos(rad)*a.y);
}

// 度をラジアンに変換
double toRad(double agl)
{
  return agl*M_PI/180.0;
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

//cross product of pq and pr
double cross3p(Point p,Point q,Point r)
{
  return (r.x-q.x) * (p.y -q.y) - (r.y - q.y) * (p.x - q.x);
}
  
//returns true if point r is on the same line as the line pq
bool collinear(Point p,Point q,Point r)
{
  return fabs(cross3p(p,q,r)) < EPS;
}
  
//returns true if point t is on the left side of line pq
bool ccwtest(Point p,Point q,Point r)
{
  return cross3p(p,q,r) > 0;//can be modified to accept collinear points
}
 
bool onSegment(Point p,Point q,Point r)
{
  return collinear(p,q,r) && equals(sqrt(pow(p.x-r.x,2)+pow(p.y-r.y,2)) + sqrt(pow(r.x-q.x,2) + pow(r.y-q.y,2) ),sqrt(pow(p.x-q.x,2)+pow(p.y-q.y,2)) ) ;
}

bool isIntersect(Point p1,Point p2,Point p3,Point p4)
{
  return (ccw(p1,p2,p3) * ccw(p1,p2,p4) <= 0 &&
          ccw(p3,p4,p1) * ccw(p3,p4,p2) <= 0 );
}

bool isIntersect(Segment s1,Segment s2)
{
  if((s1.p1.x == s1.p2.x && s1.p1.y == s1.p2.y) && (s2.p1.x == s2.p2.x && s2.p1.y == s2.p2.y))
    {
      return false;
    }
  else if( (s1.p1.x == s1.p2.x && s1.p1.y == s1.p2.y) )
    {
      return onSegment(s2.p1,s2.p2,s1.p1);
    }
  else if( (s2.p1.x == s2.p2.x && s2.p1.y == s2.p2.y) )
    {
      return onSegment(s1.p1,s1.p2,s2.p1);
    }
  return isIntersect(s1.p1,s1.p2,s2.p1,s2.p2);
}

int Welch_Powell(vector<vector<int> > &G2)
{
 bool Empti = true;
  for(int i=0;i<G2.size();i++)if(G2[i].size() != 0){Empti = false; break;}
  if(Empti)return 1;
  int G2_size = G2.size();
  int PC = 0;
  int chromatic_number = 0;
  bool Drew[G2_size];
  vector<pair<int,int> > Degree;
  for(int i=0;i<G2_size;i++)Drew[i] = false,Degree.push_back(pair<int,int>(G2[i].size(),i) );
  sort(Degree.begin(),Degree.end(),greater<pair<int,int> >());
       while(PC < G2_size)
	 {
	   chromatic_number++;
	   bool Draw[G2_size];
	   for(int i=0;i<G2_size;i++)Draw[i] = Drew[i];
	   for(int i=0;i<G2_size;i++)
	     { 
	       if(Draw[Degree[i].second]) 
		 continue;
	       Drew[Degree[i].second] = Draw[Degree[i].second] = true;
	       PC++;
	       int index = Degree[i].second;
	       for(int j=0;j<G2[index].size();j++)Draw[G2[index][j]] = true; 
	     }
	 }
       return chromatic_number;
}

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




int n;
vector<Point> vec[30];
vector<vector<int> > G;

int main()
{
  /*
  Segment s1(Point(0,0),Point(10,0));
  Segment s2(Point(0,10),Point(10,10));
  cout << isIntersect(s1,s2) << endl;
  */
  while(cin >> n,n)
    {
      rep(i,30)vec[i].clear();
      rep(i,n)
	{
	  int m;
	  cin >> m;
	  rep(j,m)
	    {
	      int x,y;
	      cin >> x >> y;
	      vec[i].push_back(Point(x,y));
	      if(m == 1) vec[i].push_back(Point(x,y));
	    }
	}
      G.clear();
      G.resize(n,vector<int>());
      vector<vector<int> > M(n,vector<int>(n,0));
      rep(i,n)
	{
	  bool insect[n];
	  rep(j,n)insect[j] = false;
	  rep(j,vec[i].size()-1)
	    {
	      bool intersect = false;
	      REP(k,i+1,n)
		{
		  if(insect[k])continue;
		  rep(l,vec[k].size()-1)
		    {
		      //cout << "Segment( (" << vec[i][j].x << "," << vec[i][j].y << " ) , (" << vec[i][j+1].x << "," << vec[i][j+1].y << ") ) Segment2( (" << vec[k][l].x << "," << vec[k][l].y << ") (" << vec[k][l+1].x << "," << vec[k][l+1].y << ") ) = " << isIntersect(Segment(vec[i][j],vec[i][j+1]),Segment(vec[k][l],vec[k][l+1])) << endl; 
		      if(isIntersect(Segment(vec[i][j],vec[i][j+1]),Segment(vec[k][l],vec[k][l+1])))
			{
			  M[i][k] = M[k][i] = 1;
			  insect[k] = true;
			  G[i].push_back(k);
			  G[k].push_back(i);
			  intersect = true;
			  break;
			}
		    }
	       
		}

	    }
	}
      /*
      cout << "------" << endl;
      rep(i,n)
	{
	  cout << "from " << i << endl;
	  rep(j,G[i].size())
	    {
	      cout << G[i][j] << " ";
	    }
	  cout << endl;
	}
      cout << "------" << endl;
      */
      cout << chromatic_number(M) <<endl;
      //cout << Welch_Powell(G) << endl; 
    }
  return 0;
}