#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

vector<LL> maketbl(const vector<int> &mp, const vector<int> &dmg, int mh){
	vector<LL> ret(mh + 1, 1LL << 50);
	ret[0] = 0;
	for(int i = 1; i <= mh; ++i){
		for(size_t j = 0; j < mp.size(); ++j){
			ret[i] = min(ret[i], ret[max(i - dmg[j], 0)] + mp[j]);
		}
	}
	return ret;
}

int main(){
	int n;
	while(scanf("%d", &n), n){
		vector<int> hp(n);
		int mh = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d", &hp[i]);
			mh = max(mh, hp[i]);
		}
		vector<int> mps, dmgs, mpa, dmga;
		int m;
		scanf("%d", &m);
		for(int i = 0; i < m; ++i){
			int d, p;
			char c;
			scanf("%*s%d %c%*s%d", &p, &c, &d);
			if(d){
				if(c == 'S'){
					mps.push_back(p);
					dmgs.push_back(d);
				}
				else{
					mpa.push_back(p);
					dmga.push_back(d);
				}
			}
		}
		vector<LL> tbls = maketbl(mps, dmgs, mh);
		vector<LL> tbla = maketbl(mpa, dmga, mh);
		LL ans = 1LL << 50;
		for(int i = 0; i <= mh; ++i){
			LL s = tbla[i];
			for(int j = 0; j < n; ++j){
				s += tbls[max(hp[j] - i, 0)];
			}
			ans = min(ans, s);
		}
		printf("%lld\n", ans);
	}
}