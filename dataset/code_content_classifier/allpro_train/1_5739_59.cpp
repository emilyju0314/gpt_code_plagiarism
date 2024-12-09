#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define pii pair <int , int>
#define mp make_pair
#define fs first
#define sc second
using namespace std;
typedef long long LL;

template <typename T>
void read(T &x) {
	T f=1;x=0;char s=getchar();
	while(s<'0'||s>'9') {if(s=='-') f=-1;s=getchar();}
	while(s>='0'&&s<='9') {x=(x<<3)+(x<<1)+(s^'0');s=getchar();}
	x *= f;
}

template <typename T>
void write(T x , char s='\n') {
	if(!x) {putchar('0');putchar(s);return;}
	if(x<0) {putchar('-');x=-x;}
	T t = 0 , tmp[25] = {};
	while(x) tmp[t ++] = x % 10 , x /= 10;
	while(t -- > 0) putchar(tmp[t] + '0');
	putchar(s);
}

const LL mod = 1e9 + 7;

LL dp[105][10005] , c[105] , b[105] , n , x , Sum[105] , Sc[105];

map <int , LL> ans;

LL solve(LL x) {
	for (int i = 0; i <= Sc[n]; ++i) dp[0][i] = 1;
	for (int i = 1; i <= n; ++i) {
		memset(dp[i] , 0 , sizeof dp[i]);
		for (int j = max(0ll , Sum[i] + i * x); j <= Sc[i]; ++j) {
			if(j <= c[i]) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = (dp[i - 1][j] - dp[i - 1][j - c[i] - 1] + mod) % mod;
		}
		for (int j = 1; j <= Sc[n]; ++j) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
	}
	return dp[n][Sc[n]];
}

int main() {
	read(n);
	LL ans1 = 1 , num = 0;
	for (int i = 1; i <= n; ++i) read(c[i]) , num += c[i] , Sc[i] = Sc[i - 1] + c[i] , ans1 = ans1 * (c[i] + 1) % mod;
	for (int i = 1; i < n; ++i) read(b[i]) , b[i] += b[i - 1];
	for (int i = 2; i <= n; ++i) Sum[i] = Sum[i - 1] + b[i - 1];
	LL l = 0 , r = 1e9;
	for (int i = 1; i <= n; ++i) 
		l = min(l , -(Sum[i] + i - 1) / i + 1) , r = min(r , (num - Sum[i]) / i);
	for (int i = l; i <= r; ++i) 
		ans[i] = solve(i);
	int Q;
	read(Q);
	while(Q -- > 0) {
		int x;
		read(x);
		if(x < l) write(ans1);
		else if(x > r) write(0);
		else write(ans[x]);
	}
	return 0;
}