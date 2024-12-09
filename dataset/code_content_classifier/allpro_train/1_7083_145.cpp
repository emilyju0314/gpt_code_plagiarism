#include <algorithm>
#include <cstdio>
#include <vector>

const int N = 100000;

int n, m, a[N], result;
std::vector<int> children[N];

int dfs(int u)
{
    int dep = 0;
    for (auto v : children[u]) {
        auto ret = dfs(v);
        if (u && ret == m - 1) {
            result ++;
        } else {
            dep = std::max(dep, ret + 1);
        }
    }
    return dep;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
        if (i) {
            children[-- a[i]].push_back(i);
        }
    }
    result = a[0] != 1;
    dfs(0);
    printf("%d\n", result);
}
