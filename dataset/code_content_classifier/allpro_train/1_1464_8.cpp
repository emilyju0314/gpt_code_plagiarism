#include <bits/stdc++.h>
using namespace std;
#define int long long
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
#define ZIP(v) sort(all(v)),UNIQUE(v)
#define ADD(a, b) a = (a + b) % mod
#define SUB(a, b) a = (a+mod-b)%mod
#define MUL(a, b) a = (a * b) % mod
#define repi(i,m,n) for(int i = m;i < n;i++)
#define drep(i,n,m) for(int i = n;i >= m;i--)
#define rep(i,n) repi(i,0,n)
#define rrep(i,n) repi(i,1,n+1)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
#define dmp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define fi first
#define se second
typedef pair<int,int> P;
typedef pair<int, P> PP;
typedef pair<P, int> Pi;
typedef vector<int> vi;
typedef deque<int> dq;
const int inf = 1e9+7;
const int INF = 1e18+7;

int a[2000][2000];
vector<string> str;
signed main(){
	int h, w, ans = 1;
	scanf("%lld%lld", &w, &h);
	str.resize(h);
	rep(i,h)rep(j,w)scanf("%lld",&a[i][j]);
	rep(i,h)rep(j,w)str[i].pb('0'+a[i][j]);
	ZIP(str);
	if(str.size() != 2){printf("no\n");return 0;}
	int cnt[2] = {};
	rep(i,2)rep(j,w)if(str[i][j] == '1')cnt[i]++;
	if(llabs(cnt[0]-cnt[1]) > 1){printf("no\n");return 0;}
	rep(j,w)if(str[0][j] == str[1][j])ans = 0;
	printf("%s\n", ans == 1 ? "yes" : "no");
	rep(i,str.size()){
		//cout << str[i] << endl;
	}
	return 0;
}
/*
3 3
1 1 0
0 1 1
1 1 0
*/





