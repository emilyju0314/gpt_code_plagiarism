#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

vector<vector<int>> adj;
vector<int> match_left, match_right, dist;

bool bfs() {
    queue<int> q;
    for (int left = 0; left < match_left.size(); left++) {
        if (match_left[left] == -1) {
            dist[left] = 0;
            q.push(left);
        } else {
            dist[left] = INF;
        }
    }
    
    dist[-1] = INF;
    
    while (!q.empty()) {
        int left = q.front();
        q.pop();
        
        if (dist[left] < dist[-1]) {
            for (int right : adj[left]) {
                if (dist[match_right[right]] == INF) {
                    dist[match_right[right]] = dist[left] + 1;
                    q.push(match_right[right]);
                }
            }
        }
    }
    
    return dist[-1] != INF;
}

bool dfs(int left) {
    if (left == -1) {
        return true;
    }
    
    for (int right : adj[left]) {
        if (dist[match_right[right]] == dist[left] + 1 && dfs(match_right[right])) {
            match_left[left] = right;
            match_right[right] = left;
            return true;
        }
    }
    
    dist[left] = INF;
    return false;
}

int hopcroft_karp() {
    int matching = 0;
    while (bfs()) {
        for (int left = 0; left < match_left.size(); left++) {
            if (match_left[left] == -1 && dfs(left)) {
                matching++;
            }
        }
    }
    
    return matching;
}

int main() {
    int n;
    cin >> n;
    
    match_left.resize(n);
    fill(match_left.begin(), match_left.end(), -1);
    
    match_right.resize(n);
    fill(match_right.begin(), match_right.end(), -1);
    
    dist.resize(n);
    
    adj.resize(n);
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    cout << hopcroft_karp() << endl;
    
    for (int i = 0; i < n; i++) {
        if (match_left[i] != -1) {
            cout << i + 1 << " " << match_left[i] + 1 << " " << match_right[match_left[i]] + 1 << " " << match_left[match_right[match_left[i]]] + 1 << endl; 
        }
    }
    
    return 0;
}