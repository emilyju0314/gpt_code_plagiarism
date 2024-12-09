#include <iostream>
#include <vector>
#include <utility>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define eps 1e-9

using namespace std;
typedef pair<double, int> P;

struct vec2d{
	double x, y;
	vec2d(){}
	vec2d(double x, double y){
		this->x = x, this->y = y;
	}
	double add(double a, double b){
		if(fabs(a+b) < eps * (fabs(a) + fabs(b))) return 0.0;
		return a+b;
	}
	vec2d operator+(vec2d ope){
		return vec2d(add(x, ope.x), add(y, ope.y));
	}
	vec2d operator-(vec2d ope){
		return vec2d(add(x, -ope.x), add(y, -ope.y));
	}
	vec2d operator*(double t){
		return vec2d(x*t, y*t);
	}
	vec2d operator/(double t){
		return vec2d(x/t, y/t);
	}
	double dot(vec2d ope){
		return add(x*ope.x, y*ope.y);
	}
	double cross(vec2d ope){
		return add(x*ope.y, -y*ope.x);
	}
	double norm(){
		double d2 = dot(*this);
		if(d2 > 0) return sqrt(d2);
		return 0.0;
	}
};

double distPP(vec2d p, vec2d q){
	return (p-q).norm();
}

double distSP(vec2d p, vec2d q, vec2d x)
{
	if((x-p).dot(q-p) <= 0) return distPP(p, x);
	if((x-q).dot(p-q) <= 0) return distPP(q, x);
	return fabs( (x-p).cross(q-p) / distPP(p, q) );
}

int n;
vec2d p[105];
double r[105];
vector<P> vec[105];
bool used[105];

void getCrossPoint(vec2d c1, double r1, vec2d c2, double r2, vec2d &lp, vec2d &rp)
{
	vec2d v = c2 - c1, n;
	//cout << v.x << " " << v.y << endl;
	double d = v.norm();
	double x = (r1*r1-r2*r2+d*d)/(2*d);
	if(x >= 0){
		v =  v * (x / v.norm());
		n = vec2d(-v.y, v.x);
		n = n * (sqrt(r1*r1 - x*x) / n.norm());
		lp = c1 + v - n, rp = c1 + v + n;
	}
	else{
		x *= -1;
		v =  v * (x / v.norm()) * -1;
		n = vec2d(-v.y, v.x);
		n = n * (sqrt(r2*r2 - (d+x)*(d+x)) / n.norm());
		lp = c1 + v + n, rp = c1 + v - n;

	}
}

int main(void)
{
  while(1){
    cin >> n;
    if(n == 0) break;

    for(int i = 0; i < n; i++){
      cin >> p[i].x >> p[i].y >> r[i];
    }

		for(int i = 0; i < n; i++) used[i] = false;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i == j || used[j]) continue;
				if(distPP(p[i], p[j]) <= (r[j] - r[i])) used[i] = true;
			}
		}

		double ans = 0;
		for(int i = 0; i < n; i++){
			if(!used[i]) ans += 2 * M_PI * r[i];
		}

		vec2d lp, rp;
		for(int i = 0; i < n; i++) vec[i].clear();
		for(int i = 0; i < n; i++){
			if(used[i]) continue;
			for(int j = 0; j < n; j++){
				if(i == j || used[j]) continue;
				if(distPP(p[i], p[j]) >= r[i]+r[j]) continue;
				getCrossPoint(p[i], r[i], p[j], r[j], lp, rp);
				//cout << i << " " << j << endl;
				//cout << lp.x << "," << lp.y << " " << rp.x << "," << rp.y << endl;
				lp = lp - p[i], rp = rp - p[i];
				//cout << lp.x << "," << lp.y << " " << rp.x << "," << rp.y << endl;
				double lang = atan2(lp.y, lp.x), rang = atan2(rp.y, rp.x);
				if(lang < rang){
					vec[i].push_back(P(lang, 1));
					vec[i].push_back(P(rang, 2));
				}
				else{
					vec[i].push_back(P(lang, 1));
					vec[i].push_back(P(M_PI, 2));
					vec[i].push_back(P(-M_PI, 1));
					vec[i].push_back(P(rang, 2));
				}
			}
			sort(vec[i].begin(), vec[i].end());
			/*cout << i << endl;
			for(int j = 0; j < vec[i].size(); j++){
				cout << vec[i][j].first << " " << vec[i][j].second << endl;
			}*/

			int cnt = 0; double pre;
			for(int j = 0; j < vec[i].size(); j++){
				if(vec[i][j].second == 1){
					if(cnt == 0) pre = vec[i][j].first;
					cnt++;
				}
				else{
					if(cnt == 1) ans -= r[i] * (vec[i][j].first - pre);
					cnt--;
				}
			}
		}

		printf("%.11f\n", ans);
  }

	return 0;
}

