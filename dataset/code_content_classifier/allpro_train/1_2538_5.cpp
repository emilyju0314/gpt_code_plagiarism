#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <random>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
#define pb push_back
#define INF 2e15
#define mod 998244353
#define eps 1e-9
#define abs(x) ((x)>=0?(x):-(x))
#define y1 solai
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
const ll N=200100;
ll te,n,x,ans,k,s[N],a[N];
map<ll,ll>v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>te;
	for(;te--;)
	{
		cin>>n;
		ans=n;
		v.clear();
		for(ll i=1;i<=n;i++)
			cin>>x,v[x]++;
		k=0;
		for(auto cur:v)
			a[++k]=cur.se;
		sort(a+1,a+k+1);
		for(ll i=1;i<=k;i++)
			s[i]=s[i-1]+a[i];
		for(ll i=1;i<=k;i++)
			ans=min(ans,s[k]-(k-i+1)*a[i]);
		cout<<ans<<"\n";
	}
}
/*
5
LRLDD
*/