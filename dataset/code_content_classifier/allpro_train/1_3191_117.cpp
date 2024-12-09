#include <iostream>
#include <complex>
#include <vector>
#include <utility>
using namespace std;

using Float = double;
using Point = complex<Float>;

vector<Point> ps;

const Float radius = 1.0;
const Float EPS = 1e-8;

int calc(Point c){
	int ret = 0;
	for(const Point &p : ps){
		if(abs(p - c) <= radius + EPS) ret++;
	}
	return ret;
}

signed main(){
	int n;
	while(cin >> n,n){
		ps.clear();
		for(int i = 0;i < n;i++){
			Float x,y;
			cin >> x >> y;
			ps.emplace_back(x,y);
		}
		int ans = 1;
		for(int i = 0;i < n;i++){
			for(int j = i + 1;j < n;j++){
				if(abs(ps[i] - ps[j]) >= radius * 2) continue;
				Point mid = (ps[i] + ps[j]) / 2.0;
				Point vect = Point(imag(ps[i] - ps[j]),-real(ps[i] - ps[j]));
				Float dist = sqrt(1.0 - norm(mid - ps[i]));
				ans = max(ans,max(calc(mid + vect / abs(vect) * dist),calc(mid - vect / abs(vect) * dist)));
			}
		}
		cout << ans << endl;
	}
}
