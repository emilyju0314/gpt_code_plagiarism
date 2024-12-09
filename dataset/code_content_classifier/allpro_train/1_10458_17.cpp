#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int n, a[N], b[N];
char s[N], t[N];

int main() {
	scanf("%d%s%s", &n, s + 1, t + 1);
	for (int i = 1; i < n; ++i) if (s[i] != s[i + 1]) a[++a[0]] = i;
	for (int i = 1; i < n; ++i) if (t[i] != t[i + 1]) b[++b[0]] = i;
	int ans = 1 << 30;
	for (int i = -a[0] - 1; i <= b[0] + 1; ++i)
		if ((i & 1) ^ (s[1] == t[1])) {
			int s = 0;
			for (int j = min(1, 1 - i); j <= max(a[0], b[0] - i); ++j)
				s += abs((j <= 0 ? 0 : j > a[0] ? n : a[j]) - (j + i <= 0 ? 0 : j + i > b[0] ? n : b[i + j]));
			ans = min(ans, s);
		}
	printf("%d\n", ans);
}
