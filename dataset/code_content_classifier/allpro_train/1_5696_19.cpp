#include<bits/stdc++.h>
using namespace std;

const int G = 3 , P = 998244353 , _ = 1 << 14 | 1; int N , M , dp[_] , fac[_] , ifac[_] , A[_] , B[_];
int poww(long long a , int b){int tms = 1; while(b){if(b & 1) tms = tms * a % P; a = a * a % P; b >>= 1;} return tms;}
int binom(int a , int b){return 1ll * fac[a] * ifac[b] % P * ifac[a - b] % P;}

int dir[_] , w[_] , need , invnd;
void init(int len){
	need = 1; while(need < len) need <<= 1;
	invnd = poww(need , P - 2);
	for(int i = 1 ; i < need ; ++i) dir[i] = (dir[i >> 1] >> 1) | (i & 1 ? need >> 1 : 0);
	for(int i = 1 ; i < need ; i <<= 1){
		w[i] = 1; int wn = poww(G , P / 2 / i);
		for(int j = 1 ; j < i ; ++j) w[i + j] = 1ll * w[i + j - 1] * wn % P;
	}
}

void DFT(int *arr , int tp){
	for(int i = 1 ; i < need ; ++i) if(i < dir[i]) swap(arr[i] , arr[dir[i]]);
	for(int i = 1 ; i < need ; i <<= 1)
		for(int j = 0 ; j < need ; j += i << 1)
			for(int k = 0 ; k < i ; ++k){
				int x = arr[j + k] , y = 1ll * arr[i + j + k] * w[i + k] % P;
				arr[j + k] = (x + y) % P; arr[i + j + k] = (x - y + P) % P;
			}
	if(tp == -1){
		reverse(arr + 1 , arr + need);
		for(int i = 0 ; i < need ; ++i)
			arr[i] = 1ll * arr[i] * invnd % P;
	}
}

int main(){
	cin >> N >> M; fac[0] = 1; for(int i = 1 ; i <= N + 2 ; ++i) fac[i] = 1ll * fac[i - 1] * i % P;
	ifac[N + 2] = poww(fac[N + 2] , P - 2); for(int i = N + 1 ; ~i ; --i) ifac[i] = ifac[i + 1] * (i + 1ll) % P;
	init(2 * N + 10); dp[0] = 1; for(int i = 3 ; i <= N + 2 ; ++i) B[i] = ifac[i];
	DFT(B , 1);
	for(int i = 1 ; i <= M ; ++i){
		memset(A , 0 , sizeof(A)); for(int j = 0 ; j <= N ; ++j) A[j] = 1ll * dp[j] * ifac[j] % P;
		DFT(A , 1); for(int j = 0 ; j < need ; ++j) A[j] = 1ll * A[j] * B[j] % P;
		DFT(A , -1); for(int j = 0 ; j <= N ; ++j) dp[j] = (dp[j] * (binom(j + 1 , 2) + 1ll) + 1ll * A[j + 2] * fac[j + 2]) % P;
	}
	int sum = 0; for(int i = 0 ; i <= N ; ++i) sum = (sum + 1ll * binom(N , i) * dp[i]) % P;
	cout << sum; return 0;
}
