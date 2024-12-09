#include <bits/stdc++.h>
using namespace std;

const int N = 100005, M = int(1e9) + 7;

int n, c[26], r = 1;
char s[N];

int main(){
	scanf("%d%s", &n, s);
	for(int i = 0; i < n; i++) c[s[i] - 'a']++;
	for(int i = 0; i < 26; i++) r = 1LL * r * (c[i] + 1) % M;
	printf("%d\n", (r + M - 1) % M);
}