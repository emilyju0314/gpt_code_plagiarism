#include<iostream>
#include<algorithm>

using namespace std;
typedef long long Int;
#define MOD 998244353LL;

Int cmemo[4000][4000];

Int C(Int x, Int y){
	if(x < y)return 0;
	Int &res = cmemo[x][y];
	if(res != -1)return res;
	if(y == 0 || x == y)return res = 1;
	return res = (C(x-1, y) + C(x-1, y-1)) % MOD;
}

Int cnt(Int n, Int k){
	if(n < 0)return 0;
	return C(n+k-1, n);
}

Int solve(Int n, Int ban, Int k){
	Int res = 0;
	Int p = 1;
	for(Int i = 1;i <= ban;i++){
		res += p * C(ban, i) * cnt(n-2*i,k) % MOD;res %= MOD;
		p *= -1;
	}
	if(res < 0)res += MOD;
	return cnt(n, k) - res;
}

int cnthoge(int x, int k){
	int res = 0;
	for(int i = 1;i <= k;i++){
		int kk = x - i;
		if(0 < kk && kk <= k && kk != i)res++;
	}
	return res / 2;
}

int main(){
	Int k, n;
	for(int i = 0;i < 4000;i++)
		for(int j = 0;j < 4000;j++)
			cmemo[i][j] = -1;
	cin >> k >> n;
	for(int i = 2;i <= 2*k;i++){
		Int res = 0;
		if(i % 2 == 0){
			res += solve(n,cnthoge(i, k), k-1);
			res += solve(n-1,cnthoge(i, k), k-1);
			res %= MOD;
		}
		else{
			res += solve(n, cnthoge(i, k), k);
		}
		res %= MOD;
		if(res < 0)res += MOD;
		cout << res << endl;
	}
	return 0;
}