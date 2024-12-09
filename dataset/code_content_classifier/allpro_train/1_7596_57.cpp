#include <bits/stdc++.h>
using namespace std;
const int N = 3e2+5, oo = 0x3f3f3f3f;
int n, m, c[N], ans, d[N][N]; char s[N][N];
void dfs(int x, int w)
{
    c[x] = w;
    for(int y = 1; y <= n; ++y) if(s[x][y] == '1')
    {
        if(!c[y]) dfs(y, w^1);
        else if(c[y] != (w^1)) puts("-1"), exit(0);
    }
}
int main()
{
    scanf("%d", &n); for(int i = 1; i <= n; ++i) scanf("%s", s[i]+1);
    dfs(1, 2); for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) 
        if(i == j) d[i][j] = 0; else if(s[i][j] == '1') d[i][j] = 1; else d[i][j] = oo;
    for(int k = 1; k <= n; ++k) for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j)
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
    for(int i = 1; i <= n; ++i) ans = max(ans, *max_element(d[i]+1, d[i]+n+1));
    printf("%d\n", ans+1);
    return 0;
}