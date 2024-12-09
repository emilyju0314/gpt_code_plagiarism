#include<bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
	ll n;
	cin >> n;
	vector<ll> cnt(n+1);

	for(int i = 1;i*i<=n;i++)
		for(int j = 1;j*j<=n;j++)
			for(int k = 1;k*k<=n;k++)
			{
				ll now = i*i+j*j+k*k+i*j+j*k+i*k;
				if(now>n)continue;
				cnt[now] ++ ;
			}
	for(int i = 1;i<=n;i++)cout << cnt[i] << endl;
}
