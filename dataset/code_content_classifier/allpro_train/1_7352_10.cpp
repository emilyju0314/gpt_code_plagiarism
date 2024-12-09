#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;

using ld= long double;
ld eps=1e-9;

/* 幾何の基本 */

#include <complex>

typedef complex<ld> Point;


// 外積
ld cross(const Point& a, const Point& b) {
	return imag(conj(a) * b);
}

// 直線の定義
class Line {
public:
	Point a, b;
	Line() : a(Point(0, 0)), b(Point(0, 0)) {}
	Line(Point a, Point b) : a(a), b(b) {}
	Point operator[](const int _num)const {
		if (_num == 0)return a;
		else if (_num == 1)return b;
		else {
			assert(false);
			return Point();
		}
	}
};

// 直線と直線の交点
Point is_ll(const Line &s, const Line& t) {
	Point sv = s.b - s.a, tv = t.b - t.a;
	assert(cross(sv, tv) != 0);
	return s.a + sv * cross(tv, t.a - s.a) / cross(tv, sv);
}


bool connect(pair<long long int, long long int>l, pair<long long int,long long  int>r) {
	long long int dx=r.first-l.first;
	long long int dy=r.second-l.second;
	if (!dx || !dy || abs(dx) == abs(dy)) {
		return true;
	}
	else {
		return false;
	}
}

vector<pair<long long int, long long int>>kouhos(pair<long long int, long long int>l, pair<long long int, long long int>r) {

	vector<pair<long long int, long long int>>kouho;
	int dx[4] = { 1,1,1,0 };
	int dy[4] = { -1,0,1,1 };
	for (int way1 = 0; way1 < 4; ++way1) {
		for (int way2 = 0; way2 < 4; ++way2) {
			if(way1==way2)continue;
			Point p1(l.first,l.second);
			Line l1(p1,p1+Point(dx[way1],dy[way1]));
			Point p2(r.first,r.second);
			Line l2(p2,p2+Point(dx[way2],dy[way2]));
			Point sect(is_ll(l1,l2));
			long long int n=static_cast<long long int>(sect.real()+eps*100);
			if (abs(static_cast<long long int>(sect.real()+eps*100) - sect.real()) < 0.1) {
				kouho.push_back(make_pair(static_cast<long long int>(sect.real()+eps*100), static_cast<long long int>(sect.imag()+eps*100)));
			}
		}
	}
	return kouho;
}

int solve(vector<pair<long long int, long long int>>&bases, const pair<long long int, long long  int>&goal) {
	if(bases.size()==6)return 4;
	
	int ans=4;
	for (int i = 0; i < bases.size(); ++i) {
		if (bases[i] == goal) {
			ans=min(ans,int(bases.size())-2);
		}
		if (connect(bases[i], goal)) {
			ans=min(ans,int(bases.size())-2+2);
		}
		if(bases.size()==5)continue;
		for (int j = 0; j < bases.size(); ++j) {
			if(i==j)continue;
			pair<long long int, long long int>l(bases[i]);
			pair<long long int, long long int>r(bases[j]);
			if (connect(l, goal) && connect(r, goal)) {
				ans=min(ans,int(bases.size()-2+1));
			}
			if (connect(l, r)) {
				ans=min(ans,int(bases.size())-2+3);
			}
			else {
				if (bases.size() == 2) {
					auto cands(kouhos(l, r));
					for (auto cand : cands) {
						if (connect(cand, goal)) {
							ans=min(ans,3);
						}
					}
				}
				
			}
		}
	}
	return ans;
}
int main() {
	int Q;cin>>Q;
	while (Q--) {
		long long int x1,y1,x2,y2,X,Y;cin>>x1>>y1>>x2>>y2>>X>>Y;
		x1+=1e10;
		y1+=1e10;
		x2+=1e10;
		y2+=1e10;
		X+=1e10;
		Y+=1e10;
		vector<pair<long long int, long long int>>bases{ make_pair(x1,y1),make_pair(x2,y2) };
		pair<long long int, long long int>goal(X,Y);
		int ans=solve(bases,goal);
		cout<<ans<<endl;
	}
	return 0;
}
