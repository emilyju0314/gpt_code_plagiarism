#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#include<iomanip>
#include<ctime>
#include<cassert>
#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
#define EPS (1e-7)
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1 
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0
#define MAX 1000
#define equals(a,b) (fabs((a)-(b)) < EPS)


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
    return !equals(x,p.x)?x<p.x:y<p.y;
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



class Voronoi
{
public:
  Polygon poly;
  vector<Point> cutpoints;

  Voronoi(Polygon poly):poly(poly){}

  double norm(Point p){
    return p.x*p.x+p.y*p.y;
  }
 
  double abs(Point p){
    return sqrt(norm(p));
  }
 
  Point polar(double a,double rad){
    return Point(a*cos(rad),a*sin(rad));
  }
 
  double args(Point p){
    return atan2(p.y,p.x);
  }
 
  double dot(Point a,Point b){
    return a.x*b.x+a.y*b.y;
  }
 
  double cross(Point a,Point b){
    return a.x*b.y-b.x*a.y;
  }
 
  Point project(Segment s,Point p){
    Point base = s.p2 - s.p1;
    double t = dot(p-s.p1,base)/base.norm();
    return s.p1+base*t;
  }
 
  Point reflect (Segment s, Point p){
    return p + (project(s,p)-p)*2.0;
  }
 
  int ccw(Point p0,Point p1,Point p2){
    Point a = p1-p0;
    Point b = p2-p0;
    if(cross(a,b) > EPS) return COUNTER_CLOCKWISE;
    if(cross(a,b) < -EPS) return CLOCKWISE;
    if(dot(a,b) < -EPS) return ONLINE_BACK;
    if(a.norm() < b.norm() ) return ONLINE_FRONT;
    return ON_SEGMENT;
  }
 
  bool isIntersect(Point p1,Point p2,Point p3,Point p4){
    return (ccw(p1,p2,p3) * ccw(p1,p2,p4) <= 0 && ccw(p3,p4,p1) * ccw(p3,p4,p2) <= 0 );
  }
 
  bool isIntersect(Segment s1,Segment s2){
    return isIntersect(s1.p1,s1.p2,s2.p1,s2.p2);
  }

  Point getCrossPointSegments(Segment s1,Segment s2){
    //assert(isIntersect(s1,s2));
    Point base = s2.p2 - s2.p1;
    double d1 = abs(cross(base,s1.p1-s2.p1));
    double d2 = abs(cross(base,s1.p2-s2.p1));
    double t = d1/(d1+d2);
    return s1.p1+(s1.p2-s1.p1)*t;
  }


  Point getCrossPointLines( Line s1, Line s2){

    Point a = s1.p2 - s1.p1;
    Point base = s2.p2 -s2.p1;
    return s1.p1 + a * (cross(base, s2.p1 - s1.p1)/cross(base, a));
  }

  Polygon cutPolygon( Polygon P, Line l ){
    Polygon u;
    
    for ( int i = 0; i < P.size(); i++ ){
      Point a = P[i], b = P[(i+1)%P.size()];
	
      if ( ccw(l.p1, l.p2, a) != CLOCKWISE ) u.push_back(a);
      if ( ccw(l.p1, l.p2, a) * ccw(l.p1, l.p2, b) == -1 ){
	cutpoints.push_back(getCrossPointLines(Segment(a,b),l));
	u.push_back(getCrossPointLines(Segment(a, b), l));
      }
    }   
    return u;
  } 
 
  Line CreateLine(Point p,Point pp){
    Point mid = (p+pp)/2;
    Point sl = pp-p;//原点に5
    double rad = args(sl);
    Point ap = polar(abs(sl),rad+M_PI/2)+mid;
    //ap.x = abs(sl)*cos(rad+M_PI/2)+mid.x;
    //ap.y = abs(sl)*sin(rad+M_PI/2)+mid.y;
    return Line(mid,ap);
  } 
 
  double AreaCalc(Polygon p){
    double area = 0;
    for(int i=0;i<p.size();i++)
      area+=cross(p[i],p[(i+1)%p.size()]);
    return fabs(area)/2.0;
  } 

  //サイトposに対するボロノイセルV(pos)の面積を返す 
  //pointsは多角形の中に存在するサイトの集合]
  //posはpoints中の自分の位置
  double getAreaOfVoronoi(vector<Point>& points,int pos)
  {
    Polygon polx = poly;
    int N = points.size();
    for(int i=0;i<N;i++)
      if(i != pos)
	polx = cutPolygon(polx,CreateLine(points[pos],points[i]));
    return AreaCalc(polx);
  }  

  /*
   作成中
   points[pos]を基準にcutPolygonした後のpolygonを返す
   */
  vector<Point> getPoints(vector<Point>& points,int pos)
  {
    set<Point> polyS;
    cutpoints.clear();
    for(int i=0;i<poly.size();i++)polyS.insert(poly[i]);
    Polygon polx = poly;
    int N = points.size();
    //  cout << "N = " << N << endl;
    for(int i=0;i<N;i++)
      if(i != pos)
	{
	  polx = cutPolygon(polx,CreateLine(points[pos],points[i]));
	  Line line = CreateLine(points[pos],points[i]);
	  rep(i,4)
	    {
	      if( ccw(line.p1,line.p2,poly[i]) == ON_SEGMENT ||  ccw(line.p1,line.p2,poly[i]) == ONLINE_FRONT ||  ccw(line.p1,line.p2,poly[i]) == ONLINE_BACK)
		{
		  cutpoints.push_back(poly[i]);
		}
	    }
	}

    /*
      cout << "polx ---" << endl;
    rep(i,polx.size())
      {
	cout << polx[i].x << "," << polx[i].y << endl;
      }
    cout << endl;

    cout << "cutpoint ---" <<endl;
    rep(i,cutpoints.size())
      {
	cout << cutpoints[i].x << "," << cutpoints[i].y << endl;
      }
    cout << endl;
    */

    vector<Point> ret;
    for(int i=0;i<polx.size();i++)
      {
	bool ok = false;
	rep(j,cutpoints.size())
	  {
	 
	    if(equals(polx[i].x,cutpoints[j].x) && equals(polx[i].y,cutpoints[j].y))
	      {
		ok = true;
		break;
	      }
	  }
	if(ok)
	  ret.push_back(polx[i]);
      }

    /*
    cout << "ret ---" <<endl;
    rep(i,ret.size())
      {
	cout << ret[i].x << "," << ret[i].y << endl;
      }
    cout << endl;
    */
    return ret;
  }


  vector<Point> getPoints2(vector<Point>& points,int pos)
  {
    set<Point> polyS;
    for(int i=0;i<poly.size();i++)polyS.insert(poly[i]);
    Polygon polx = poly;
    int N = points.size();
    for(int i=0;i<N;i++)
      if(i != pos)
	polx = cutPolygon(polx,CreateLine(points[pos],points[i]));
    /*
    vector<Point> ret;
    const int MOD = 10000000;
    for(int i=0;i<polx.size();i++)
      {
	//if(polyS.find(polx[i]) == polyS.end())
	Point p;

	p.x = floor(polx[i].x*MOD);
	p.x /= MOD;

	p.y = floor(polx[i].y*MOD);
	p.y /= MOD;

	ret.push_back(p);
      }
    */
    return polx;
  }

};

bool check(vector<Point> &vec,Point p)
{
  rep(i,vec.size())
    {
      if(equals(vec[i].x,p.x) && equals(vec[i].y,p.y))return true;
    }
  return false;
}

int getIndex(vector<Point> &prep,Point p)
{
  rep(i,prep.size())
    {
      if(equals(prep[i].x,p.x) && equals(prep[i].y,p.y))
	{
	  return i;
	}
    }

  assert(false);
}

int n;
long double mincost[MAX][MAX];

int main()
{


  /*
  vector<Point> vec(4);
  vec[0] = Point(0,0);
  vec[1] = Point(4,0);
  vec[2] = Point(4,4);
  vec[3] = Point(0,4);

  vector<Point> points;
  points.push_back(Point(1,0.5));
  points.push_back(Point(1,2.5));
  points.push_back(Point(3,1.5));
  points.push_back(Point(3,3.5));
  //points.push_back();
  Voronoi vol(vec);
  vector<Point> that = vol.getPoints(points,1);

  cout << "the area = " << vol.getAreaOfVoronoi(points,1) << endl;

  cout << "that.size() = " << that.size() << endl;
  rep(i,that.size())
    cout << that[i].x << " " << that[i].y << endl; 
  */

  //clock_t start,end;
  //start = clock();
  
  while(cin >> n,n)
    {
      vector<Point> frame(4);
      frame[0] = Point(0,0);
      frame[1] = Point(4,0);
      frame[2] = Point(4,4);
      frame[3] = Point(0,4);
      set<Point> sp;
      rep(i,4)sp.insert(Point(frame[i]));

      Voronoi vol(frame);

      vector<Point> site(n);
      rep(i,n)cin >> site[i].x >> site[i].y;

      vector<Point> prep;
      vector<vector<Point> > material;
     
      rep(i,n)
	{
	  material.push_back(vol.getPoints2(site,i));
	  material[i].push_back(material[i][0]); 
	}



      rep(i,n)
	{
	  vector<Point> crossP = vol.getPoints(site,i);
	  //material.push_back(crossP);
	  rep(j,crossP.size())
	    {
	      bool ok = true;
	      rep(k,prep.size())
		{
		  if(equals(crossP[j].x,prep[k].x) && equals(crossP[j].y,prep[k].y))
		    {
		      ok = false;
		      break;
		    }		  
		}
	      if(ok)
		{
		  prep.push_back(crossP[j]);
		}
	    }
	}

      /*
      cout << "--------" << endl;
      rep(i,prep.size())
	cout << prep[i].x << "," << prep[i].y << endl;
      */
      int N = prep.size();
      vector<vector<double> > G(N,vector<double>(N));
      rep(i,N)rep(j,N)G[i][j] = (i==j?0:1000);
      map<Point,int> index;
      vector<int> ST,ED;


      //cout << "prep === " << endl;
      rep(i,(int)prep.size())
	{
	  //cout << "(" << prep[i].x << "," << prep[i].y << ")" << endl;
	  index[prep[i]] = i;
	  if(equals(prep[i].x,0))ST.push_back(i);
	  if(equals(prep[i].x,4))ED.push_back(i);
	}
      //cout <<"ST = " << ST.size() << ", ED = " << ED.size() << endl;


      
      if(ST.empty() || ED.empty())
	{
	  cout << "impossible" << endl;
	  continue;
	}
      


      rep(i,material.size())
	{
	  int prev = -1;
	  Point pp;
	  //cout << "|||||||||||||||||||||||||||||" << endl;
	  rep(j,material[i].size())
	    {
	      if(!check(prep,material[i][j]))
		{//frame に material[i][j] が含まれるならばアウト
		  prev = -1;
		  continue;	     
		}
	      if(prev == -1)
		{
		  int pes = getIndex(prep,material[i][j]);
		  pp = prep[pes];
		  prev = pes;
		  continue;
		}
	      int next = getIndex(prep,material[i][j]);
	      
	      //cout <<  prev << "(" << pp.x << "," << pp.y << ") is able to go to "<< next << "("<< prep[next].x << "," << prep[next].y << ")" << endl; 
	      if(prev == next)continue;
	      double cost = sqrt(pow(prep[next].x-pp.x,2)+pow(prep[next].y-pp.y,2));
	      G[prev][next] = cost;
	      G[next][prev] = cost;
	      prev = next;
	      pp = prep[next];
	    }
	}
 

      /*
      cout << "N--------------" << endl;
      rep(i,N)cout << "i = " << i << " : (" << prep[i].x << "," << prep[i].y << ")" <<endl;     

      cout << "G--------------" << endl;
      rep(i,N)
	{
	  rep(j,N)
	    {
	      cout.width(10);
	      cout << setiosflags(ios::fixed) << setprecision(10) << G[i][j] << " ";
	      //printf("%.10llf",G[i][j]);
	    }
	  cout << endl;
	}
      */



      for(int k=0;k<N;k++)for(int i=0;i<N;i++)for(int j=0;j<N;j++)G[i][j] = min(G[i][j],G[i][k]+G[k][j]);

      /*
      cout << "------------G-------------" << endl;
      rep(i,N)
	{
	  rep(j,N)
	    {
	      cout.width(10) ;
	      cout << setiosflags(ios::fixed) << setprecision(10) << G[i][j] << " ";
	    }
	  cout << endl;
	}
      cout << endl;
      */

      double ans = 1000;
      rep(i,ST.size())rep(j,ED.size())ans = min(ans,G[ST[i]][ED[j]]);
      cout << setiosflags(ios::fixed) << setprecision(12) << ans << endl;
    }
  //end = clock();
  //cout << setiosflags(ios::fixed) << setprecision(10) << (double)(end-start)/CLOCKS_PER_SEC << endl;

  return 0;
}