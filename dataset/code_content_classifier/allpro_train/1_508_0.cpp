#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
bool eq(ld a, ld b) {
	return (abs(a - b) < eps);
}
//内積
ld dot(Point a, Point b) {
	return real(conj(a)*b);
}
//外積
ld cross(Point a, Point b) {
	return imag(conj(a)*b);
}
//線分
//直線にするなら十分通い２点を端点とすればよい
class Line {
public:
	Point a, b;
};
//円
class Circle {
public:
	Point p;
	ld r;
};
//3点の位置関係
int ccw(Point a, Point b, Point c) {
	b -= a; c -= a;
	if (cross(b, c) > eps)return 1;//a,b,cが反時計回り
	if (cross(b, c) < -eps)return -1;//a,b,cが時計回り
	if (dot(b, c) < 0)return 2;//c,a,bの順に一直線
	if (norm(b) < norm(c))return -2;//a,b,cの順に一直線
	return 0;//a,c,bの順に一直線
}
//2直線の交差判定
bool isis_ll(Line l, Line m) {
	return !eq(cross(l.b - l.a, m.b - m.a), 0);
}
//直線と線分の交差判定
bool isis_ls(Line l, Line s) {
	return (cross(l.b - l.a, s.a - l.a)*cross(l.b - l.a, s.b - l.a) < eps);
}
//点が直線上に存在するか
bool isis_lp(Line l, Point p) {
	return (abs(cross(l.b - p, l.a - p)) < eps);
}
//点が線分上に存在するか
bool isis_sp(Line s, Point p) {
	return (abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps);
}
//線分と線分の交差判定
bool isis_ss(Line s, Line t) {
	if (isis_sp(s, t.a) || isis_sp(s, t.b) || isis_sp(t, s.a) || isis_sp(t, s.b))return true;
	return(cross(s.b - s.a, t.a - s.a)*cross(s.b - s.a, t.b - s.a) < -eps&&cross(t.b - t.a, s.a - t.a)*cross(t.b - t.a, s.b - t.a) < -eps);
}
//点から直線への垂線の足
Point proj(Line l, Point p) {
	ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
	return l.a + t * (l.a - l.b);
}
//直線と直線の交点
//平行な２直線に対しては使うな！！！！
Point is_ll(Line s, Line t) {
	Point sv = s.b - s.a; Point tv = t.b - t.a;
	return s.a + sv * cross(tv, t.a - s.a) / cross(tv, sv);
}
//直線と点の距離
ld dist_lp(Line l, Point p) {
	return abs(p - proj(l, p));
}
//直線と直線の距離
ld dist_ll(Line l, Line m) {
	return isis_ll(l, m) ? 0 : dist_lp(l, m.a);
}
//線分と直線の距離
ld dist_ls(Line l, Line s) {
	return isis_ls(l, s) ? 0 : min(dist_lp(l, s.a), dist_lp(l, s.b));
}
//線分と点の距離
ld dist_sp(Line s, Point p) {
	Point r = proj(s, p);
	return isis_sp(s, r) ? abs(p-r) : min(abs(p-s.a),abs(p-s.b));
}
//線分と線分の距離
ld dist_ss(Line s, Line t) {
	if (isis_ss(s, t))return 0;
	return min({ dist_sp(s,t.a),dist_sp(s,t.b),dist_sp(t,s.a),dist_sp(t,s.b) });
}
Point turn(Point x, ld r) {
	Point res;
	ld nx = real(x)*cos(r) - imag(x)*sin(r);
	ld ny = real(x)*sin(r) + imag(x)*cos(r);
	res = { nx,ny };
	return res;
}
struct edge { int to; ld cost; };
typedef pair<ld, int> speP;
int main(){
	cout << fixed << setprecision(10) << endl;
	int n, s, g;
	while (cin >> n >> s >> g, n) {
		s--; g--;
		Line l[100][5];
		rep(i, n) {
			ld x, y, a, r; cin >> x >> y >> a >> r;
			a = a * pi / 180.0;
			Point now = { 0,r };
			now = turn(now, a);
			Point c[5];
			rep(j, 5) {
				c[j] = { real(now) + x,imag(now) + y };
				now = turn(now, 2.0 * pi / 5.0);
			}
			l[i][0] = { c[0],c[2] };
			l[i][1] = { c[0],c[3] };
			l[i][2] = { c[1],c[3] };
			l[i][3] = { c[1],c[4] };
			l[i][4] = { c[2],c[4] };
		}
		vector<edge> G[100];
		rep(i, n) {
			Rep(j, i + 1, n) {
				ld cost = 100000;
				rep(k1, 5) {
					rep(k2, 5) {
						cost = min(cost, dist_ss(l[i][k1], l[j][k2]));
					}
				}
				G[i].push_back({ j,cost });
				G[j].push_back({ i,cost });
			}
		}
		ld d[100];
		rep(i, n) {
			d[i] = 1000000;
		}
		priority_queue<speP> q;
		q.push({ 0,s }); d[s] = 0;
		while (!q.empty()) {
			speP x = q.top(); q.pop();
			int v = x.second;
			if (x.first > d[v])continue;
			int len = G[v].size();
			rep(j, len) {
				int nex = G[v][j].to;
				ld c = G[v][j].cost;
				if (d[nex] > d[v] + c) {
					d[nex] = d[v] + c;
					q.push({ d[nex],nex });
				}
			}
		}
		cout << d[g] << endl;
	}
	return 0;
}
