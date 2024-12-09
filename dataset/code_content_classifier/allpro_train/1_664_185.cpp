//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x7fffffff
#define INFL 0x7fffffffffffffffLL

vector<pair<ll,ll>> a(2000);
ll n;
ll dp[2000][2000];

ll calc(ll x, ll y) {
	int idx = x + ((n-1) - y);
	if (idx == n) return 0;
	if (dp[x][y]!=0) return dp[x][y];
	ll ans = max( abs(a[idx].second-x)*a[idx].first + calc(x+1 , y) , abs(a[idx].second-y)*a[idx].first + calc(x , y-1) );
	dp[x][y] = ans;
	return ans; 
}

int main() {
	ll		b,c,i,j,k,m,x,y,ans = 0;
	string	str;

	cin >> n;

	for(i=0;i<n;i++) {
		cin >> j;
		a[i] = make_pair(j , i);
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	x=0;
	y=n-1;

	ans = calc(x , y);

	cout << ans << endl;

}
