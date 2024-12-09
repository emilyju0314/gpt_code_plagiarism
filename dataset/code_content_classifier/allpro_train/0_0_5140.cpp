#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<char> ranks;
vector<bool> visited;

bool isValid(int u, int parent) {
    visited[u] = true;

    char maxRank = 'A';
    for(int v : adj[u]) {
        if(v == parent) continue;
        if(!visited[v]) {
            if(maxRank == 'Z') maxRank = 'Y';
            ranks[v] = maxRank--;
            if(!isValid(v, u)) return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    adj.resize(n);
    ranks.resize(n);
    visited.resize(n, false);

    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);        
    }

    ranks[0] = 'A';
    if(isValid(0, -1)) {
        for(char rank : ranks) {
            cout << rank << " ";
        }
        cout << endl;
    } else {
        cout << "Impossible!" << endl;
    }

    return 0;
}