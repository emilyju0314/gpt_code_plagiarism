#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
const int maxn = 205;

int x[maxn],y[maxn];

long long ans[maxn];

const int mod = 998244353;

int qpow(int x,int n){
	int ret = 1;
	while(n > 0){
		if(n & 1){
			ret = 1LL * ret * x % mod;
		}
		x = 1LL * x * x % mod;
		n >>= 1;
	}
	return ret;
}

void upd(long long &a,int b){
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
}

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		scanf("%d%d",x + i,y + i);
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++) if(j != i){
			int num = 2;
			for(int k = 1;k <= n;k++) if(k != i && k != j){
				if((x[k] - x[i]) * (y[j] - y[i]) - (x[j] - x[i]) * (y[k] - y[i]) == 0) num++;	
			}
			upd(ans[num],(qpow(2,num) - 1 - num + mod) % mod);
		}
	}
	long long res = 0;
	upd(res,qpow(2,n));
	upd(res,-n-1);
	for(int i = 1;i <= n;i++){
		int tmp = ans[i] * qpow(i,mod - 2) % mod * qpow(i - 1,mod - 2) % mod;
		upd(res,-tmp);
	}
	cout << res << endl;
	return 0;
}
