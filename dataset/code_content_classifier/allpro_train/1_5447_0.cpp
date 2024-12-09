#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;

pll add(const pll &a, const pll &b){
	return pll(a.first + b.first, a.second + b.second);
}

pll sub(const pll &a, const pll &b){
	return pll(a.first - b.first, a.second - b.second);
}

pll mul(LL t, const pll &a){
	return pll(a.first * t, a.second * t);
}

LL cross(const pll &a, const pll &b){
	return a.first * b.second - b.first * a.second;
}

LL div(const pll &a, const pll &b){
	if(b.first != 0){ return a.first / b.first; }
	return a.second / b.second;
}

vector<pll> input(int n){
	vector<pll> pts(n);
	for(int i = 0; i < n; ++i){
		cin >> pts[i].first >> pts[i].second;
	}
	rotate(pts.begin(), min_element(pts.begin(), pts.end()), pts.end());

	vector<pll> vec(n);
	for(int i = 0; i < n; ++i){
		vec[i] = sub(pts[i + 1], pts[i]);
	}
	vec[n - 1] = sub(pts[0], pts[n - 1]);
	return vec;
}

LL area(const vector<pll> &v){
	int n = v.size();
	pll p;
	LL s = 0;
	for(int i = 0; i < n; ++i){
		pll q = add(p, v[i]);
		s += cross(p, q);
		p = q;
	}
	return s;
}

int main(){
	int n, m;
	while(cin >> n >> m && n){
		vector<pll> v1 = input(n);
		vector<pll> v2 = input(m);
		if(area(v1) > area(v2)){ v1.swap(v2); }
		vector<int> idxs;
		while(true){
			int s1 = v1.size(), s2 = v2.size();
			idxs.assign(s1, -1);
			int j = 0;
			LL u = 1LL << 50;
			for(int i = 0; i < s1; ++i){
				for(; j < s2; ++j){
					if(cross(v1[i], v2[j]) == 0){ break; }
				}
				if(j >= s2){
					u = 0;
					break;
				}
				idxs[i] = j;
				LL t = div(v2[j], v1[i]);
				u = min(t, u);
				++j;
			}
			if(u <= 0){ break; }
			for(int i = 0; i < s1; ++i){
				int k = idxs[i];
				v2[k] = sub(v2[k], mul(u, v1[i]));
			}
			v2.erase(remove(v2.begin(), v2.end(), pll()), v2.end());
			v1.swap(v2);
		}
		LL a1 = area(v1);
		LL a2 = area(v2);
		cout << (a1 + a2) << endl;
	}
}
