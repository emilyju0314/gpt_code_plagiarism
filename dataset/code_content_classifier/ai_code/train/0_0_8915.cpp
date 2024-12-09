#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
bool visited[MAXN];

void bfs(int start, int end, vector<int>& dist) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int N, M, S, T;
    cin >> N >> M >> S >> T;
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> dist_from_S(N+1, -1);
    vector<int> dist_from_T(N+1, -1);
    
    bfs(S, T, dist_from_S);
    bfs(T, S, dist_from_T);
    
    if (dist_from_S[T] == -1) {
        cout << "-1" << endl;
        return 0;
    }
    
    int min_dist = dist_from_S[T];
    
    if (isPrime(min_dist)) {
        cout << min_dist << endl;
    } else {
        cout << "-1" << endl;
    }
    
    return 0;
}