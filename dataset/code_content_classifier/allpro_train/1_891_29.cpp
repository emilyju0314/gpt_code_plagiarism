#include<bits/stdc++.h>
#define PB emplace_back
using namespace std;
typedef long long LL;
const int N = 1503, mod = 1004535809;
template<typename T>
void read(T &x){
    int ch = getchar(); x = 0;
    for(;ch < '0' || ch > '9';ch = getchar());
    for(;ch >= '0' && ch <= '9';ch = getchar()) x = x * 10 + ch - '0';
}
int n, m, a[N][N], b[N][N], d[N], va[N], vb[N];
bool vis[N], viz[N]; vector<int> ans;
int main(){
    read(n); read(m);
    for(int i = 1;i <= n;++ i)
        for(int j = 1;j <= m;++ j){
            read(a[i][j]);
            va[i] = ((LL)va[i] * N + a[i][j]) % mod;
        }
    for(int i = 1;i <= n;++ i){
        for(int j = 1;j <= m;++ j){
            read(b[i][j]);
            vb[i] = ((LL)vb[i] * N + b[i][j]) % mod;
        }
        for(int j = 1;j <= n;++ j)
            if(!vis[j] && vb[i] == va[j]){
                vis[j] = true; b[i][0] = j; break;
            }
        if(!b[i][0]){puts("-1"); return 0;}
    }
    for(int i = 0;i <= m;++ i)
        for(int j = 1;j < n;++ j)
            d[i] += b[j][i] > b[j+1][i];
    memset(vis, 0, sizeof vis);
    while(true){
        int pos = -1;
        for(int i = 0;i <= m;++ i)
            if(!vis[i] && !d[i]){pos = i; break;}
        if(!~pos){puts("-1"); return 0;}
        vis[pos] = true;
        if(!pos){
            printf("%lu\n", ans.size());
            for(int i = (int)ans.size()-1;~i;-- i)
                printf("%d ", ans[i]);
            putchar('\n'); return 0;
        } ans.PB(pos);
        for(int i = 1;i < n;++ i)
            if(!viz[i] && b[i][pos] < b[i+1][pos]){
                viz[i] = true;
                for(int j = 0;j <= m;++ j)
                    d[j] -= b[i][j] > b[i+1][j];
            }
    }
}