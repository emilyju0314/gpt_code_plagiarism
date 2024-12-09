#include <bits/stdc++.h>

using namespace std;

int n, cur = 200002, id = 0;
char x[200005];
vector<int> v[400006];
long long ans;

int main() {
	scanf("%s", x);
	n = strlen(x);
	v[cur].push_back(id);
	for (int i = 0; i < n; i++) {
		if (x[i] == '(')
			v[++cur].push_back(++id);
		else if (x[i] == ')') {
			v[--cur].push_back(++id);
			int tmp = v[cur - 1].empty() ? -1 : v[cur - 1].back();
			ans += v[cur].end() - lower_bound(v[cur].begin(), v[cur].end(), tmp) - 1;
		} else {
			int tmp = v[cur - 1].empty() ? -1 : v[cur - 1].back();
			ans -= v[cur].end() - lower_bound(v[cur].begin(), v[cur].end(), tmp) - 1;
			v[cur].pop_back();
			id--;
			if (v[cur + 1].empty() || v[cur + 1].back() != id)
				cur--;
			else
				cur++;
		}
		printf("%lld\n", ans);
	}
}

