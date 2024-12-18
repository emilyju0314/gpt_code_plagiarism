#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

struct SCC{
    int V;
    vector<vector<int>> G, rG;
    vector<int> vs; // ??°?????????????????????
    vector<int> cmp; //?±????????????£?????????????????????????????????
    vector<bool> used;

    SCC(){}
    SCC(int n){
        V = n;
        G = vector<vector<int>>(n);
        rG = vector<vector<int>>(n);
    }

    void add_edge(int from, int to){
        G[from].push_back(to);
        rG[to].push_back(from);
    }

    void dfs(int v){
        used[v] = true;
        rep(i,G[v].size())if(!used[G[v][i]]) dfs(G[v][i]);
        vs.push_back(v);
    }

    void rdfs(int v, int k){
        used[v]=true;
        cmp[v]=k;
        rep(i,rG[v].size())if(!used[rG[v][i]]) rdfs(rG[v][i],k);
    }

    int scc(){
        used = vector<bool>(V,false);
        vs.clear();
        rep(i,V)if(!used[i]) dfs(i);

        used = vector<bool>(V,false);
        cmp = vector<int>(V);
        int num_scc = 0;
        for(int i=vs.size()-1; i>=0; --i)if(!used[vs[i]]) rdfs(vs[i],num_scc++);
        return num_scc;
    }
};

struct TwoSat{
    int v;
    SCC graph;

    // v literals
    // 0~v-1: true
    // v~2v-1: false

    TwoSat(int num_literal){
        v = num_literal;
        graph = SCC(2*v);
    }

    inline int num(int id, bool b){return id+(b?0:v);}

    void add_clause(int x, bool X, int y, bool Y){
        graph.add_edge(num(x,!X), num(y,Y));
        graph.add_edge(num(y,!Y), num(x,X));
    }

    // ?????????????????????????????????
    bool calc(){
        graph.scc();
        rep(i,v)if(graph.cmp[i]==graph.cmp[v+i]) return false;
        return true;
    }

    // ?????????????????????????????????
    vector<bool> get_literals(){
        assert(calc());
        vector<bool> res(v);
        rep(i,v) res[i] = (graph.cmp[i]>graph.cmp[v+i]);
        return res;
    }
};

using pi = pair<int,int>;
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

int main()
{
    int n;
    while(cin >>n,n)
    {
        vector<vector<pi>> v(n);
        map<pi,pi> m;
        rep(i,n)
        {
            int x,y;
            char d;
            cin >>x >>y >>d;

            v[i].pb({x,y});
            if(d=='x') v[i].pb({x+1,y});
            else v[i].pb({x,y+1});

            rep(j,2) m[v[i][j]] = {i,j};
        }

        TwoSat solver(n);
        rep(i,n)rep(j,2)rep(k,4)
        {
            int nx = v[i][j].fi+dx[k];
            int ny = v[i][j].se+dy[k];
            if(m.count({nx,ny}))
            {
                pi p = m[{nx,ny}];
                int id = p.fi;
                int b = p.se;
                if(id == i) continue;

                solver.add_clause(i,j,id,!b);
            }
        }

        cout << (solver.calc()?"Yes":"No") << endl;
    }
    return 0;
}