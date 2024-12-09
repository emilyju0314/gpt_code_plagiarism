#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
 
using namespace std;
 
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define rep(i,n) REP(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(r) (r).begin(),(r).end()
#define rall(r) (r).rbegin(),(r).rend()
#define fi first
#define se second
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 

 
const int INF = 1000000;
const double EPS = 1e-8;
const int mod = 1e9 + 7;

const double PI = acos(-1);

int dx[] ={-1,0,1,0};
int dy[] ={0,-1,0,1};

struct Point
{
	double x, y;
	Point(){};
	Point(double x, double y):x(x), y(y){};

	Point operator - (const Point& p) const{
		return Point(x-p.x, y-p.y);
	}

	double getAng(){
		return atan2(y, x);
	}
	double getCross(const Point& p) const{
		return x*p.y-y*p.x;
	}
	double getDot(const Point& p) const{
		return x*p.x+y*p.y;
	}
};

struct Circle
{
	Point p;
	double r;
	Circle(){};
	Circle(double x, double y, double r):p(x, y), r(r){};
	Circle(Point p, double r) :p(p),r(r){};

};

struct Line{
	Point p;
	double ang;
	Line(){};
	Line(Point p1, Point p2):p(p1), ang((p2-p1).getAng()){};
	Line(Point p, double ang):p(p), ang(ang){};
};
	
int n;
Circle c[1010];
Point taro, oni;
Line l;
Point lv;

bool checkSigneCross(Point p){
	return lv.getCross(p-l.p) > 0;
}

Point getCrossPoint(Line L){
	Point ret;
	ret.x = L.p.x + 1000000 * cos(L.ang);
	ret.y = L.p.y + 1000000 * sin(L.ang);
	bool sign = checkSigneCross(L.p), sign2 = checkSigneCross(ret);
	sign2 = sign^sign2;
	//cout<<sign2<<endl;
	double l = 0.0, r = 1000000.0, m;
	rep(i, 1000){
		m = (l + r) / 2.0;
		ret.x = L.p.x + m * cos(L.ang) * (sign2?1:-1);
		ret.y = L.p.y + m * sin(L.ang) * (sign2?1:-1);
		if(checkSigneCross(ret) == sign) l = m;
		else r = m;
	}
	return ret;
}

bool checkInCircle(const Circle& C, const Point& P){
	Point p = C.p-P;
	return p.x*p.x+p.y*p.y < C.r*C.r + EPS;
}

bool check(){
	for(int i = 0; i < n; i++){
		if(checkInCircle(c[i], taro)^checkInCircle(c[i], oni)) return true;
		else if(checkInCircle(c[i], taro)&&checkInCircle(c[i], oni)) continue;
		Line l2(c[i].p, l.ang+PI/2.0);

		Point p =  getCrossPoint(l2);
		if(checkInCircle(c[i], p) && (taro-p).getDot(oni-p) < 0) return true;
	}
	return false;
}

int main(){
	int m;
	while(cin>>n && n){
		rep(i, n) cin>>c[i].p.x>>c[i].p.y>>c[i].r;
		cin>>m;
		rep(i, m){
			cin>>taro.x>>taro.y>>oni.x>>oni.y;
			l = Line(taro, oni);
			lv = Point(cos(l.ang), sin(l.ang));
			cout<<(check()?"Safe":"Danger")<<endl;
		}
	}
}