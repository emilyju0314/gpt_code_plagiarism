#include <iostream>
#include <vector>
using namespace std;
long long const mod = 1000000007;

long long mod_pow(long long a, long long b){
    long long res = 1;
    a %= mod;
    while(b > 0){
        if(b%2 == 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

long long mod_div(long long a){
    return mod_pow(a, mod-2);
}

vector< vector<int> > edg;
vector<int> cc, par;

int f(int v, int p){
    int res = 1;
    par[v] = p;
    for(int i=0;i<edg[v].size();i++){
        int w = edg[v][i];
        if(w == p) continue;
        res += f(w, v);
    }
    return cc[v] = res;
}

int main(void){
    int n;
    long long ans = 0;
    cin >> n;
    edg.assign(n, vector<int>());
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }

    cc.assign(n, -1);
    par.assign(n, -1);
    f(0, -1);
    long long r2 = mod_div(2), pn = mod_pow(r2, n);
    for(int i=0;i<n;i++){
        long long res = r2 + mod - pn;
        if(edg[i].size() == 1) continue;
        if(i > 0){
            long long t = n-cc[i];
            res += mod - mod_pow(r2, n-t) + pn;
        }
        for(int j=0;j<edg[i].size();j++){
            if(edg[i][j] == par[i]) continue;
            long long t = cc[edg[i][j]];
            res += mod - mod_pow(r2, n-t) + pn;
        }
        ans += res % mod;
        ans %= mod;
    }
    cout << ans << endl;
}
