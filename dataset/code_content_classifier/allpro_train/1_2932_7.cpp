#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;

struct UF{
    int N;
    vector<int> par, siz;
    void init(int _n){
        N = _n;
        par.resize(N);
        siz.resize(N,1);
        for(int i=0;i<N;i++){
            par[i] = i;
        }
    }
    int root(int x){
        if(x == par[x]) return x;
        else return par[x] = root(par[x]);
    }
    void unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(siz[x] < siz[y]) swap(x,y);
        siz[x] += siz[y];
        par[y] = par[x];
    }
    bool same(int x, int y){
        return root(x)==root(y);
    }
    int size(int x){
        return siz[root(x)];
    }
};

int n, m;
vector<vector<int> > g, cnt;
vector<int> deg;
vector<bool> visited;
vector<P> ans;

void flip(int x, int y){
    cnt[x][y] ^= 1;
    cnt[y][x] ^= 1;
}

bool dfs(int now){
    if((deg[now]&1)==0) return true;
    visited[now] = true;
    for(int i=0;i<n;i++){
        if(!visited[i] && g[now][i] == 0){
            flip(now,i);
            deg[now] += (cnt[now][i]?1:-1);
            deg[i] += (cnt[now][i]?1:-1);
            if(dfs(i)) return true;
            flip(now,i);
            deg[now] += (cnt[now][i]?1:-1);
            deg[i] += (cnt[now][i]?1:-1);
        }
    }
    return false;
}

bool solve(){
    if(n & 1){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(g[i][j] == 0){
                    ans.push_back(P(i+1,j+1));
                }
            }
        }
        return true;
    }
    cnt.resize(n,vector<int>(n,0));
    visited.resize(n);
    for(int i=0;i<n;i++){
        if(deg[i]&1){
            fill(visited.begin(), visited.end(), false);
            if(!dfs(i)) return false;
        }
    }
    UF uf;
    uf.init(n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(g[i][j] || cnt[i][j]){
                uf.unite(i,j);
            }
        }
    }
    vector<int> iso;
    for(int i=0;i<n;i++){
        if(deg[i]==0) iso.push_back(i);
    }
    if(iso.size()==2){
        int x=-1, y=-1;
        for(int i=0;i<n;i++){
            if(deg[i] != 0){
                if(x < 0) x = i;
                else{
                    y = i;
                    break;
                }
            }
        }
        flip(x,iso[0]);
        flip(iso[0],iso[1]);
        flip(y,iso[1]);
        uf.unite(x,iso[0]);
        uf.unite(iso[0],iso[1]);
        uf.unite(iso[1],y);
    }
    else if(iso.size()>2){
        int k = iso.size();
        for(int i=0;i<k;i++){
            flip(iso[i],iso[(i+1)%k]);
            uf.unite(iso[i],iso[(i+1)%k]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(uf.same(i,j)) continue;
            if(uf.size(i)>=2 && uf.size(j)>=2){
                int x, y;
                for(int k=0;k<n;k++){
                    if(i!=k && uf.same(i,k)){
                        x = k;
                        break;
                    }
                }
                for(int k=0;k<n;k++){
                    if(j!=k && uf.same(j,k)){
                        y = k;
                        break;
                    }
                }
                flip(i,j);
                flip(i,y);
                flip(x,j);
                flip(x,y);
                uf.unite(i,j);
            }
            else if(uf.size(i)>=2 || uf.size(j)>=2){
                int x, y;
                if(uf.size(i)>=2){
                    x = i; y = j;
                } else{
                    x = j; y = i;
                }
                bool flag = false;
                for(int s=0;s<n;s++){
                    if(!uf.same(i,s)) continue;
                    for(int t=s+1;t<n;t++){
                        if(uf.same(i,t) && g[s][t]==0){
                            flip(j,s);
                            flip(j,t);
                            flip(s,t);
                            flag = true;
                            break;
                        }
                    }
                    if(flag) break;
                }
                if(!flag) return false;
                uf.unite(i,j);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(cnt[i][j]){
                ans.push_back(P(i+1,j+1));
            }
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    g.resize(n, vector<int>(n,0));
    deg.resize(n);
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a][b] = 1;
        g[b][a] = 1;
        deg[a]++;
        deg[b]++;
    }
    if(solve()){
        cout << ans.size() << endl;
        for(auto &e : ans){
            cout << e.first << " " << e.second << " \n";
        }
    }
    else{
        cout << "-1\n";
    }
    return 0;
}

