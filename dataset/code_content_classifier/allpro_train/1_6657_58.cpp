#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
const int    INF = 100000000;
const double EPS = 1e-10;
const int    MOD = 1000000007;
using namespace std;
typedef pair<int,int> P;

struct range{
	int st, en;
} pos[1000];

int n, w, d;
map<int,vector<int> > m;
map<int,vector<int> >::iterator it;
map<int,int> nxt;
vector<int> xx[2000];
bool saw[1000];

int main(){
	cin >> n >> w >> d;
	rep(i,n){
		int x, y; char f;
		cin >> x >> y >> f;
		y = d-y;
		if(f == 'N'){
			if(w-x < y){
				//pos[i].st = P(w,y-w+x);
				pos[i].st = w+d*2-(y-w+x);
			} else{
				//pos[i].st = P(x+y,0);
				pos[i].st = w*2+d*2-(x+y);
			}
			if(x < y){
				//pos[i].en = P(0,y-x);
				pos[i].en = y-x;
			} else{
				//pos[i].en = P(x-y,0);
				pos[i].en = w*2+d*2-(x-y);
			}
		} else if(f == 'E'){
			if(w-x < d-y){
				//pos[i].st = P(w,y+w-x);
				pos[i].st = w+d*2-(y+w-x);
			} else{
				//pos[i].st = P(x+d-y,d);
				pos[i].st = d+x+d-y;
			}
			if(w-x < y){
				//pos[i].en = P(w,y-w+x);
				pos[i].en = w+d*2-(y-w+x);
			} else{
				//pos[i].en = P(x+y,0);
				pos[i].en = w*2+d*2-(x+y);
			}
		} else if(f == 'W'){
			if(x < y){
				//pos[i].en = P(0,y-x);
				pos[i].st = y-x;
			} else{
				//pos[i].en = P(x-y,0);
				pos[i].st = w*2+d*2-(x-y);
			}
			if(x < d-y){
				//pos[i].en = P(0,y+x);
				pos[i].en = y+x;
			} else{
				//pos[i].en = P(x+y-d,d);
				pos[i].en = d+x+y-d;
			}
		} else{
			if(x < d-y){
				//pos[i].en = P(0,y+x);
				pos[i].st = y+x;
			} else{
				//pos[i].en = P(x+y-d,d);
				pos[i].st = d+x+y-d;
			}
			if(w-x < d-y){
				//pos[i].st = P(w,y+w-x);
				pos[i].en = w+d*2-(y+w-x);
			} else{
				//pos[i].st = P(x+d-y,d);
				pos[i].en = d+x+d-y;
			}
		}
		//cout << pos[i].st << " " << pos[i].en  << endl;
		m[pos[i].st].push_back(i);
		m[pos[i].en].push_back(i);
	}
	int cnt = 0;
	for(it = m.begin(); it != m.end(); it++){
		vector<int> v = (*it).second;
		xx[cnt] = v;
		nxt[(*it).first] = cnt;
		cnt++;
	}
	int ans = INF;
	rep(i,cnt){
		int counter = 1;
		rep(j,n) saw[j] = false;
		rep(j,xx[i].size()){
			saw[xx[i][j]] = true;
		}
		map<int,int> tmp;
		for(int j = i+1; j < cnt; j++){
			rep(k,xx[j].size()){
				if(saw[xx[j][k]]) continue;
				if(nxt[pos[xx[j][k]].en] == j){
					if(tmp[xx[j][k]] == 1){
						tmp.clear();
						counter++;
						break;
					}
				} else{
					tmp[xx[j][k]] = 1;
				}
			}
		}
		for(int j = 0; j < i; j++){
			rep(k,xx[j].size()){
				if(saw[xx[j][k]]) continue;
				if(nxt[pos[xx[j][k]].en] == j){
					if(tmp[xx[j][k]] == 1){
						tmp.clear();
						counter++;
						break;
					}
				} else{
					tmp[xx[j][k]] = 1;
				}
			}
		}
		ans = min(ans,counter);
	}
	cout << ans << endl;
}