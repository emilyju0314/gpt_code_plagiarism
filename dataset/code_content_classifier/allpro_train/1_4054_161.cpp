#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#include <vector>
typedef long long ll;
typedef pair<ll, ll> PLL;
const int MAXN = 150005;
const ll INF = 1e12;
int n;
int son[MAXN][2], fa[MAXN], s[MAXN], val[MAXN];
int siz[MAXN]; ll dis[MAXN], mid;

vector<PLL> v[MAXN];
PLL ord[MAXN]; int tot;

void dfs_init(int o) {
    dis[o] = dis[fa[o]] + val[o], siz[o] = 1, s[o] = 0;
    if (!son[o][0]) {
        v[o].resize(1);
        return;
    }
    dfs_init(son[o][0]), dfs_init(son[o][1]);
    siz[o] += siz[son[o][0]] + siz[son[o][1]];
    v[o].resize(min(siz[son[o][0]], siz[son[o][1]]) << 1);
}

void insert(ll x, ll y) {
    ord[tot++] = make_pair(x, y);
}

bool dfs(int o) {
    if (!son[o][0]) {
        tot = 0, insert(dis[o], dis[o]), s[o] = tot;
        for (int i = 0; i < tot; i++)
            v[o][i] = ord[i];
        return 1;
    }
    int ls = son[o][0], rs = son[o][1];
    if (!dfs(ls) || !dfs(rs))
        return 0;
    if (s[ls] > s[rs])
        swap(ls, rs);
    for (int i = tot = 0, j = s[rs] - 1; i < s[ls] && ~j; i++) {
        while (~j && v[ls][i].first + v[rs][j].first - (dis[o] << 1) > mid)
            j--;
        if (j >= 0) {
            insert(v[ls][i].second, v[rs][j].second);
            insert(v[rs][j].second, v[ls][i].second);
        }
    }
    if (!tot)
        return 0;
    sort(ord, ord + tot);
    ll _min = INF; int cnt = 0;
    for (int i = 0; i < tot; i++)
        if (ord[i].second < _min)
            _min = ord[i].second, ord[cnt++] = ord[i];
    for (int i = 0; i < cnt; i++)
        v[o][i] = ord[i];
    return s[o] = cnt, 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		scanf("%d %d", fa + i, val + i);
		son[fa[i]][s[fa[i]]++] = i;
	}
    dfs_init(1);
    ll l = 0, r = INF;
    while (l <= r)
        mid = (l + r) >> 1, dfs(1) ? r = mid - 1 : l = mid + 1;
    printf("%lld", l);
	return 0;
}
