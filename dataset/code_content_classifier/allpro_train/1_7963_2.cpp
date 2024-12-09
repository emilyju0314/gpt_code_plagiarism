#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

string b[128];
int cr[128][1024], cc[1024][128];
int mh;

struct glyph{
	char c;
	vector<string> v, r;
	void input(){
		int h, w;
		cin >> c >> h >> w;
		v.resize(h);
		r.resize(h);
		for(int i = 0; i < h; ++i){
			cin >> v[i];
			r[i] = string(v[i].rbegin(), v[i].rend());
		}
		mh = max(mh, h);
	}
	bool match_base(int y1, int x1, int y2, int x2, const vector<string> &a) const{
		int h = a.size(), w = a[0].size();
		if(y2 - y1 + 1 != h || x2 - x1 + 1 != w){ return false; }
		for(int i = 0; i < h; ++i){
			if(b[y1 + i].compare(x1, w, a[i])){ return false; }
		}
		return true;
	}
	bool match(int y1, int x1, int y2, int x2) const{
		return match_base(y1, x1, y2, x2, v);
	}
	bool rmatch(int y1, int x1, int y2, int x2) const{
		return match_base(y1, x1, y2, x2, r);
	}
};

vector<glyph> gs;

string term(int, int, int, int);

string seq(int y1, int x1, int y2, int x2){
	bool ex = false;
	vector<string> v;
	for(int j = x1; j <= x2 + 1; ++j){
		if(j <= x2 && cc[j][y2] - cc[j][y1 - 1]){
			ex = true;
		}
		else if(ex){
			ex = false;
			v.push_back(term(y1, x1, y2, j - 1));
			x1 = j + 1;
		}
	}

	int idx = 1;
	for(size_t i = 0; i < v.size(); ++i){
		if(v[i][0] == '_' && v[i][1] == '_'){
			idx = 2;
			break;
		}
	}
	for(size_t i = 0; i < v.size(); ++i){
		if(v[i][0] == '_'){
			v[i] = string(1, v[i][idx]);
		}
	}

	if(idx == 1){
		return accumulate(v.begin(), v.end(), string());
	}
	return accumulate(v.rbegin(), v.rend(), string());
}

string term(int y1, int x1, int y2, int x2){
	while(cr[y1][x2] - cr[y1][x1 - 1] == 0){ ++y1; }
	while(cr[y2][x2] - cr[y2][x1 - 1] == 0){ --y2; }
	while(cc[x1][y2] - cc[x1][y1 - 1] == 0){ ++x1; }
	while(cc[x2][y2] - cc[x2][y1 - 1] == 0){ --x2; }

	string ret;
	if(y2 - y1 + 1 > mh){
		ret = '[' + seq(y1 + 2, x1 + 2, y2 - 2, x2 - 2) + ']';
	}
	else{
		ret = "___";
		for(size_t i = 0; i < gs.size(); ++i){
			if(gs[i].match(y1, x1, y2, x2)){
				ret[1] = gs[i].c;
				break;
			}
		}
		for(size_t i = 0; i < gs.size(); ++i){
			if(gs[i].rmatch(y1, x1, y2, x2)){
				ret[2] = gs[i].c;
				break;
			}
		}
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);

	int n, m;
	string s;
	while(cin >> n >> m, n){
		mh = 0;
		gs.resize(n);
		for(int i = 0; i < n; ++i){
			gs[i].input();
		}
		for(int k = 1; k <= m; ++k){
			int h, w;
			cin >> h >> w;
			b[0].assign(w + 1, '.');
			for(int i = 1; i <= h; ++i){
				cin >> s;
				b[i] = '.' + s;
				for(int j = 1; j <= w; ++j){
					cr[i][j] = cr[i][j - 1] + (b[i][j] == '*');
					cc[j][i] = cc[j][i - 1] + (b[i][j] == '*');
				}
			}

			s = seq(1, 1, h, w);
			cout << s << '\n';
		}
		cout << "#\n";
	}
}