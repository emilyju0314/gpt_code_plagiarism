#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
inline LL read() {
	LL x = 0, fl = 1; char c = getchar();
	while (c < '0' || c > '9') { if(c == '-') fl = -1; c = getchar(); }
	while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
	return x * fl;
}
const int N = 100010, M = 100010, mod = 1e9 + 7;
int n, m, k, top, t;

vector<int> a[30];
string s;
int main()
{
	t = read();
	while(t --) {
		n = read();
		cin >> s;
		for(int i = 0; i < n; i++) {
			a[s[i] - 'A'].push_back(i);
		}
		int fl = 1;
		for(int i = 0; i < 26; i++) {
			if(a[i].size()) {
				m = a[i].size();
				for(int j = 1; j < m; j++) {
					if(a[i][j] - a[i][j - 1] > 1) 
						fl = 0;
				}
			}
			a[i].clear();
		}
		if(fl) puts("YES");
		else puts("NO");
	}


	return 0;
}

