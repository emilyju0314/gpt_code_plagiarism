#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll arr[1005][1005] = {};

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	
	string in[2000];
	for(int i = 0; i < n; i++) {
		cin >> in[i];
	}
	
	arr[0][1] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(in[i-1][j-1] == '.') {
				arr[i][j] = arr[i-1][j] + arr[i][j-1];
				arr[i][j] %= 1000000007;
			}
		}
	}
	
	printf("%lld\n", arr[n][m]);
}