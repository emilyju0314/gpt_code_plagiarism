#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
#include <queue>

using namespace std;

#define For(i,a,n)	for(int i = a;i < n;i++)
#define rep(i,n)	For(i,0,n)
#define clr(n)		memset(n,0,sizeof n)
#define all(n)		(n).begin(),(n).end()

const int INF = 1e9;
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
bool cheak(int x, int y, int mx, int my){
	return x >= 0 && y >= 0 && x < mx &&  y < my;
}

int main()
{
	int n;
	cin >> n;
	rep(_, n){
		int h, w;
		char d[51][51];
		cin >> h >> w;
		rep(y, h)rep(x, w){
			cin >> d[y][x];
		}

		bool f = false;
		set<char> vs[256];
		For(ct, 'A', 'Z' + 1){
			int rx = -1, ry = -1;
			int lx = 51, ly = 51;
			rep(y, h)rep(x, w){
				if (d[y][x] == ct){
					lx = min(lx, x), ly = min(ly, y);
					rx = max(rx, x), ry = max(ry, y);
				}
			}
			set<char> v;
			For(y, ly, ry + 1)For(x, lx, rx + 1){
				if (d[y][x] == '.'){
					f = true; goto End;
				}
				if (d[y][x] != ct){
					v.insert(d[y][x]);
				}
			}
			vs[ct] = v;
		}
		rep(i, 256){
			if (vs[i].size()){
				queue<pair<char,vector<bool>>> q;
				for (auto j : vs[i]){
					vector<bool> cf(256, 0);
					cf[i] = true;
					cf[j] = true;
					q.push(make_pair(j,cf));
				}
				while (q.size()){
					auto now = q.front(); q.pop();
					for (auto j : vs[now.first]){
						auto tf = now.second;
						if (tf[j]){
							f = true; goto End;
						}
						tf[j] = true;
						q.push(make_pair(j,tf));
					}
				}
			}
		}
	End:;

		if (f)cout << "SUSPICIOUS" << endl;
		else  cout << "SAFE" << endl;

	}
	return 0;
}