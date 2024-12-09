#include <cstdio>
#include <vector>

#define MAXN 100009

int ans;
bool viz[MAXN];
std::vector < int > g[MAXN];

bool dfs(int x) {
    viz[x] = 1;
    int cnt = 0;
    bool r = 0;
    for (auto &y : g[x]) {
        if (viz[y] == 0) {
            bool f = dfs(y);
            cnt += 1 - f;
            r |= f;
        }
    }
    if (cnt > 1)
        ans += cnt - 1, r = 1;
    return r;
}

int main() {
    int n;
    scanf("%d", &n);

    int rad = 0;
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x++;
        y++;

        g[x].push_back(y);
        g[y].push_back(x);

        if (g[x].size() > 2)
            rad = x;
        if (g[y].size() > 2)
            rad = y;
    }

    if (rad)
        bool r = dfs(rad);
    else ans = 1;

    printf("%d\n", ans);

    return 0;
}
