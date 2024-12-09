#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

bool isConsistent(int N, vector<pair<int, int, int>>& info) {
    vector<vector<pair<int, int>>> adj(N+1);
    for(const auto& i:info){
        adj[i.first].push_back({i.second, i.third});
        adj[i.second].push_back({i.first, -i.third});
    }
    vector<bool> visited(N+1, false);
    vector<int> x(N+1, 0);
    for(int node=1;node<=N;node++){
        if(visited[node]){
            continue;
        }
        visited[node] = true;
        x[node] = 0;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(const auto& neighbor:adj[curr]){
                int next = neighbor.first;
                int diff = neighbor.second;
                if(!visited[next]){
                    visited[next] = true;
                    x[next] = x[curr]+diff;
                    q.push(next);
                } else if(x[next]!=x[curr]+diff){
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int, int>> info(M);
    for(int i=0;i<M;i++){
        int L, R, D;
        cin >> L >> R >> D;
        info[i] = {L, R, D};
    }

    if (isConsistent(N, info)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}