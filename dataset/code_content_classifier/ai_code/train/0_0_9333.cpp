#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> parent(N+1);

    for(int i=1; i<N; i++) {
        int a, b;
        cin >> a >> b;
        parent[b] = a;
    }

    vector<pair<int, int>> edges;
    unordered_set<int> vertices;

    for(int i=0; i<M; i++) {
        int c, d;
        cin >> c >> d;
        edges.push_back({c, d});
        vertices.insert(c);
        vertices.insert(d);
    }

    int ans = M;
    
    for(auto edge : edges) {
        int a = edge.first;
        int b = edge.second;
        if(parent[a] == b) swap(a, b);
        if(parent[b] == a) continue;
        
        int c = parent[a];
        
        if(vertices.count(c)) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}