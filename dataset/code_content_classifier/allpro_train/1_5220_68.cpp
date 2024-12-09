#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;

int n, a, b;
char s[maxn];
int l[maxn], r[maxn], tot;

void work() {
	tot = 0;
	l[++tot] = 0;
	for(int i = 1; i < n; ++i) {
		if(s[i] == s[i - 1]) continue;
		else {
			r[tot] = i - 1;
			l[++tot] = i;
		}
	}
	r[tot] = n - 1;
	
	if(b > 0) {
		cout << a * n + b * n << "\n";
	}
	else {
		cout << a * n + b * (tot / 2 + 1) << "\n";
	}
	
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		cin >> n >> a >> b >> s;
		work();
	}
	
	
	
	return 0;
}

