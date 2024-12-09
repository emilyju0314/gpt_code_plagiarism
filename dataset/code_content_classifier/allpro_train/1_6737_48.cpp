#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 3030;



int n, m;
string s;
int a[maxn];
int b[maxn];
ll dp[maxn][maxn];//# ways to fill first i elems, holding j 1's



void add(ll& x, ll y) {
    x %= mod;
    y %= mod;
    x += y;
    x %= mod;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n>>m;
    cin>>s;
    for (int i=0; i<n; i++) {
	a[i]=(s[i]-'0');
	b[i]=i+1;
    }

    for (int i=0; i<m; i++) {
	int l,r; cin>>l>>r;
	--l; --r;
	b[l]=max(b[l],r+1);
    }

    for (int i=1; i<n; i++) {
	b[i]=max(b[i],b[i-1]);
    }

    dp[0][0]=1;
    for (int i=0, j=0; i<n; i++) {
	int ones = 0;
	while (j<b[i]) ones+=a[j++];

	for (int x=0; x<=n; x++) {
	    if (dp[i][x] == 0) continue;
	    int cur=x+ones;

	    //put 1 at ith index
	    if (cur!=0) {
		add(dp[i+1][cur-1], dp[i][x]);
	    }

	    // put 0 at ith index
	    if (j-i != cur) {
		add(dp[i+1][cur], dp[i][x]);
	    }
	}
    }

    ll ans = dp[n][0];
    ans %= mod;
    ans += mod;
    ans %= mod;
    cout<<ans<<endl;
  

    return 0;
}
