#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

typedef vector<int> Node;
typedef vector<Node> Graph;

const int INF = 1000000000;

int add(Graph& G, int u){
    int v = G.size();
    G[u].push_back(v);
    G.push_back(Node());
    G[v].push_back(u);
    return v;
}
void bellman_ford(const Graph& G, int s, int dist[1000]){
    dist[s] = 0;
    bool update = true;
    while(update){
        update = false;
        for(int i = 0; i < G.size(); i++){
            for(int j = 0; j < G[i].size(); j++){
                int k = G[i][j];
                if(dist[k] > dist[i] + 1){
                    dist[k] = dist[i] + 1;
                    update = true;
                }
            }
        }
    }
}

int main(){
    int N;
    while(cin >> N && N){
        int d[100][100] = {};
        int dist[100][1000] = {};
        REP(i, 100) fill(dist[i], dist[i] + 1000, INF);
        int start[100] = {};
        REP(i, N) REP(j, N) cin >> d[i][j];
        REP(i, N) REP(j, N) d[i][j] -= 2;

        Graph G;
        G.push_back(Node());
        start[0] = 0;
        dist[0][0] = 0;

        for(int i = 1; i < N; i++){
            vector<int> v;
            for(int j = 0; j < i; j++){
                v.push_back(d[i][j]);
            }

            int u = -1;
            int len = -1;
            for(int j = 0; j < G.size(); j++){
                set<int> s;
                for(int k = 0; k < v.size(); k++){
                    s.insert(v[k] - dist[k][j]);
                }
                if(s.size() == 1){
                    u = j;
                    len = *s.begin();
                }
            }

            assert(u != -1);
            assert(len >= 0);
            while(len--){
                u = add(G, u);
            }
            start[i] = u;
            //printf("start[%d] = %d\n", i, u);

            for(int j = 0; j <= i; j++){
                bellman_ford(G, start[j], dist[j]);
            }
        }
        vector<int> ans;
        for(int i = 0; i < G.size(); i++){
            ans.push_back(G[i].size());
        }
        for(int i = 0; i < N; i++){
            ans[ start[i] ]++;
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i];
            if(i == ans.size() - 1) cout << endl;
            else cout << " ";
        }
    }
    return 0;
}