#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MAXN = 200005;

int n; lint k;
int a[2 * MAXN];
int mp[2 * MAXN];
lint nxt[60][MAXN];

int main(){
	scanf("%d %lld",&n,&k);
	for(int i=0; i<n; i++) scanf("%d",&a[i]), a[i + n] = a[i];
	for(int i=2*n-1; i>=0; i--){
		if(i < n) nxt[0][i] = mp[a[i]] - i + 1;
		mp[a[i]] = i;
	}
	for(int i=1; i<60; i++){
		for(int j=0; j<n; j++){
			lint sum = nxt[i - 1][j];
			sum += nxt[i - 1][(j + sum) % n];
			sum = min(sum, (lint)1e18);
			nxt[i][j] = sum;
		}
	}
	lint pos = 0;
	for(int i=59; i>=0; i--){
		if(pos + nxt[i][pos % n] <= n * (k - 2)){
			pos += nxt[i][pos % n];
		}
	}
	while(pos < n * k){
		while(pos + nxt[0][pos % n] <= n * k){
			pos += nxt[0][pos % n];
		}
		if(pos == n * k) break;
		printf("%d ", a[pos % n]);
		pos++;
	}
}
