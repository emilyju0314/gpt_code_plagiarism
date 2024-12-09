#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

const int MX = 1005;
const int MM = 1000000007;

int D[MX];
ll F[MX], I[MX], FI[MX];
ll dp[2][MX][MX];
int N;

int main()
{
	F[0] = I[1] = FI[0] = 1;
	for(int i = 2; i < MX; i++) I[i] = (MM - MM/i) * I[MM%i] % MM;
	for(int i = 1; i < MX; i++) F[i] = F[i-1] * i % MM;
	for(int i = 1; i < MX; i++) FI[i] = FI[i-1] * I[i] % MM;
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", D+i);
	sort(D, D+N);
	if(D[0] >= 2) return !printf("%lld\n", F[N-1] * I[2] % MM);

	ll ans = 0;
	/*
	for(int i = 0; i < 1<<N; i++){
		ll mul = 1;
		int sz = 0, sum = 0, ch = 1;
		for(int j = 0; j < N; j++){
			if(~i&1<<j) continue;
			if(D[j] <= 1 ) ch = 0;
			mul = mul * (D[j]-1) % MM;
			sz++;
			sum += D[j]-2;
		}
		if( !ch || sum <= 0 || sz <= 2) continue;
		mul = mul * F[sz-1] % MM * F[N-sz-1] % MM * sum % MM;
		ans = (ans + mul) % MM;
	} // */
	
	auto S = dp[0], E = dp[1];
	S[0][0] = 1;
	for(int i = 1; i <= N; i++){
		memset(E, 0, sizeof dp[0]);
		E[0][0] = 1;
		for(int j = 1; j <= N; j++){
			if(D[i] >= 2){
				for(int k = 0; k <= 2*N; k++){
					E[j][k] = (S[j][k] + (k >= D[i]? S[j-1][k-D[i]] * (D[i]-1) : 0)) % MM;
				}
			}
			else{
				for(int k = 0; k <= 2*N; k++){
					E[j][k] = S[j][k];
				}
			}
		}
		swap(S, E);
	}
	for(int i = 3; i <= N; i++){
		for(int j = i*2+1; j <= N*2; j++){
			ans = (ans + S[i][j] * F[i-1] % MM * F[N-i-1] % MM * (j-i*2)) % MM;
		}
	}

	for(int i = 0; i < N; i++) ans = ans * FI[D[i]-1] % MM;
	printf("%lld\n", ans * I[2] % MM);
}
