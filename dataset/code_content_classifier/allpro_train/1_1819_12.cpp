#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint n, k;
llint a[1<<20];

void zeta_transform(llint a[], int n)
{
	int S = 1<<n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < S; j++){
			if((j&(1<<i))) a[j] += a[j^(1<<i)];
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[1<<i];
	
	zeta_transform(a, n);
	for(int i = 0; i < (1<<n); i++){
		if(a[i] == k) a[i] = 1;
		else a[i] = 0;
	}
	zeta_transform(a, n);
	
	llint ans = n+1;
	for(int i = 0; i < (1<<n); i++){
		if(a[i]) continue;
		llint cnt = 0;
		for(int j = 0; j < n; j++){
			if(i & (1<<j)) cnt++;
		}
		ans = min(ans, n-cnt);
	}
	cout << ans << endl;
	
	return 0;
}
